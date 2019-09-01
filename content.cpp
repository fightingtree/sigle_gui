#include "content.h"
#include "ui_content.h"

Content::Content(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Content)
{
    ui->setupUi(this);
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    caesar = new Caesar();
    affine = new Affine();
    vigenere = new Vigenere();
    playfair = new Playfair();
    permutation = new Permutation();
    column = new Column();
    rc4 = new RC4();
    des = new DES();
    rsa = new RSA();
    dh = new DH();

    stack->addWidget(caesar);
    stack->addWidget(affine);
    stack->addWidget(vigenere);
    stack->addWidget(playfair);
    stack->addWidget(permutation);
    stack->addWidget(column);
    stack->addWidget(rc4);
    stack->addWidget(des);
    stack->addWidget(rsa);
    stack->addWidget(dh);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(2);
    mainLayout->addWidget(stack,0,0);
}

Content::~Content()
{
    delete ui;
}
