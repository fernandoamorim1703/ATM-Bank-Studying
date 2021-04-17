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
        strcpy(conta.typeAccount,"Corrente");
    }else if (ui->radioPoupanca->isChecked()==true) {
        strcpy(conta.typeAccount,"Poupanca");
    }else {
        strcpy(conta.typeAccount,"Jurídica");
    }

    conta.idade=idade;
    conta.cpf=cpf;
    conta.nascimento=nascimento;

    char nome;

    strcpy(&nome,name.toLatin1());
    strcpy(conta.nome,&nome);

    char mail;

    strcpy(&mail,email.toLatin1());
    strcpy(conta.email,&mail);

    qDebug() << conta.nome;


    AccountVector::instance()->accounts.push_back(conta);

   /* ui->editName->clear();
    ui->editCpf->clear();
    ui->editNascimento->clear();
    ui->EditEmail->clear();
    ui->editIdade->clear();*/
    //close();
}
