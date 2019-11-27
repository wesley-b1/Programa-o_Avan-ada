#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    matrizX = 1;
    matrizY = 1;
    matrizZ = 1;

    ui->lineEditXPut->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditYPut->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZPut->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditXBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditYBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditSphere->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditXEllip->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditYEllip->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZEllip->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditR->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditG->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditB->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditA->QLineEdit::setValidator( new QIntValidator(0, 100, this) );
    ui->horizontalSliderMatriz->QSlider::setMaximum(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSliderMatriz_valueChanged()
{
    ui->plotter->setZAtual(ui->horizontalSliderMatriz->value());
}

void MainWindow::on_pushButtonMatriz_clicked()
{
    matrizX = ui->lineEditXPut->text().toInt();
    matrizY = ui->lineEditYPut->text().toInt();
    matrizZ = ui->lineEditZPut->text().toInt();

    ui->horizontalSliderMatriz->QSlider::setMaximum(matrizZ-1);

    ui->plotter->setSizeMatriz(matrizX,matrizY,matrizZ);
}

void MainWindow::on_pushButtonCor_clicked()
{
    int r,g,b,a=100;

    r = ui->lineEditR->text().toInt();
    g = ui->lineEditG->text().toInt();
    b = ui->lineEditB->text().toInt();
    a = ui->lineEditA->text().toInt();

    ui->plotter->setRGBA(r,g,b,a);
}

void MainWindow::on_pushButtonPutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->lineEditXBox->text().toInt();
    y1 = ui->lineEditYBox->text().toInt();
    z1 = ui->lineEditZBox->text().toInt();

    ui->plotter->putBox(x1,y1,z1);
}

void MainWindow::on_pushButtonCutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->lineEditXBox->text().toInt();
    y1 = ui->lineEditYBox->text().toInt();
    z1 = ui->lineEditZBox->text().toInt();

    ui->plotter->cutBox(x1,y1,z1);
}

void MainWindow::on_pushButtonPutSphere_clicked()
{
    int r;

    r = ui->lineEditSphere->text().toInt();

    ui->plotter->putSphere(r);
}

void MainWindow::on_pushButtonCutSphere_clicked()
{
    int r;

    r = ui->lineEditSphere->text().toInt();

    ui->plotter->cutSphere(r);
}

void MainWindow::on_pushButtonPutEllipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->lineEditXEllip->text().toInt();
    ry = ui->lineEditYEllip->text().toInt();
    rz = ui->lineEditZEllip->text().toInt();

    ui->plotter->putEllipsoid(rx,ry,rz);
}

void MainWindow::on_pushButtonCutEllipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->lineEditXEllip->text().toInt();
    ry = ui->lineEditYEllip->text().toInt();
    rz = ui->lineEditZEllip->text().toInt();

    ui->plotter->cutEllipsoid(rx,ry,rz);
}

void MainWindow::on_radioButtonPut_clicked()
{
    ui->plotter->setRadioButton(1);
}

void MainWindow::on_radioButtonBox_clicked()
{
    ui->plotter->setRadioButton(2);
}

void MainWindow::on_radioButtonSphere_clicked()
{
    ui->plotter->setRadioButton(3);
}
void MainWindow::on_radioButtonEllip_clicked()
{
    ui->plotter->setRadioButton(4);
}

void MainWindow::on_pushButtonSalvar_clicked()
{
    string nome = ui->lineEditSalvar->text().toStdString();
    nome = nome + ".OFF";
    ui->plotter->Salvar(nome);
}

