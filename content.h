#ifndef CONTENT_H
#define CONTENT_H
#include <QStackedWidget>
#include <QFrame>
#include <QGridLayout>
#include "caesar.h"
#include "affine.h"
#include "vigenere.h"
#include "playfair.h"
#include "permutation.h"
#include "column.h"
#include "rc4.h"
#include "des.h"
#include "rsa.h"
#include "dh.h"

namespace Ui {
class Content;
}

class Content : public QFrame
{
    Q_OBJECT

public:
    explicit Content(QWidget *parent = nullptr);
    QStackedWidget *stack;
    Caesar *caesar;
    Affine *affine;
    Vigenere *vigenere;
    Playfair *playfair;
    Permutation *permutation;
    Column *column;
    RC4 *rc4;
    DES *des;
    RSA *rsa;
    DH *dh;
    ~Content();
signals:
public slots:
private:
    Ui::Content *ui;
    QGridLayout *mainLayout;
};

#endif // CONTENT_H
