#ifndef DRAWBOX_H
#define DRAWBOX_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>


class DrawBox : public QWidget
{
    Q_OBJECT


private:
    bool m_disegnaCirconferenza;
    bool drawingEdgedPolygon;
    bool drawingSinglePoint;
    bool mousePressed;
    bool initialized;
    unsigned int grabbed;
    QPalette pal;
    QColor color;
    QPointF circleCenter;
    double circleRadius;
    QPolygonF edgedPolygon;
    QPoint singlePoint;


public:
    explicit DrawBox(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* PaintEvent);

signals:
    void sendRadius(double);
    void sendPolygonPoint(QPointF,uint);

public slots:
    void disegnaCirconferenza(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void updateDrawingColor(QString s);
    void drawPoint(QPoint);

};

#endif // DRAWBOX_H
