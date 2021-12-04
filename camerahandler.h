#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include <QtCore>
#include <QObject>
#include <QtMultimedia>

class CameraHandler : public QObject
{
    Q_OBJECT

private:
    const int INTERVAL=30;
    QTimer* m_pTimer;
    QCamera* m_pCamera;
    QCameraImageCapture* m_pCapture;

public:
    explicit CameraHandler(QObject *parent = nullptr);
private slots:
    void slotTimeOut();

public slots:
    void slotStart();
    void slotStop();

signals:
    void signalImageCaptured(int id, const QImage& image);

};

#endif // CAMERAHANDLER_H
