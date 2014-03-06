#include "miwidget.h"
#include <QStyleOption>


miWidget::miWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setStyleSheet( "border-radius: 5px; "
                         "border: 1px solid black;"
                         "border: 2px groove gray;"
                         "image: url(://imagenes/mapa2.png)");
}

void miWidget::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(2.5);
    pen.setBrush(Qt::black);

    painter.setPen(pen);
    painter.drawLine(811-15, 453-125, 182-20, 324-125);
    painter.drawLine(204-15,287-125 ,677 -20,182-125);
    painter.drawLine(182-15,327-125 ,712 -20,262-125);
    painter.drawLine(411-15,271-125 ,677 -20,183-125);
    painter.drawLine(811-15,453-125 ,411 -20,271-125);
}
