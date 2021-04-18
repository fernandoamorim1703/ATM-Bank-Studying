#ifndef PERSONACCOUNT_H
#define PERSONACCOUNT_H
#include<vector>
#include<QString>
#include<QDate>
class PersonAccount{
    public:
        QString nome;
        int idade;
        long cpf;
        QDate nascimento;
        QString email;
        QString typeAccount;
        long saldo;
};


#endif // PERSONACCOUNT_H
