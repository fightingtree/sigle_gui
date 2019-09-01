#include "affine.h"
#include "ui_affine.h"
#include <QDebug>
Affine::Affine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Affine)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    ui->a_line->setPlaceholderText("0-25");
    ui->b_line->setPlaceholderText("0-25,(b,26)=1");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));

}


Affine::~Affine()
{
    delete ui;
}

void Affine::on_pushButton_clicked()
{
    int e = 1;
    change(e);
     QString cmd ="./test.py 1 "+this->ui->a_line->text()+" "+
             this->ui->b_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    // qDebug()<<cmd;
     process->start(cmd);
     out=tr("");
     ui->ciphertext_edit->setText(out);
}

void Affine::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd = "./test.py 2 "+this->ui->a_line->text()+
" "+this->ui->b_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
    ui->plaintext_edit->setText(out);
}

void Affine::readOutput(){
    out+=process->readAll();
    qDebug()<<out;
    if(flag == 1){
        ui->ciphertext_edit->setText(out);
    }
    else{
        ui->plaintext_edit->setText(out);
    }

}

void Affine::change(int i){
    flag = i;
}

void Affine::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->a_line->setText(" ");
    this->ui->b_line->setText(" ");
}
