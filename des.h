#ifndef DES_H
#define DES_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class DES;
}

class DES : public QWidget
{
    Q_OBJECT

public:
    explicit DES(QWidget *parent = nullptr);
    ~DES();

private:
    Ui::DES *ui;
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

#endif // DES_H
