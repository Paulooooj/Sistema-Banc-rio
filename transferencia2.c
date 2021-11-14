#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

void ted();
void informacoes();
struct dados_cliente
{
    char nome[41];
    char conta[41];
    
};

struct dados_cliente cliente[10];
    
    
int main(){
        int ted1;
        printf("1-Para fazer TED\n2-Para saber sobre TED:\n");
        scanf("%d", &ted1);
        
        switch(ted1){
            case 1:
            ted();
            break;
            case 2:
            informacoes();
            break;
            case 3:
            printf("Opção invalida.");
            break;
        }
    return 0;
    }   
void ted() {
    bool transferencia = false, flag = true;
    int i, n, n2, ct, valort = 0, sair;
    char nome2[10], nome3[30], conta[6];
    
    for(i = 0; i < 3; i++){
        setbuf(stdin, NULL);
        printf("Qual o nome: ");
        fgets(cliente[i].nome, 30, stdin);
        setbuf(stdin, NULL);
        printf("Qual a chave pix: ");
        fgets(cliente[i].conta, 60, stdin);
    }
    
    //a parte logo abaixo vai receber o nome e o valor para fazer a transferencia
    while(flag){
        printf("Informe o valor a ser transferido: "); 
        scanf("%d", &valort);
        setbuf(stdin, NULL);
        printf("Informe o nome:");
        fgets(nome2, 10, stdin);
    

        // for de comparação atráves do nome para saber se a pessoa tem conta no banco
        for(i = 0; i < 3; i++){
            if(strncmp(cliente[i].nome, nome2, 3) == 0){
                // informar todas as pessoas com esse nome que tem conta no banco
                printf("%d-%s",i +1, cliente[i].nome);
                printf("%s\n",cliente[i].conta);
                transferencia = true;
            }
        }  
        if(transferencia){
            // usando flag para se o nome informado tiver no cadastro cair nessa opção, e finalizar a transferencia
            printf("Digite o numero da pessoa para quem deseja fazer a transfencia:\n");
            scanf("%d", &n);
            system("cls");
            printf("Cliente %s", cliente[n-1].nome);
            printf("Conta %s\n", cliente[n-1].conta);
            printf("Para confirmar a transferencia digite 1 para cancelar digite 2:");
            scanf("%d", &ct);
        
            if(ct == 1){
                // finalizar a transferencia e gerar o comprovante 
                printf("Confirme sua senha de quatro digitos:\n");
                //while(){
                //printf("Senha digita errada, digite novamente:\n");
                //}
            
            
                //colocar um while aqui para fazer com que a pessoa digite a senha até ele acertar

                printf("Transferencia realizada com sucesso.\n");
                printf("Enviada para %s",cliente[n-1].nome);
                printf("Numero da conta %s",cliente[n-1].conta); 
                printf("No valor de %d\n", valort);
                printf("Obrigado por usar o ETI.");

            }else if(ct == 2){
                system("cls");
                main();
            }
        
        }else{
            // caso a pesso que vai receber não tenha conta no banco
            system("cls");
            printf("Essa pessoa nao tem conta no ETI\n");
            //while aqui
            printf("Para fazer a transferencia:\n");
            setbuf(stdin, NULL);
            printf("Informe o nome do cliente:\n");
            fgets(nome3, 30, stdin);
            setbuf(stdin, NULL);
            printf("Informe o numero da conta:\n");
            fgets(conta, 6, stdin);
            system("cls");
            printf("Dados do cliente:\n");
                for(i = 1; i < 2; i++){
                    printf("%s", nome3);
                    printf("%s\n", conta);
                }
            printf("Para confirmar a transferencia digite 1 para cancelar digite 2:");
            scanf("%d", &n2);
                // em alguma parte informar que vai ser combrado uma taxa pois que irá receber a trasnferencia não tem conta no banco, uma taxa pequena
                if(n2 == 1) {
                    printf("Informe a senha de 4 digitos:");
                    //while(){
                        //printf("Senha digita errada, digite novamente:\n");
                    //}
            
                    //colocar um while aqui para fazer com que a pessoa digite a senha até ele acertar
                    printf("\nTransferencia realizada com sucesso.\n");
                    printf("Enviada para %s",nome3);
                    printf("Numero da conta %s",conta); 
                    printf("No valor de %d\n", valort);
                    printf("Obrigado por usar o ETI.");
                }else if(n2 = 2){
                    system("cls");
                    main();
                }
        
        }
    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n1-Nova transferencia\n2-Voltar menu transferencia\n");
    scanf("%d", &sair);
    
        while(sair != 1 && sair != 2){
            system("cls");
            printf("\nEscolha invalida digitar novamente");
            printf("\n1-Nova transferencia\n2-Voltar menu transferencia\n");
            scanf("%d", &sair);

        }if(sair == 1){
            system("cls");
        }else if(sair == 2){
            system("cls");
            main();
        }
    }


return;
}
void informacoes(){
    int inf;
    printf("Entre contas do banco nao sera cobrado nenhum valor.\n");
    printf("Transferencia para outros bancos sera combrado a taxa de 0.0025\n");
    printf("De 30 a 60 minutos para cair o valor da transferencia\n");
    printf("1-voltar para o menu\n");
    scanf("%d", &inf);
    while(inf != 1){
        printf("1-voltar para o menu:\n");
        scanf("%d", &inf);
    }
    if(inf == 1){
        system("cls");
        main();
    }
}