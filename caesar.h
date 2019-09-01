#ifndef CAESAR_H
#define CAESAR_H
#include <QProcess>
#include <QWidget>

namespace Ui {
class Caesar;
}

class Caesar : public QWidget
{
    Q_OBJECT

public:
    explicit Caesar(QWidget *parent = nullptr);
    int flag;
    void change(int i);
    ~Caesar();

private:
    Ui::Caesar *ui;
    QProcess *process;
    QString out;

private slots:
    void readOutput();//从进程中读取数据
    void on_encrption_button_clicked();//点击按钮触发外部程序
    void on_decrption_button_clicked();
    void on_pushButton_3_clicked();
};

#endif // CAESAR_H
