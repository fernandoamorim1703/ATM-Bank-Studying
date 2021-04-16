#include "openaccount.h"
#include"personaccount.h"
#include "ui_openaccount.h"
#include "interface.h"
#include <stdio.h>
#include <string.h>

std::vector<PersonAccount> accounts;


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
    PersonAccount conta;// = new PersonAccount();

    QString name (ui->editName->text());
    QString email (ui->EditEmail->text());
    int idade=ui->editIdade->text().toInt();
    int cpf=ui->editCpf->text().toInt();
    int nascimento=ui->editNascimento->text().toInt();
    int tipoConta;
    if(ui->radioCorrente->isChecked()){
        tipoConta=1;
    }else if (ui->radioPoupanca->isChecked()) {
        tipoConta=2;
    }else {
        tipoConta=3;
    }
    char nome,mail;
    strcpy(&nome,name.toLatin1());
    strcpy(&mail,email.toLatin1());

    strcpy(conta.nome,&nome);
    conta.idade=idade;
    conta.cpf=cpf;
    conta.nascimento=nascimento;
    strcpy(conta.email,&mail);
    conta.typeAccount=tipoConta;
    accounts.push_back(conta);

    ui->editName->clear();
    ui->editCpf->clear();
    ui->editNascimento->clear();
    ui->EditEmail->clear();
    ui->editIdade->clear();
    close();
}
