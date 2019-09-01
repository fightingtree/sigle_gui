#include "rc4.h"
#include "ui_rc4.h"

RC4::RC4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RC4)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    this->process= new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

RC4::~RC4()
{
    delete ui;
}

void RC4::on_pushButton_clicked()
{
    int e =1;
    change(e);
    QString cmd = "./rc4.py 1 "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->ciphertext_edit->setText(out);
}

void RC4::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd ="./rc4.py 2 "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->plaintext_edit->setText(out);
}

void RC4::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");
}

void RC4::readOutput(){
    out += process->readAll();
    if(flag == 1){
        ui->ciphertext_edit->setText(out);
    }
    else{
        ui->plaintext_edit->setText(out);
    }

}
void RC4::change(int i){
    flag = i;
}
