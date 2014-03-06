#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admin1.h"
#include "cliente.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap("://imagenes/adim.ico");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(pixmap.rect().size());

    QPixmap pixmap2("://imagenes/users.ico");
    QIcon ButtonIcon2(pixmap2);
    ui->pushButton_2->setIcon(ButtonIcon2);
    ui->pushButton_2->setIconSize(pixmap2.rect().size());

    QPixmap pixmap3("://imagenes/logout.ico");
    QIcon ButtonIcon3(pixmap3);
    ui->pushButton_3->setIcon(ButtonIcon3);
    ui->pushButton_3->setIconSize(pixmap3.rect().size());

    //this->miGrafo;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     admin1 ventana;
     ventana.setModal(true);
     ventana.setGrafo(&miGrafo);
     ventana.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    cliente ventana;
    ventana.setModal(true);
    ventana.setGrafo(&miGrafo);
    ventana.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
