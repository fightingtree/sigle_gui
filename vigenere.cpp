#include "vigenere.h"
#include "ui_vigenere.h"

Vigenere::Vigenere(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vigenere)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

Vigenere::~Vigenere()
{
    delete ui;
}

void Vigenere::on_pushButton_clicked()
{
    int e =1;
    change(e);
    QString cmd ="./vigenere.py 1 "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out= tr("");
    this->ui->ciphertext_edit->setText(out);
}

void Vigenere::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd ="./vigenere.py 2 "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->plaintext_edit->setText(out);
}

void Vigenere::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");

}

void Vigenere::change(int i){
    flag =i;
}
void Vigenere::readOutput(){
    out+=process->readAll();
    if(flag==1){
        this->ui->ciphertext_edit->setText(out);
    }
    else{
        this->ui->plaintext_edit->setText(out);
    }
}
