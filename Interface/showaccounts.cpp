#include "showaccounts.h"
#include "ui_showaccounts.h"

showaccounts::showaccounts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showaccounts)
{
    ui->setupUi(this);
    connect(ui->showAllAccounts,SIGNAL(clicked()),this,SLOT(showAllAccounts()));
}

showaccounts::~showaccounts()
{
    delete ui;
}

void showaccounts::showAllAccounts()
{
    ui->editAllAccounts->setPlainText("Teste");
}
