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

using namespace std;

namespace Ui {
class admin1;
}

class admin1 : public QDialog
{
    Q_OBJECT

public:
    TiXmlDocument doc;
    bool hacerPunto;
    explicit admin1(QWidget *parent = 0);
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

    void dibujarPunto(int x, int y);

    bool checkPunto(int x1, int y1);

    int x,y;
    void paintEvent(QPaintEvent *);

    Ui::admin1 *ui;
};

#endif // ADMIN1_H
