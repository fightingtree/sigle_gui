#ifndef VIGENERE_H
#define VIGENERE_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class Vigenere;
}

class Vigenere : public QWidget
{
    Q_OBJECT

public:
    explicit Vigenere(QWidget *parent = nullptr);
    ~Vigenere();
    int flag;

private:
    Ui::Vigenere *ui;
    QProcess *process;
    QString out;
private slots:
    void readOutput();
    void change(int i);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // VIGENERE_H
