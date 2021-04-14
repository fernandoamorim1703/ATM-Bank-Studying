#include "interfacebank.h"
#include "ui_interfacebank.h"
#include<QTWidgets

interfaceBank::interfaceBank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceBank)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(apertarBotao()));
}

interfaceBank::~interfaceBank()
{
    delete ui;
}

void interfaceBank::apertarBotao()
{
    ui->textEdit->setPlainText("ola");
}
