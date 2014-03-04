#ifndef ADMIN1_H
#define ADMIN1_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <iostream>
#include "qpainter.h"
#include <QtXml>
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
    void on_admin1_accepted();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QMouseEvent *ev);

    void escribirXml(int x, int y, QString codigo, QString ciudad);
    void leerXml();

    bool checkPunto(int x, int y);

    int x,y;

    Ui::admin1 *ui;
};

#endif // ADMIN1_H
