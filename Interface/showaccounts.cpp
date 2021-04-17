#include "showaccounts.h"
#include "ui_showaccounts.h"
#include"accountvector.h"

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
   QString account;
    if((AccountVector::instance()->accounts.size()) > 0){
        for(size_t i=0;i<AccountVector::instance()->accounts.size();i++){
            account.append("----Conta "+ QString(AccountVector::instance()->accounts[i].typeAccount) + "-----");
            account.append("\nNome: " + QString (AccountVector::instance()->accounts[i].nome) + "\nIdade: " + QString::number(AccountVector::instance()->accounts[i].idade) + "\nNascimento: " + QString::number(AccountVector::instance()->accounts[i].nascimento) + "\nCPF: " + QString::number(AccountVector::instance()->accounts[i].cpf) + "\nEmail: " + QString (AccountVector::instance()->accounts[i].email));
            account.append("\n-----------------");
        }
    }

    ui->editAllAccounts->setPlainText(account);
}
