#include "permutation.h"
#include "ui_permutation.h"

Permutation::Permutation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Permutation)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

Permutation::~Permutation()
{
    delete ui;
}

void Permutation::on_pushButton_clicked()
{
    int e =1;
    change(e);
    QString cmd = "./permutation 1 "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->ciphertext_edit->setText(out);
}

void Permutation::on_pushButton_2_clicked()
{
    int d =2;
    change(d);
    QString cmd ="./permutation 2 "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    this->ui->plaintext_edit->setText(out);
}

void Permutation::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");

}

void Permutation::readOutput(){
     out +=process->readAll();
     if(flag == 1){
         ui->ciphertext_edit->setText(out);
     }
     else{
         ui->plaintext_edit->setText(out);
     }
}
void Permutation::change(int i){
     flag = i;
}
