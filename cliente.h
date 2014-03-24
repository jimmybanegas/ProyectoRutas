#ifndef CLIENTE_H
#define CLIENTE_H

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
class cliente;
}

class cliente : public QDialog
{
    Q_OBJECT

public:
    TiXmlDocument doc;
    TiXmlDocument doc2;
    Grafo miGrafo;
    miWidget *a ;

    explicit cliente(QWidget *parent = 0);
    void setGrafo(Grafo miGrafo);
    ~cliente();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

private:
    void leerXml();
    void leerXml2();
    void dibujarPunto(int x, int y);

    Ui::cliente *ui;
};

#endif // CLIENTE_H
