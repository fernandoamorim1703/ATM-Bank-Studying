#include "infoaccount.h"
#include "ui_infoaccount.h"
#include"accountvector.h"

infoAccount::infoAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoAccount)
{
    ui->setupUi(this);
    connect(ui->btnSearchCpf,SIGNAL(clicked()),this,SLOT(btnSeachCpf()));
}

infoAccount::~infoAccount()
{
    delete ui;
}

void infoAccount::btnSeachCpf()
{
    long cpf=ui->editCpf->text().toLong();
    bool exists=false;
    int index;
    QString account;

    for(size_t i=0;i<AccountVector::instance()->accounts.size();i++){
        if(AccountVector::instance()->accounts[i].cpf==cpf){
            exists=true;
            index=i;
            break;
        }
    }

    if(exists==true){
        account.append("----Conta "+ QString(AccountVector::instance()->accounts[index].typeAccount) + "-----");
        account.append("\nNome: " + QString (AccountVector::instance()->accounts[index].nome) + "\nIdade: " + QString::number(AccountVector::instance()->accounts[index].idade) + "\nNascimento: " + QString::number(AccountVector::instance()->accounts[index].nascimento) + "\nCPF: " + QString::number(AccountVector::instance()->accounts[index].cpf) + "\nEmail: " + QString (AccountVector::instance()->accounts[index].email));
    }else{
        account.append("Conta não encontrada!");
    }

    ui->textEditCpf->setPlainText(account);

}
