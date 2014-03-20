#ifndef ADMIN1_H
#define ADMIN1_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <iostream>
#include <QPainter>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include "TinyXml/tinyxml.h"
#include "miwidget.h"
#include "grafo.h"

using namespace std;

namespace Ui {
class admin1;
}

class admin1 : public QDialog
{
    Q_OBJECT

public:
    TiXmlDocument doc;
    TiXmlDocument doc2;
    Grafo *miGrafo;
    bool hacerPunto;
    miWidget *a ;

    explicit admin1(QWidget *parent = 0);
    void setGrafo(Grafo *miGrafo);
    ~admin1();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    void mousePressEvent(QMouseEvent *ev);

    void escribirXml(int x, int y, QString codigo, QString ciudad);
    void leerXml();

    void escribirXml2(QString ini, QString fin, double costo);
    void leerXml2();

    void dibujarPunto(int x, int y);

    bool checkPunto(int x1, int y1);

    int x,y;

    Ui::admin1 *ui;
};

#endif // ADMIN1_H
