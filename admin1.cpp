#include "admin1.h"
#include "ui_admin1.h"
#include "qlabel.h"

admin1::admin1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin1)
{
    ui->setupUi(this);

    this->a = new miWidget(this);
    a->setGeometry(20,130,900,431);
    a->show();

    QPixmap pixmap("://imagenes/save.ico");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(pixmap.rect().size());

    QPixmap pixmap2("://imagenes/stop-error.ico");
    QIcon ButtonIcon2(pixmap2);
    ui->pushButton_2->setIcon(ButtonIcon2);
    ui->pushButton_2->setIconSize(pixmap2.rect().size());

    QPixmap pixmap3("://imagenes/save.ico");
    QIcon ButtonIcon3(pixmap3);
    ui->pushButton_3->setIcon(ButtonIcon3);
    ui->pushButton_3->setIconSize(pixmap3.rect().size());

    QPixmap pixmap4("://imagenes/stop-error.ico");
    QIcon ButtonIcon4(pixmap4);
    ui->pushButton_4->setIcon(ButtonIcon4);
    ui->pushButton_4->setIconSize(pixmap4.rect().size());

    this->hacerPunto=true;

    doc=TiXmlDocument("Aeropuertos.xml");
    doc2=TiXmlDocument("Conexiones.xml");

    leerXml();
    leerXml2();

    miGrafo->mostrar_grafo();
}

admin1::~admin1()
{
    delete ui;
}

void admin1::mousePressEvent(QMouseEvent *ev)
{     
    x = ev->x();
    y = ev->y();

    if(ui->frame_2->isEnabled())
        return;

    if(checkPunto(x-5,y-10))
    {
        ui->frame_2->setEnabled(true);

        Aeropuerto *actual = miGrafo->recuperar(ev->x(),ev->y());
        if(actual!=NULL)
          cout<<actual->ciudad.toStdString()<<endl;
    }
    else if(hacerPunto && x>=35 && x<=900 && y>=140 && y<=551){
          this->x=ev->x()-5;
          this->y=ev->y()-10;

          dibujarPunto(x,y);

          ui->frame->setEnabled(true);
          hacerPunto = false;
          update();
     }
}

void admin1::escribirXml(int x, int y, QString codigo, QString ciudad)
{
       doc.LoadFile();

       TiXmlElement *element=new TiXmlElement("aeropuerto");
       element->SetAttribute("Codigo",codigo.toStdString().c_str());
       element->SetAttribute("Ciudad",ciudad.toStdString().c_str());
       element->SetAttribute("x",x);
       element->SetAttribute("y",y);
       doc.LinkEndChild(element);
       doc.SaveFile();
}

void admin1::leerXml()
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


        //Cargar al grafo los aeropuertos existentes
        miGrafo->insertar_aeropuerto(codigo,ciudad,x,y);

        patr=patr->NextSibling();

    }
}

void admin1::escribirXml2(QString inicio, QString destino, double costo)
{
       doc2.LoadFile();

       TiXmlElement *element=new TiXmlElement("conexion");
       element->SetAttribute("Inicio",inicio.toStdString().c_str());
       element->SetAttribute("Destino",destino.toStdString().c_str());
       element->SetDoubleAttribute("Costo",costo);

       doc2.LinkEndChild(element);
       doc2.SaveFile();
}

void admin1::leerXml2()
{
   doc2.LoadFile();
   TiXmlNode *patr=doc2.FirstChild();

    while(patr){
        QString inicio = QString::fromUtf8(patr->ToElement()->Attribute("Inicio"));
        QString destino = QString::fromUtf8(patr->ToElement()->Attribute("Destino"));
        double costo = atof(patr->ToElement()->Attribute("Costo"));


        //Cargar al grafo los aeropuertos existentes
        miGrafo->insertar_conexion(inicio,destino,costo);

        patr=patr->NextSibling();

    }
}

void admin1::dibujarPunto(int x, int y)
{
    QPixmap punto=QPixmap(":/imagenes/punto.png");
    QLabel *imagen=new QLabel(this) ;
    imagen->setPixmap(punto);
    imagen->setScaledContents(true);
    imagen->setGeometry(x,y,10,10);
    imagen->raise();
    imagen->show();
}

bool admin1::checkPunto(int x1, int y1)
{
    doc.LoadFile();
    TiXmlNode *patr=doc.FirstChild();

     while(patr){
         int x = atoi(patr->ToElement()->Attribute("x"));
         int y =  atoi(patr->ToElement()->Attribute("y"));

         if((((x1>= x)&& (x1<= x+20)) || ((x1+20 >= x)&& (x1+20 <= x+20))) &&
                (((y1 >= y) && (y1 <= y+20)) || ((y1+20 >= y) && (y1+20 <= y+20))))
         return true;

         patr=patr->NextSibling();

     }

     return false;
}

void admin1::setGrafo(Grafo *miGrafo)
{
    this->miGrafo = miGrafo;
}

void admin1::on_pushButton_2_clicked()
{
    this->close();
}

void admin1::on_pushButton_4_clicked()
{
    this->close();
}

void admin1::on_pushButton_clicked()
{
    if(ui->lineEdit->text().toStdString() != "" && ui->lineEdit_2->text().toStdString() !="")
    {
        QString codigo = ui->lineEdit->text();
        QString ciudad = ui->lineEdit_2->text();

        this->escribirXml(x,y,codigo,ciudad);

        QMessageBox msgBox;
        msgBox.setText("El aeropuerto ha sido guardado");
        msgBox.setInformativeText("¿Desea agregar uno nuevo?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Yes:
               this->hacerPunto = true;
               ui->lineEdit->setText("");
               ui->lineEdit_2->setText("");
               ui->frame->setEnabled(false);
               break;
           case QMessageBox::No:
               this->close();
               break;
           default:
               // should never be reached
               break;
         }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Complete los datos para guardar");
        msgBox.exec();
    }
}

void admin1::on_pushButton_3_clicked()
{
    if(ui->lineEdit_3->text().toStdString() != "")
    {
        double costo = ui->lineEdit_3->text().toDouble();

        QString inicio = ui->comboBox->itemText(ui->comboBox->currentIndex());
        QString destino = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());

        this->escribirXml2(inicio,destino,costo);

        QMessageBox msgBox;
        msgBox.setText("La conexión ha sido guardada");
        msgBox.setInformativeText("¿Desea agregar una nueva?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Yes:
               ui->lineEdit_3->setText("");
               hacerPunto = false;
               break;
           case QMessageBox::No:
               this->close();
               break;
           default:
               // should never be reached
               break;
         }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Complete los datos para guardar");
        msgBox.exec();
    }
}
