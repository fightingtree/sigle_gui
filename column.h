#ifndef COLUMN_H
#define COLUMN_H
#include <QProcess>
#include <QDebug>
#include <QWidget>

namespace Ui {
class Column;
}

class Column : public QWidget
{
    Q_OBJECT

public:
    explicit Column(QWidget *parent = nullptr);
    ~Column();

private:
    Ui::Column *ui;
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

#endif // COLUMN_H
