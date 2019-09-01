#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class Permutation;
}

class Permutation : public QWidget
{
    Q_OBJECT

public:
    explicit Permutation(QWidget *parent = nullptr);
    ~Permutation();

private:
    Ui::Permutation *ui;
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

#endif // PERMUTATION_H
