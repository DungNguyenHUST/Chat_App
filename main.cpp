#include <QDBusMessage>
#include <QDBusConnection>
#include <QtDBus>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QDebug>

#include "main.h"

ChatEngine::ChatEngine(QObject *parent, QString username, char* instant) :
    QObject(parent), _iface(SERVICE_NAME  + QString(instant), "/", "", QDBusConnection::sessionBus())
{
    _instant = instant;
    qDebug() << "Current instant: " << _instant;
    _username = username;

    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("test.sql");
    _db.open();

    _query = QSqlQuery(_db);

    _query.exec("create table if not exists tblMessage\
                (   id integer primary key,\
                    username varchar(50), \
                    message varchar(255), \
                    time timestamp\
                )\
                " );
}

ChatEngine::~ChatEngine(){
    _db.close();
}

void ChatEngine::loadStoredMessage(QString username)
{
    _query = QSqlQuery("SELECT * FROM tblMessage");
    while(_query.next()){
        sendToQml(_query.value(1).toString(), _query.value(2).toString(), _query.value(3).toString(), (username == _query.value(1).toString())?1:0);
    }
}

void ChatEngine::receiveFromQml(QString message)
{
    messageSend(_username, message);
    // qDebug() << messageLoad().message;
}

void ChatEngine::messageSend(QString username, QString message)
{
    // qDebug() << "Received from QML: " << message;
    if (_iface.isValid()) {
        QDBusReply<QString> reply = _iface.call("messageSend", username, message);
        if (reply.isValid()) {
            qDebug("Reply was: %s\n", qPrintable(reply.value()));
        }
    }
    else
    {
        fprintf(stderr, "%s\n", qPrintable(QDBusConnection::sessionBus().lastError().message()));
    }
}

void ChatEngine::messageStore(QString username, QString message, QDateTime time)
{
    _query.prepare("INSERT INTO tblMessage(username, message, time) \
                    values(:username,:message,:time)");

    _query.bindValue(":username", username);
    _query.bindValue(":message", message);
    _query.bindValue(":time", time);

    _query.exec();
}

// Post message received from DBus to view and store it
void ChatEngine::postMessage(QString username, QString message)
{
    _nowTime = QDateTime::currentDateTime();
    sendToQml(username, message, _nowTime.toString(), 0);
    messageStore(_username, message, _nowTime);
}

Receiver::Receiver(ChatEngine *chatEngine)
{
    // (void)chatEngine;
    _chatEngine = chatEngine;
}
// Supply messageSend so that other instant can call
QString Receiver::messageSend(const QString &arg1, const QString &arg2)
{
    _chatEngine->postMessage(arg1, arg2);
    return "received";
}

int main(int argc, char *argv[])
{
    char* instant;
    QString username = "";
    QGuiApplication app(argc, argv);

    // Check DBus connection
    if (!QDBusConnection::sessionBus().isConnected()) {
        qWarning("Cannot connect to the D-Bus session bus.\n");
        return 1;
    }

    // Check SQL driver
    if (QSqlDatabase::drivers().isEmpty()){
        qWarning("No database drivers found");
        return 1;
    }

    if(argc != 4){
        qWarning("Invalid input parameters, run with ./Qt_chat [USERNAME] [INSTANT?1:2] [LANGUAGE?e:v]");
        return 1;
    }
    else{
        username = argv[1];
        instant = argv[2];
    }

    // Implement chatWindows
    QQmlApplicationEngine chatWindow;

    ChatEngine chatEngine(0, username, instant);
    Receiver receiver(&chatEngine);
    QTranslator translator;

    if (QString(argv[3]) == "v")
    {
        translator.load("Qt_chat_tr");
        app.installTranslator(&translator);
    }

    QQmlContext* context = chatWindow.rootContext();
    context->setContextProperty("chatEngine", &chatEngine);
    chatWindow.load(QUrl(QStringLiteral("qrc:///main.qml")));
    chatEngine.loadStoredMessage(username);

    if (!QDBusConnection::sessionBus().registerService(SERVICE_NAME  + QString(QString(instant)=="1"?"2":"1"))) {
        qDebug() << QDBusConnection::sessionBus().lastError().message();
        exit(1);
    }

    QDBusConnection::sessionBus().registerObject("/", &receiver, QDBusConnection::ExportAllSlots);

    return app.exec();
}
