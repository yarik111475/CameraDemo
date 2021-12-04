#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QtCore>
#include <QObject>
#include <QImage>
#include <QPainter>
#include <QQuickPaintedItem>

class ImageItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image
               READ(getImage)
               WRITE(setImage))
private:
    QImage m_image;
public:
    explicit ImageItem(QQuickItem *parent = nullptr);
    virtual void paint(QPainter *painter);
    void setImage(const QImage& image);
    QImage getImage()const;

signals:
};

#endif // IMAGEITEM_H
