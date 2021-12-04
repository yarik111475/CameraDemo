#include "imageitem.h"

ImageItem::ImageItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

void ImageItem::paint(QPainter *painter)
{
    if(!m_image.isNull()){
        QImage scaledImage=m_image.scaled(width(), height(), Qt::KeepAspectRatio);
        painter->drawPixmap((width()-scaledImage.width())/2,
                            (height()-scaledImage.height())/2,
                            scaledImage.width(), scaledImage.height(),
                            QPixmap::fromImage(m_image));
    }
}

void ImageItem::setImage(const QImage &image)
{
    m_image=image;
    update();
}

QImage ImageItem::getImage() const
{
    return m_image;
}
