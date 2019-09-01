#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class Playfair;
}

class Playfair : public QWidget
{
    Q_OBJECT

public:
    explicit Playfair(QWidget *parent = nullptr);
    ~Playfair();

private:
    Ui::Playfair *ui;
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

#endif // PLAYFAIR_H
