#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<unistd.h>
#include"personaccount.h"
#include"optionsaccounts.h"

std::vector<PersonAccount *> accounts;

void OptionsAccounts::newAccount(){

    PersonAccount *conta = new PersonAccount();
    system("clear");
    printf("Informacoes necessarias:\n");
    printf("Nome: ");
    scanf("%s",conta->nome);
    printf("Idade: ");
    scanf("%d",&conta->idade);
    printf("CPF: ");
    scanf("%ld",&conta->cpf);
    printf("Data Nascimento(somente numeros): ");
    scanf("%d",&conta->nascimento);
    printf("Email: ");
    scanf("%s",conta->email);
    printf("Tipos de contas:");
    printf("\n|1 - Poupanca|\n|2- Corrente |\n|3 - Juridica|\n");
    printf("Qual deseja: ");
    scanf("%d",&conta->typeAccount);
    if(conta->typeAccount>3){
        system("clear");
        printf("Tipo de conta invalido!\n\n");
    }else{
        accounts.push_back(conta);
        system("clear");
        printf("Conta inserida com sucesso!\n\n");
    }
}

void OptionsAccounts::infoAccount(int index){
    system("clear");
    char tipoConta[9];

    if(accounts[index]->typeAccount==1){
        strcpy(tipoConta,"Poupanca");
    }else if (accounts[index]->typeAccount==2) {
        strcpy(tipoConta,"Corrente");
    }else{
        strcpy(tipoConta,"Juridica");
    }
    printf("-----Conta %s-----\n",tipoConta);
    printf("Nome: %s\nIdade: %d\nCPF: %ld\nNascimento: %d\nEmail: %s\nSaldo: R$ %ld\n\n",accounts[index]->nome,accounts[index]->idade,accounts[index]->cpf,accounts[index]->nascimento,accounts[index]->email,accounts[index]->saldo);
}

void OptionsAccounts::changeInfoAccount(int index){

    int newNascimento,newTypeAccount;
    int optionChange;
    char newName[40],newEmail[40];
    char tipoConta[9];

    system("clear");
    printf("O que deseja alterar?\n1 - Nome\n2 - Nascimento\n3 - Email\n4 - Tipo de conta\nOpcao: ");
    scanf("%d",&optionChange);
    system("clear");
    if(optionChange==1){
        printf("Alterar Nome: %s para :",accounts[index]->nome);
        scanf("%s",newName);
        strcpy(accounts[index]->nome, newName);
        system("clear");
        printf("Nome alterado com sucesso!\n\n");
    }else if (optionChange==2){
        printf("Alterar Data nascimento: %d para :",accounts[index]->nascimento);
        scanf("%d",&newNascimento);
        accounts[index]->nascimento=newNascimento;
        system("clear");
        printf("Data nascimento alterado com sucesso!\n\n");
    }else if (optionChange==3){
        printf("Alterar Email: %s para: ",accounts[index]->email);
        scanf("%s",newEmail);
        strcpy(accounts[index]->email,newEmail);
        system("clear");
        printf("Email alterado com sucesso!\n\n");
    }else if (optionChange==4){
        if(accounts[index]->typeAccount==1){
            strcpy(tipoConta,"Poupanca");
        }else if (accounts[index]->typeAccount==2) {
            strcpy(tipoConta,"Corrente");
        }else{
            strcpy(tipoConta,"Juridica");
        }
        printf("Seu tipo atual de conta e %s\n",tipoConta);
        printf("Tipos de contas:");
        printf("\n|1 - Poupanca|\n|2- Corrente |\n|3 - Juridica|\n");
        printf("Para qual deseja alterar: ");
        scanf("%d",&newTypeAccount);
        if(newTypeAccount>3){
            system("clear");
            printf("Tipo de conta invalido!\n\n");
        }else{
            accounts[index]->typeAccount=newTypeAccount;
        }

    }else{
        system("clear");
        printf("Opcao Invalida\n\n");
    }
}

int OptionsAccounts::searchCpf(){
    long escolhaCpf;
    int index=-1;
    bool exists=false;
    system("clear");

    printf("Digite CPF da conta que deseja(apenas numeros): ");
    scanf("%ld",&escolhaCpf);

    for(size_t i=0;i<accounts.size();i++){
        if ((accounts[i]->cpf)==(escolhaCpf)){
            index=i;
            exists=true;
            break;
        }
    }
    if(exists==false){
        system("clear");
        printf("Nao foi possivel encontrar registro para este CPF - %ld\n\n",escolhaCpf);
    }
    return index;
}

void OptionsAccounts::transactAccount(){
    int escolha,index,newIndex;
    long deposit,withdraw,pix;

    index=searchCpf();
    system("clear");
    printf("O que deseja fazer %s?\n1 - Depositar\n2 - Sacar\n3 - Transferir\nOpcao: ",accounts[index]->nome);
    scanf("%d",&escolha);

    if (index>=0){
        if(escolha==1){
            system("clear");
            printf("Seu saldo e: R$ %ld\n",accounts[index]->saldo);
            printf("Quanto deseja depositar: R$ ");
            scanf("%ld",&deposit);
            accounts[index]->saldo=deposit;
        }else if (escolha==2){
            system("clear");
            printf("Seu saldo e: R$ %ld\n",accounts[index]->saldo);
            printf("Quanto deseja sacar: R$ ");
            scanf("%ld",&withdraw);
            if(accounts[index]->saldo>=withdraw){
                accounts[index]->saldo=(accounts[index]->saldo-withdraw);
                printf("\nSaque realizado com sucesso!\n\n");
            }else {
                printf("\nSaldo insuficiente na sua conta!\n\n");
            }
        }else if (escolha==3){
            system("clear");
            printf("Transferencia bancaria\n");
            printf("Para quem deseja transferir? \n");
            newIndex=searchCpf();
            if(newIndex>=0){
                printf("Seu saldo e: R$ %ld\n",accounts[index]->saldo);
                printf("Quanto deseja transferir para %s :",accounts[newIndex]->nome);
                scanf("%ld",&pix);
                if(accounts[index]->saldo>=pix){
                    accounts[index]->saldo=(accounts[index]->saldo-pix);
                    accounts[newIndex]->saldo=(accounts[newIndex]->saldo+pix);
                    system("clear");
                    printf("\nTransferencia realiza com sucesso!\n\n");
                }else{
                    system("clear");
                    printf("\nSaldo insuficiente na sua conta!\n\n");
                }
            }

        }else{
            system("clear");
            printf("Opcao invalida!!");
        }
    }

}

void OptionsAccounts::deleteAccount(){
    int escolha;

    printf("Exclusao de conta\n");
    int index=searchCpf();
    system("clear");
    if (index>=0){
        printf("Voce tem certeza que deseja remover conta de %s ?\n1-Sim | 2- Nao - ",accounts[index]->nome);
        scanf("%d",&escolha);
        if(escolha==1){
            if (accounts.size()>0){
                accounts.erase(accounts.begin() + index);
                system("clear");
                printf("Conta foi removida com sucesso!\n\n");
            }
        }else if (escolha==2){
            system("clear");
            printf("Operacao Cancelada!\n\n");
        }else {
            system("clear");
            printf("Opcao invalida!\n\n");
        }
    }
}

void OptionsAccounts::managerOption(){
    char pin[]="3214189";
    char tipoConta[9];
    system("clear");

    printf("Para verificar todos os clientes, digite senha de Gerente: ");
    char *password=getpass("");

    system("clear");
    if(strcmp(pin,password)==0){
        if(accounts.size()<=0){
            printf("Nao ha clientes cadastrados!\n\n");
        }else{
            for(size_t i=0;i<accounts.size();i++){
                if(accounts[i]->typeAccount==1){
                    strcpy(tipoConta,"Poupanca");
                }else if (accounts[i]->typeAccount==2) {
                    strcpy(tipoConta,"Corrente");
                }else{
                    strcpy(tipoConta,"Juridica");
                }
                printf("-----Conta %s-----\n",tipoConta);
                printf("Nome: %s\nIdade: %d\nCPF: %ld\nNascimento: %d\nEmail: %s\nSaldo: R$ %ld\n",accounts[i]->nome,accounts[i]->idade,accounts[i]->cpf,accounts[i]->nascimento,accounts[i]->email,accounts[i]->saldo);
                printf("------------------------\n");
            }
        }
    }else {
        printf("Senha invalida!\n\n");
    }

}
