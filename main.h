#ifndef MAIN_H
#define MAIN_H
#include <QtDBus>
#include <QObject>
#include <QtSql>
#include <QDateTime>
#include <QTranslator>

#define SERVICE_NAME    "lge.example.QtDBus.ChatExample"

class ChatEngine : public QObject
{
    Q_OBJECT
public:
    explicit ChatEngine(QObject *parent, QString username, char* instant);
    virtual ~ChatEngine();

    // this method load stored messages from database and puts into view
    // only call this method when view is ready
    void loadStoredMessage(QString username);
    QString messageReceive(QString username, QString message);
    void postMessage(QString username, QString message);

private:
    QString _instant;
    QDBusInterface _iface;
    QString _username;
    QSqlDatabase _db;
    QSqlQuery _query;
    QDateTime _nowTime;

    void messageSend(QString username, QString message);
    void messageStore(QString username, QString message, QDateTime time);

signals:
    void sendToQml(QString username, QString message, QString time, bool isUser);
public slots:
    void receiveFromQml(QString message);
};

class Receiver: public QObject
{
    Q_OBJECT
public:
    explicit Receiver(ChatEngine *chatEngine);
private:
    ChatEngine *_chatEngine;

public slots:
    Q_SCRIPTABLE QString messageSend(const QString &arg1, const QString &arg2);
};

#endif /* MAIN_H */
