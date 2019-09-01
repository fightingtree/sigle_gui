#include "playfair.h"
#include "ui_playfair.h"

Playfair::Playfair(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playfair)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文(字母数为偶数)");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    this->process= new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));

}

Playfair::~Playfair()
{
    delete ui;
}



void Playfair::on_pushButton_clicked()
{
    int e = 1;
    change(e);
    QString cmd = "./palyfair.py D "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
   // qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
    this->ui->ciphertext_edit->setText(out);
}

void Playfair::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd = "./palyfair.py E "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->plaintext_edit->setText(out);

}

void Playfair::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");

}

void Playfair::change(int i){
    flag =i;

}

void Playfair::readOutput(){
     out+=process->readAll();
     if(flag ==1){
         this->ui->ciphertext_edit->setText(out);
     }
     else{
         this->ui->plaintext_edit->setText(out);
     }


}
