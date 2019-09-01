#ifndef DH_H
#define DH_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class DH;
}

class DH : public QWidget
{
    Q_OBJECT

public:
    explicit DH(QWidget *parent = nullptr);
    ~DH();

private:
    Ui::DH *ui;
    QProcess *process;
    QString out;

private slots:
    void readOutput();

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DH_H
