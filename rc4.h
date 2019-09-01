#ifndef RC4_H
#define RC4_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class RC4;
}

class RC4 : public QWidget
{
    Q_OBJECT

public:
    explicit RC4(QWidget *parent = nullptr);
    ~RC4();

private:
    Ui::RC4 *ui;
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

#endif // RC4_H
