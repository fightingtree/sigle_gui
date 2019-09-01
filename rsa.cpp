#include "rsa.h"
#include "ui_rsa.h"

RSA::RSA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSA)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文(数字)");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    ui->a_line->setPlaceholderText("如需解密输入私钥a");
    ui->b_line->setPlaceholderText("如需解密输入私钥b");
    this->process= new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

RSA::~RSA()
{
    delete ui;
}

void RSA::on_pushButton_clicked()
{
    int e =1;
    change(e);
    QString cmd = "./rsa.py 1 "+this->ui->plaintext_edit->toPlainText();
   // qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->ciphertext_edit->setText(out);
}

void RSA::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd = "./rsa.py 2 "+this->ui->ciphertext_edit->toPlainText()+" "+this->ui->a_line->text()+" "+this->ui->
            b_line->text();
    //qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
    this->ui->ciphertext_edit->setText(out);
}

void RSA::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->a_line->setText(" ");
    this->ui->b_line->setText(" ");
}

void RSA::readOutput(){
    out += process->readAll();
    if(flag == 1){
        this->ui->ciphertext_edit->setText(out);
    }
    else{
        this->ui->plaintext_edit->setText(out);
    }
}

void RSA::change(int i){
     flag =i;
}
