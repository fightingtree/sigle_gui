#include "dh.h"
#include "ui_dh.h"

DH::DH(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DH)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("密钥交换过程演示");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

DH::~DH()
{
    delete ui;
}

void DH::on_pushButton_2_clicked()
{
    QString cmd = "./dh.py "+this->ui->lineEdit->text();
    //qDebug()<<cmd;
    process->start(cmd);
    out =tr("");
    this->ui->textEdit->setText(out);
}

void DH::on_pushButton_clicked()
{
   this->ui->lineEdit->setText(" ");
   this->ui->textEdit->setText(" ");
}

void DH::readOutput(){
     out += process->readAll();
     this->ui->textEdit->setText(out);
}
