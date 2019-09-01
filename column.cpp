#include "column.h"
#include "ui_column.h"

Column::Column(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Column)
{
    ui->setupUi(this);
    ui->plaintext_edit->setPlaceholderText("请输入明文");
    ui->ciphertext_edit->setPlaceholderText("请输入密文");
    ui->keyword_line->setPlaceholderText("1<=n<=5,5");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
}

Column::~Column()
{
    delete ui;
}

void Column::on_pushButton_clicked()
{
    int e =1;
    change(e);
    QString cmd = "./transposition 1 "+this->ui->keyword_line->text()+" "+this->ui->plaintext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    ui->ciphertext_edit->setText(out);
}

void Column::on_pushButton_2_clicked()
{
    int d = 2;
    change(d);
    QString cmd="./transposition 2 "+this->ui->keyword_line->text()+" "+this->ui->ciphertext_edit->toPlainText();
    //qDebug()<<cmd;
    process->start(cmd);
    out = tr("");
    ui->plaintext_edit->setText(out);
}

void Column::on_pushButton_3_clicked()
{
    this->ui->plaintext_edit->setText(" ");
    this->ui->ciphertext_edit->setText(" ");
    this->ui->keyword_line->setText(" ");
}

void Column::readOutput(){
    out += process->readAll();
    if(flag == 1){
        ui->ciphertext_edit->setText(out);
    }
    else{
        ui->plaintext_edit->setText(out);
    }
}

void Column::change(int i){
    flag = i;
}
