#include "openaccount.h"
#include"personaccount.h"
#include "ui_openaccount.h"
#include"accountvector.h"
#include "interface.h"
#include <stdio.h>
#include <string.h>
#include<QDebug>

openAccount::openAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openAccount)
{
    ui->setupUi(this);
    connect(ui->btnCreateAccount,SIGNAL(clicked()),this,SLOT(btnCreateAccount()));
}

openAccount::~openAccount()
{
    delete ui;
}

void openAccount::btnCreateAccount()
{
    PersonAccount conta;

    conta.nome=ui->editName->text();
    conta.email=ui->EditEmail->text();
    conta.idade=ui->editIdade->text().toInt();
    conta.cpf=ui->editCpf->text().toLong();
    conta.nascimento=ui->editNascimento->text().toInt();
    if(ui->radioCorrente->isChecked()==true){
        conta.typeAccount="Corrente";
    }else if (ui->radioPoupanca->isChecked()==true) {
        conta.typeAccount="Poupança";
    }else {
        conta.typeAccount="Jurídica";
    }


    AccountVector::instance()->accounts.push_back(conta);

    close();
}
