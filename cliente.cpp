#include "cliente.h"
#include "ui_cliente.h"

cliente::cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cliente)
{
    ui->setupUi(this);

    this->a = new miWidget(this);
    a->setGeometry(20,130,900,431);
    a->show();

    doc=TiXmlDocument("Aeropuertos.xml");
    doc2=TiXmlDocument("Conexiones.xml");

    leerXml();
    leerXml2();

    cout<<this->miGrafo.p->ciudad.toStdString();

    miGrafo.mostrar_grafo();

    miGrafo.llenarMatriz();
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

        miGrafo.insertar_aeropuerto(codigo,ciudad,x,y);

        patr=patr->NextSibling();

    }
}

void cliente::leerXml2()
{
   doc2.LoadFile();
   TiXmlNode *patr=doc2.FirstChild();

    while(patr){
        QString inicio = QString::fromUtf8(patr->ToElement()->Attribute("Inicio"));
        QString destino = QString::fromUtf8(patr->ToElement()->Attribute("Destino"));
        double costo = atof(patr->ToElement()->Attribute("Costo"));

        //Cargar al grafo los aeropuertos existentes
        miGrafo.insertar_conexion(inicio,destino,costo);

        patr=patr->NextSibling();
    }
}

void cliente::setGrafo(Grafo miGrafo)
{
    this->miGrafo = miGrafo;
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


void cliente::on_pushButton_clicked()
{

}

void cliente::on_comboBox_activated(int index)
{

}
