#include"optionsaccount.h"
#include"personaccount.h"

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int escolha;
    int index;
    OptionsAccounts *novaConta = new OptionsAccounts;

    do{

        printf("================================\n");
        printf("==Bem vindo ao Banco da Cidade==\n");
        printf("================================\n");

        printf("1 - Abrir uma conta\n2 - Ver informaçoes da conta\n3 - Alterar informaçoes da conta\n4 - Fazer transaçoes\n5 - Excluir uma conta\n6 - Verificar todos os clientes\n7 - Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d",&escolha);

        switch (escolha) {
            case 1:
                novaConta->newAccount();
                break;
            case 2:
                index=novaConta->searchCpf();
                if (index>=0){
                    novaConta->infoAccount(index);
                }
                break;
            case 3:
                index=novaConta->searchCpf();
                if (index>=0){
                    novaConta->changeInfoAccount(index);
                }
                break;
            case 4:
                novaConta->transactAccount();
                break;
            case 5:
                novaConta->deleteAccount();
                break;
            case 6:
                novaConta->managerOption();
                break;
            case 7:
                system("clear");
                printf("Volte Sempre!\n");
                break;
            default:
                printf("Funcao indisponivel");
                break;
        }
    }while (escolha<7);

}
