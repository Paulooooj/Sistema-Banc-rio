#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
struct pixx
{
    char nome[5][40];
    char chave[5][15];
};
struct pixx cartao;
void transferencia();
void minhas_chaves();
void favoritos();
bool flag = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
char meucpf[12], meuemail[40], meutelefone[12];
int chavealeatoria, dfavoritos, cfavoritos;
int main() {
    int n;

    printf("\n -- Pix --\n");
    printf("\n1-Transferir  \n2-Minhas Chaves\n3-Favoritos\n4-Sair do menu pix\n");
    scanf("%d", &n);

    switch(n){
        case 1:
        transferencia();
        break;
        case 2:
        minhas_chaves();
        break;
        case 3:
        favoritos();
        break;
        case 5:
        //chamar a função do menu
        default:
        printf("Escolha nao existente, tentar de novo.\n");
        break;
    }
    return 0;
}
void transferencia(){
    system("cls");
    char nome[35], mensagem[25], cpf[12], chavea[12], email[40], celular[12];
    int w1 = 0, escolha1, saldo, vt, cont = 0, escolhasfavoritos;
    saldo = 400;  // vai ter ligação com a parte do João     
    while(w1 != 2){
        printf("Saldo disponível em sua conta R$ %d\n", saldo);
        printf("Qual o valor da transferência ? R$ ");
        scanf("%d", &vt);
        system("cls");
        
        if(vt < saldo && vt > 0){
            setbuf(stdin, NULL);
            printf("Qual o nome da pessoa que vai receber o pix: ");
            fgets( nome, 40, stdin);
            setbuf(stdin, NULL);
            printf("Escreva uma mensagem: ");
            fgets( mensagem, 50, stdin);
            printf("\n Qual o tipo de Chave? Pix \n1-E-mail \n2-CPF/CNPJ \n3-chave pix \n4-Número celular\n5-Favoritos \n");
            scanf("%d", &escolha1);
            
                    
            switch(escolha1){
                case 1:
                    setbuf(stdin, NULL);
                    printf("Informe o e-mail: ");
                    fgets( email, 100, stdin);
                    printf("\n\nTransferência realizada com sucesso.\n");// usar todos dessa forma para gerar o comprovante.
                    printf("%s", mensagem);
                    printf("Enviadado pra %s", nome);
                    printf("Chave pix %s", email);
                    printf("No valor de R$ %d reais.", vt);
                    break;

                case 2:
                    setbuf(stdin, NULL);
                    printf("Informe o CPF/CNPJ: ");
                    fgets( cpf, 12, stdin);
                    printf("\n\nTransferência realizada com sucesso.\n");// usar todos dessa forma para gerar o comprovante.
                    printf("%s", mensagem);
                    printf("Enviadado pra %s", nome);
                    printf("Chave pix %s", cpf);
                    printf("No valor de R$ %d reais.", vt);
                    break;
            
                case 3:
                    setbuf(stdin, NULL);
                    printf("Informe a chave pix: ");
                    fgets( chavea, 12, stdin);
                    printf("\n\nTransferência realizada com sucesso.\n");// usar todos dessa forma para gerar o comprovante.
                    printf("%s", mensagem);
                    printf("Enviadado pra %s", nome);
                    printf("Chave pix %s", chavea);
                    printf("No valor de R$ %d reais.", vt);
                    break;

                case 4:
                    setbuf(stdin, NULL);
                    printf("Informe O número do celular com o dd +55 ");
                    fgets( celular, 12, stdin);
                    printf("\n\nTransferência realizada com sucesso.\n");// usar todos dessa forma para gerar o comprovante.
                    printf("%s", mensagem);
                    printf("Enviadado pra %s", nome);
                    printf("Chave pix %s", celular);
                    printf("No valor de R$ %d reais.", vt);
                    break;

                case 5:
                    if(flag5){
                    printf("\n -- Favoritos --\n\n");
                    for(cont = 0; cont < dfavoritos; cont ++){
                    printf("%d-%s",cont + 1, cartao.nome[cont]);
                    printf("%s\n\n", cartao.chave[cont]);
                    }
                    printf("Escolha um contato para fazer a transferência: ");
                    scanf("%d", &escolhasfavoritos);
                    
                    switch(escolhasfavoritos){
                        case 1:
                        printf("\n\nTransferência realizada com sucesso.\n");
                        printf("%s", mensagem);
                        printf("Envidado para %s",cartao.nome[0]);
                        printf("Chave pix %s\n", cartao.chave[0]);
                        break;
                        case 2: 
                        printf("%s",cartao.nome[1]);
                        printf("%s\n", cartao.chave[1]);
                        break;
                        case 3:
                        printf("%s", cartao.nome[2]);
                        printf("%s\n", cartao.chave[2]);
                        break;
                        case 4:
                        printf("%%s",cartao.nome[3]);
                        printf("%s\n", cartao.chave[3]);
                        break;
                        case 5:
                        printf("%%s",cartao.nome[4]);
                        printf("%s\n", cartao.chave[4]);
                        break;
                    }
                    }else{
                        printf("Nenhum contanto adicionado aos favoritos");
                    }
                    break;

                    default:
                    printf("Informe uma opção válida.");
                    break;
            }
                    // colocar a opção de escrever alguma mensagem e também de gerar um comprovante 
                    // se tiver como enviar esse comprovante para o email escolhido
        printf("\n-------------------------------------------------------------------------------------------------------------------------");
        printf("\n1-Para fazer um nova trasnferência\n2-Se não\n");
        scanf("%d", &w1);
        system("cls");
        if(w1 == 2){
            main();
        }
            
        }   
        
    } w1 = 0;// final de transferências
return;
}
void minhas_chaves(){
    system("cls");
    int w2, escolha2, escolha3, chavealeatoria;
    while(w2 != 2){
        printf("\n1-Para cadastrar uma nova chave pix \n2-Chaves Cadrastadas \n");
        scanf("%d", &escolha2);

        if(escolha2 == 1){
            system("cls");
            printf("\nÉ permitido cadastrar apenas uma chave pix para cada tipo");
            printf("\nQual o tipo de Chave deseja cadastrar ? Pix \n1-E-mail \n2-CPF/CNPJ \n3-Número telfone \n4-Gerar uma chave automática \n");
            scanf("%d", &escolha3);

            switch(escolha3){
                case 1:
                    setbuf(stdin, NULL);
                    printf("Informe o e-mail: ");
                    fgets( meuemail, 40, stdin);
                    printf("Email %scadastrado com sucesso.\n", meuemail);
                    flag = true;
                    break;

                case 2:
                    setbuf(stdin, NULL);
                    printf("Informe o CPF/CNPJ: ");
                    fgets( meucpf, 12, stdin);
                    printf("Chave %scadastrada com sucesso.\n", meucpf);
                    flag2 = true;
                    break;
                
                case 3:
                    setbuf(stdin, NULL);
                    printf("Informe o número de telefone com dd +55 ");
                    fgets( meutelefone, 12, stdin);
                    printf("Chave %scadastrada com sucesso.\n", meutelefone);
                    flag4 = true;
                    break;
                
                case 4:
                    if(chavealeatoria == 0){
                    chavealeatoria = 100000 + rand() %10000000000000;
                    printf("Chave %dcadastrada com sucesso.\n", chavealeatoria);
                    flag3 = true;
                }
                break;
            }
                //printf("%s", me);
        }
        if(escolha2 == 2){
            if(flag2){// alterar a parte de comparação
                printf("%s\n", meucpf);
            }if(flag3){
                printf("%d\n", chavealeatoria);
            }if(flag){// não é uma comparação muito eficiente;
                printf("%s\n", meuemail);
            }if(flag4){
                printf("%s\n", meutelefone);
            }if(flag == false && flag2 == false && flag3 == false && flag4 == false){
                printf("Não tem nenhuma chave cadastrada!!\n"); 
            }
            }
            printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n1-Para continuar em minhas chaves\n2-Se não\n");
            scanf("%d", &w2);
            if(w2 == 2){
                main ();
            }
            system("cls");
    }w2 = 0;
    
return;
}
void favoritos(){
    system("cls");
    int favoritos, w4, cont;
    while(w4 != 2){
        system("cls");
        printf("No máximo pode ser adicionados 5 contatos aos favoritos.\n");
        printf("Informe quantos contatos vai adicionar aos favoritos: ");
        scanf("%d", &favoritos);

        dfavoritos = dfavoritos + favoritos;
        for(cont = cfavoritos; cont < dfavoritos; cont ++){
                setbuf(stdin, NULL);
                printf("Qual o nome: ");
                fgets( cartao.nome[cont], 300, stdin);
                printf("Qual a chave pix: ");
                scanf("%s",&cartao.chave[cont]);
                flag5 = true;

        }cfavoritos = cfavoritos + favoritos;
            printf("Contatos adicionados ao favoritos com sucesso.\n");    
            printf("\n------------------------------------------------------------------------------------------------------\n");
            printf("\n1-Para cadastrar um novo contato\n2-Se não\n");
            scanf("%d", &w4);
            if(w4 == 2){
                system("cls");
                main();
            }
            
    }
            
return;
}
