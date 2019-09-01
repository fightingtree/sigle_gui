#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "content.h"
#include <QMainWindow>
#include <QGridLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Content *content;
    QGridLayout *mainLayout;
    void createAction();
    void createToolBar();


private:
    Ui::MainWindow *ui;
    QToolBar *stackTool;
    QAction *openStack[10];

private slots:
    void openCaesar();
    void openAffine();
    void openVigenere();
    void openPlayfair();
    void openPermutation();
    void openColumn();
    void openRC4();
    void openDES();
    void openRSA();
    void openDH();
};

#endif // MAINWINDOW_H
