import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import com.examples.camera 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QCamera Demo")

    header: Rectangle{
        id: headerRect;
        width: parent.width;
        height: 50;
        color: "steelblue";

        Row{
            anchors.centerIn: parent;
            anchors.margins: 10;
            spacing: 10;

            Button{
                id: startButton;
                text: qsTr("Start");
                onClicked: {
                    cameraItem.visible=true;
                    cameraHandler.slotStart();
                }
            }
            Button{
                id: stopButton;
                text: qsTr("Stop");
                onClicked: {
                    cameraItem.visible=false;
                    cameraHandler.slotStop();
                }
            }
            Button{
                id: quitButton;
                text: qsTr("Quit");
                onClicked: {
                    Qt.quit();
                }
            }
        }
    }
    CameraItem{
        id: cameraItem;
        anchors.fill: parent;
        anchors.margins: 10;
    }
    Connections{
        target: cameraHandler;
        onSignalImageCaptured: {
            cameraItem.image=image;
        }
    }
}
