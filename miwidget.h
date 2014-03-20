#ifndef MIWIDGET_H
#define MIWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QtCore>
#include "grafo.h"
#include "TinyXml/tinyxml.h"

class miWidget : public QWidget
{
    Q_OBJECT
public:
    TiXmlDocument doc;
    TiXmlDocument doc2;
    Grafo miGrafo;
    explicit miWidget(QWidget *parent = 0);

signals:

public slots:
      void leerXml();
      void leerXml2();
      void paintEvent(QPaintEvent *);

};

#endif // MIWIDGET_H
