#include "interface.h"
#include "ui_interface.h"
#include "optionsaccount.h"
#include "personaccount.h"
#include<QDebug>
#include <stdio.h>
#include <string.h>

std::vector<PersonAccount *> accounts2;

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    connect(ui->inserir,SIGNAL(clicked()),this,SLOT(inserir()));
    connect(ui->showAll,SIGNAL(clicked()),this,SLOT(showAll()));
}

interface::~interface()
{
    delete ui;
}


void interface::inserir()
{
    PersonAccount *conta2 = new PersonAccount();

    QString name (ui->editNome->text());
    QString email (ui->editEmail->text());

    strcpy(conta2->nome,name.toLatin1());
    conta2->cpf=(ui->editCpf->text().toInt());
    conta2->idade=(ui->editIdade->text().toInt());
    conta2->nascimento=(ui->editNascimento->text().toInt());
    conta2->typeAccount=(ui->editTipoconta->text().toInt());
    strcpy(conta2->email,email.toLatin1());

    accounts2.push_back(conta2);

    ui->label->setText("Conta inserida com sucesso!");

    ui->editNome->clear();
    ui->editCpf->clear();
    ui->editNascimento->clear();
    ui->editEmail->clear();
    ui->editIdade->clear();
    ui->editTipoconta->clear();

}

void interface::showAll()
{
    ui->textEdit->clear();
    char tipoAccount[10];
    QString data = ui->textEdit->toPlainText();
    for(size_t i=0;i<accounts2.size();i++){
        if((accounts2[i]->typeAccount)==1){
            strcpy(tipoAccount,"Poupanca");
        }else if ((accounts2[i]->typeAccount)==2) {
            strcpy(tipoAccount,"Corrente");
        }else {
            strcpy(tipoAccount,"Juridica");
        }
        data.append("*****Conta  "+ QString(tipoAccount) + "*****\n");
        data.append("Nome: " + QString(accounts2[i]->nome) + "\nIdade: " + QString::number(accounts2[i]->idade) + "\nCPF: " + QString::number(accounts2[i]->cpf)+ "\nNascimento:" + QString::number(accounts2[i]->nascimento) + "\nEmail: " + QString(accounts2[i]->email) + "\n\n");
    }

    ui->textEdit->setPlainText(data);
}
