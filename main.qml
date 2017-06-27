/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtMultimedia 5.5

Window {
    width: 640
    height: 480
    id: window
    visible: true

    Connections 
    {
        target: chatEngine
        onSendToQml: {
            mediaplayer.play();
            messageModel.append({
                message: message,
                type: isUser?"user":"guest",
            });
        }
    }
    // Title
    Rectangle {
        id: rectTitle
        anchors.top: parent.top
        width: parent.width
        height: 40
        color: "blue"
        Text{
            id: txtTitle
            anchors.centerIn: parent
            font.pointSize: 15
            text: qsTr("Qt chat example")
            color: "white"
        }
    }

    // Listview
    Rectangle {
        id: rectMessageBox
        anchors.top: rectTitle.bottom
        width: parent.width
        height : parent.height - 120
        color: "#eeeeee"
        ListModel{
            id: messageModel
            ListElement {
                message: qsTr("Press Enter to send message")
                type: "user"
            }
        }

        Component{
            id: messageDelegate
            Row{
                spacing: 10
                Text {
                    text: message
                    wrapMode: Text.WordWrap
                    width: parent.width - 10
                    horizontalAlignment: type==="user"?Text.AlignLeft:Text.AlignRight
                }
                width: parent.width
            }
        }

        ListView{
            anchors.fill: parent
            model: messageModel
            delegate: messageDelegate
        }
    }

    // About view
    Rectangle {
        id: rectAboutBox
        anchors.top: rectTitle.bottom
        width: parent.width
        height: parent.height - 120
        color: "#eeeeee"
        visible: false
        Text{
            y: 20
            anchors.horizontalCenter: parent.horizontalCenter;
            font.pointSize: 15
            text: qsTr("LG Number One!")
            anchors.horizontalCenterOffset: 0
            color: "black"
        }
        Text{
            y: 60
            anchors.horizontalCenter: parent.horizontalCenter;
            font.pointSize: 15
            text: qsTr("IVI Vietnam Development Center")
            anchors.horizontalCenterOffset: 1
            color: "black"
        }
        Text{
            y: 100
            anchors.horizontalCenter: parent.horizontalCenter;
            font.pointSize: 10
            text: qsTr("This application is used for training purpose")
            anchors.horizontalCenterOffset: 1
            color: "black"
        }
    }

    TextInput {
        id: txtMessage
        width: parent.width
        height: 40
        anchors.top: rectMessageBox.bottom
        color: "#333333"
        font.pixelSize: 14
        Keys.onReturnPressed: {
            if(this.text != "")
            {
                chatEngine.receiveFromQml(this.text);
                messageModel.append({
                    message: this.text,
                    type: "user"
                });
                this.text = "";
            }
        }
        Keys.onPressed: {
            // console.log(event.key);
        }
    }

    Rectangle {
        id: rectBottomBox
        anchors.top: txtMessage.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        color: "light blue"

        Item {
            id: item1
            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 40

            Button {
                id: button1
                x: 20
                y: 5
                height:30
                text: qsTr("Chat")
                onClicked:{
                    rectAboutBox.visible = false
                    txtTitle.text = qsTr("Qt chat example")
                }
            }

            Button {
                id: button2
                x: 100
                y: 5
                height:30
                onClicked:{
                    txtTitle.text = qsTr("About")
                    rectAboutBox.visible = true
                }
                text: qsTr("About")
            }
        }
    }
    Audio {
            id: mediaplayer
            source: "file:/home/sonnd/dev/Qt_chat/ping.mp3"
        }

}
