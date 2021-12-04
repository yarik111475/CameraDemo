#include "camerahandler.h"

CameraHandler::CameraHandler(QObject *parent)
    : QObject(parent), m_pTimer{nullptr},
      m_pCamera{nullptr}, m_pCapture{nullptr}
{
    m_pTimer=new QTimer(this);
    m_pTimer->setInterval(INTERVAL);
    QObject::connect(m_pTimer, SIGNAL(timeout()),
                     this, SLOT(slotTimeOut()));

    m_pCamera=new QCamera(QCamera::UnspecifiedPosition, this);
    m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
    m_pCapture=new QCameraImageCapture(m_pCamera);   
    m_pCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);
    QObject::connect(m_pCapture, SIGNAL(imageCaptured(int,QImage)),
                     this, SIGNAL(signalImageCaptured(int,QImage)));
}

void CameraHandler::slotTimeOut()
{
    if(m_pCapture->isReadyForCapture()){
        m_pCapture->capture();
        qDebug()<<"image captured in c++ code";
    }
}

void CameraHandler::slotStart()
{
    if(m_pCamera->isAvailable()){
        m_pTimer->start();
        m_pCamera->searchAndLock();
        m_pCamera->start();
    }
}

void CameraHandler::slotStop()
{
    m_pTimer->stop();
    m_pCamera->unlock();
    m_pCamera->stop();
}
