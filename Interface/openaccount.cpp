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

    QString name (ui->editName->text());
    QString email (ui->EditEmail->text());
    int idade = ui->editIdade->text().toInt();
    long cpf=ui->editCpf->text().toLong();
    int nascimento=ui->editNascimento->text().toInt();
    if(ui->radioCorrente->isChecked()==true){
        conta.typeAccount="Corrente";
    }else if (ui->radioPoupanca->isChecked()==true) {
        conta.typeAccount="Poupança";
    }else {
        conta.typeAccount="Jurídica";
    }

    conta.idade=idade;
    conta.cpf=cpf;
    conta.nascimento=nascimento;
    conta.nome=name;
    conta.email=email;

    AccountVector::instance()->accounts.push_back(conta);

    close();
}
