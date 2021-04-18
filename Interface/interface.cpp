#include "interface.h"
#include "ui_interface.h"
#include "personaccount.h"
#include<QDebug>
#include <stdio.h>
#include <string.h>


interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    connect(ui->btnMainCreatAccount,SIGNAL(clicked()),this,SLOT(btnMainCreatAccount()));
    connect(ui->btnShowAllAccounts,SIGNAL(clicked()),this,SLOT(btnShowAllAccounts()));
    connect(ui->btnSeeAccount,SIGNAL(clicked()),this,SLOT(btnSeeAccount()));
}

interface::~interface()
{
    delete ui;
}



void interface::btnMainCreatAccount()
{
    ca = new openAccount(this);
    ca->setModal(true);
    ca->show();
}

void interface::btnShowAllAccounts()
{
    sa = new showaccounts(this);
    sa->setModal(true);
    sa->show();
}

void interface::btnSeeAccount()
{
    ia = new infoAccount(this);
    ia->setModal(true);
    ia->show();
}
