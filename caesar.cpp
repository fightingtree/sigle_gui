#include "caesar.h"
#include "ui_caesar.h"
#include <QDebug>
Caesar::Caesar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Caesar)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    ui->keyword_line->setPlaceholderText("请输入数字");
    this->process = new QProcess;


    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));

    //准备从进程里读数据的槽
}

Caesar::~Caesar()
{
    delete ui;
}

void Caesar::on_encrption_button_clicked()
{
    int a =1;
    change(a);
    QString cmd = this->ui->keyword_line->text();//获取keyword_line的内容
    QString plaintext=this->ui->plaintext_edit->toPlainText();
    cmd = "./caesar.py e "+plaintext+" "+cmd;
    //qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
    ui->ciphertext_edit->setText(out);

}

void Caesar::readOutput(){
   // qDebug()<<flag;
    out += process->readAll();
    qDebug()<<out;
    if(flag ==1){
        ui->ciphertext_edit->setText(out);
}
    else{
        ui->plaintext_edit->setText(out);
    }
}
void Caesar::on_decrption_button_clicked()
{
    int b = 2;
    change(b);
    QString cmd = this->ui->keyword_line->text();
    QString ciphertext = this->ui->ciphertext_edit->toPlainText();
    cmd ="./caesar.py d "+ciphertext+" "+cmd;
    qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
    ui->plaintext_edit->setText(out);
}

void Caesar::change(int i){
    flag = i;
}

void Caesar::on_pushButton_3_clicked()
{
   this->ui->plaintext_edit->setText(" ");
   this->ui->ciphertext_edit->setText(" ");
   this->ui->keyword_line->setText(" ");
}
