#ifndef CLIENTE_H
#define CLIENTE_H

#include <QDialog>
#include "TinyXml/tinyxml.h"

namespace Ui {
class cliente;
}

class cliente : public QDialog
{
    Q_OBJECT

public:
    TiXmlDocument doc;
    explicit cliente(QWidget *parent = 0);
    ~cliente();

private:
    void leerXml();
    void dibujarPunto(int x, int y);
    Ui::cliente *ui;
};

#endif // CLIENTE_H
