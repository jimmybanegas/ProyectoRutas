#include "cliente.h"
#include "ui_cliente.h"

cliente::cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cliente)
{
    ui->setupUi(this);
    doc=TiXmlDocument("Aeropuertos.xml");
    leerXml();

}

cliente::~cliente()
{
    delete ui;
}

void cliente::leerXml()
{
   doc.LoadFile();
   TiXmlNode *patr=doc.FirstChild();

    while(patr){
        QString codigo = QString::fromUtf8(patr->ToElement()->Attribute("Codigo"));
        QString ciudad = QString::fromUtf8(patr->ToElement()->Attribute("Ciudad"));
        int x = atoi(patr->ToElement()->Attribute("x"));
        int y =  atoi(patr->ToElement()->Attribute("y"));

        dibujarPunto(x ,y);

        ui->comboBox->addItem(ciudad);
        ui->comboBox_2->addItem(ciudad);

        patr=patr->NextSibling();

    }
}

void cliente::dibujarPunto(int x, int y)
{
    QPixmap punto=QPixmap(":/imagenes/punto.png");
    QLabel *imagen=new QLabel(this) ;
    imagen->setPixmap(punto);
    imagen->setScaledContents(true);
    imagen->setGeometry(x,y,10,10);
    imagen->raise();
    imagen->show();
}
