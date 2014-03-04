#include "admin1.h"
#include "ui_admin1.h"
#include "qlabel.h"

admin1::admin1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin1)
{

    ui->setupUi(this);

    QLabel *imageLabel = new QLabel(this);
    QImage image("://imagenes/mapa.png");
    imageLabel->setPixmap(QPixmap::fromImage(image));

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(imageLabel);

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
    leerXml();

}

admin1::~admin1()
{
    delete ui;
}

void admin1::on_admin1_accepted()
{

}

void admin1::mouseMoveEvent(QMouseEvent *ev)
{
    //
}

void admin1::mousePressEvent(QMouseEvent *ev)
{     
     if(hacerPunto){
          x = ev->x();
          y = ev->y();

          QPixmap punto=QPixmap(":/imagenes/punto.png");
          QLabel *imagen=new QLabel(this) ;
          imagen->setPixmap(punto);
          imagen->setScaledContents(true);
          this->x=ev->x()-5;
          this->y=ev->y()-10;
          imagen->setGeometry(x,y,10,10);
          imagen->raise();
          imagen->show();

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
        int x,y;
        QString codigo, nombre;

       // TiXmlAttribute *atrX = patr->ToElement()->FirstAttribute();
       // TiXmlAttribute *atr = patr->ToElement()->Attribute("Codigo");
      //  TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();

       // atrX->Next()->QueryIntValue(&x);
       // cout<<x<<endl;

    cout<<  patr->ToElement()->Attribute("Codigo")<<endl;
    cout<<  patr->ToElement()->Attribute("Ciudad")<<endl;
    cout<<  patr->ToElement()->Attribute("x")<<endl;
    cout<<  patr->ToElement()->Attribute("y")<<endl;

       // atrY->QueryIntValue(&y);
       //  cout<<y<<endl;
       patr=patr->NextSibling();
      }
}

bool admin1::checkPunto(int x, int y)
{

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
