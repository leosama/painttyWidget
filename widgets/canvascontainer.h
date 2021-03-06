#ifndef CANVASCONTAINER_H
#define CANVASCONTAINER_H

#include <QGraphicsView>

class QGraphicsScene;
class QGraphicsProxyWidget;

const qreal MAX_SCALE_FACTOR = 5.0;
const qreal MIN_SCALE_FACTOR = 0.125;

class CanvasContainer : public QGraphicsView
{
    Q_OBJECT
public:
    CanvasContainer(QWidget *parent = 0);
    void setCanvas(QWidget *canvas);
    qreal currentScaleFactor() const;
    bool smoothScale() const;
    QRectF visualRect() const;
    QWidget* scaleSlider();
    void centerOn(const QPointF &pos);
    void centerOn(qreal x, qreal y);
    
signals:
    void scaled(qreal factor);
    void rectChanged(const QRect&);

public slots:
    void setScaleFactor(qreal factor);
    void setSmoothScale(bool smooth);

private:
    QGraphicsScene *scene;
    QGraphicsProxyWidget *proxy;
    QWidget *scaleSliderWidget;
    QPoint moveStartPoint;
    int horizontalScrollValue;
    int verticalScrollValue;
    bool smoothScaleFlag;
    qreal calculateFactor(qreal current, bool zoomIn);

protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // CANVASCONTAINER_H
