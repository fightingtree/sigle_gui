#ifndef RSA_H
#define RSA_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class RSA;
}

class RSA : public QWidget
{
    Q_OBJECT

public:
    explicit RSA(QWidget *parent = nullptr);
    ~RSA();

private:
    Ui::RSA *ui;
    QProcess *process;
    QString out;
    int flag;
private slots:
    void readOutput();
    void change(int i);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // RSA_H
