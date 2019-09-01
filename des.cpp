#include "des.h"
#include "ui_des.h"

DES::DES(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DES)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    ui->keyword_line->setPlaceholderText("8 byte");
    this->process= new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

DES::~DES()
{
    delete ui;
}

void DES::on_pushButton_clicked()
{
    int e = 1;
    change(e);
    QString cmd = "./des 1 "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->ciphertext_edit->setText(out);
}

void DES::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd = "./des 2 "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->plaintext_edit->setText(out);
}

void DES::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");
}

void DES::readOutput(){
     out += process->readAll();
     if(flag == 1){
         ui->ciphertext_edit->setText(out);
     }
     else{
         ui->plaintext_edit->setText(out);
     }
}

void DES::change(int i){
   flag =i;
}
