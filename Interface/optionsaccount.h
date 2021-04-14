#ifndef OPTIONSACCOUNTS_H
#define OPTIONSACCOUNTS_H


class OptionsAccounts
{
public:
    int newAccount(int idade, int cpf, int nascimento, int tipoConta);
    void managerOption();
    void deleteAccount();
    void transactAccount();
    int searchCpf();
    void changeInfoAccount(int index);
    int infoAccount(int index);
};

#endif // OPTIONSACCOUNTS_H
