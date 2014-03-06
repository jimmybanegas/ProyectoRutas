#ifndef MIWIDGET_H
#define MIWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QtCore>

class miWidget : public QWidget
{
    Q_OBJECT
public:
    explicit miWidget(QWidget *parent = 0);

signals:

public slots:
      void paintEvent(QPaintEvent *);

};

#endif // MIWIDGET_H
