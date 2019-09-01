#ifndef AFFINE_H
#define AFFINE_H
#include <QProcess>
#include <QWidget>

namespace Ui {
class Affine;
}

class Affine : public QWidget
{
    Q_OBJECT

public:
    explicit Affine(QWidget *parent = nullptr);
    ~Affine();
    int flag;

private:
    Ui::Affine *ui;
    QProcess *process;
    QString out;
private slots:
    void readOutput();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void change(int i);
    void on_pushButton_3_clicked();
};

#endif // AFFINE_H
