#include "miwidget.h"
#include <QStyleOption>


miWidget::miWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setStyleSheet( "border-radius: 5px; "
                         "border: 1px solid black;"
                         "border: 2px groove gray;"
                         "image: url(://imagenes/mapa2.png)");

    doc=TiXmlDocument("Aeropuertos.xml");
    doc2=TiXmlDocument("Conexiones.xml");

    leerXml();
    leerXml2();
}

void miWidget::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p1(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p1, this);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(2.5);
    pen.setBrush(Qt::black);

    painter.setPen(pen);

    Aeropuerto *ptr;
    Conexion *ar;
    ptr=miGrafo.p;

    while(ptr!=NULL)
    {
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;

            while(ar!=NULL)
            {
                painter.drawLine(ptr->x-15,ptr->y-125 ,ar->destino->x-20,ar->destino->y-125);
                ar=ar->sgte;

            }

        }
        ptr=ptr->sgte;
    }
}

void miWidget::leerXml()
{
   doc.LoadFile();
   TiXmlNode *patr=doc.FirstChild();

    while(patr){
        QString codigo = QString::fromUtf8(patr->ToElement()->Attribute("Codigo"));
        QString ciudad = QString::fromUtf8(patr->ToElement()->Attribute("Ciudad"));
        int x = atoi(patr->ToElement()->Attribute("x"));
        int y =  atoi(patr->ToElement()->Attribute("y"));

        miGrafo.insertar_aeropuerto(codigo,ciudad,x,y);

        patr=patr->NextSibling();

    }
}

void miWidget::leerXml2()
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
