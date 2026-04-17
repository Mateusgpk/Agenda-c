#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int id;
    char nome[50];
    char telefone[20];
    char email[100];
} contato;

int total = 0, i;
contato *agenda = NULL;


void CarregarArquivo (){
    FILE *f = fopen("contatos.dat","rb");
    if (f==NULL){
        total=0;
        agenda=NULL;
        return;
    }
        fseek(f,0, SEEK_END);
        long tamanho= ftell(f);
        rewind(f);
        
        total=tamanho/sizeof(contato);

        agenda=malloc(total * sizeof(contato));

        fread(agenda, sizeof(contato), total, f);

        fclose(f);
}

void deletarContato(int id)
{
    int pos=id-1;
    for ( i = pos; i < total-1; i++)
    {
        agenda[i]=agenda[i+1];
        agenda[i].id=i+1;
    }
    total--;
    agenda = realloc(agenda,total*sizeof(contato));
};

void SalvarContato(){
    FILE *f = fopen("contatos.dat","wb");
    if (f==NULL){
        printf("erro ao abrir arquivo");
        return;
    }
    fwrite(agenda, sizeof(contato), total, f);
    fclose(f);
}



int main()
{   
    system("cls");

    bool trava=true;
    int op, idDel;
    char nomeBus[50], decide[10];

    CarregarArquivo();

    while (trava){
        printf("Opções para Agenda:\n");
        printf("1-Adicionar novo contato\n");
        printf("2-Pesquisar contato\n");
        printf("3-Listar todos os contatos\n");
        printf("4-Excluir contato\n");
        printf("5-Sair\n");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf("Adicionando contato\n");
            total++;
            agenda = realloc(agenda, total*sizeof(contato));
            agenda[total-1].id=total;
            printf("Nome do contato:");
            scanf(" %49[^\n]", agenda[total-1].nome);
            printf("telefone do contato:");
            scanf(" %19[^\n]", agenda[total-1].telefone);
            printf("Email do contato:");
            scanf(" %49[^\n]", agenda[total-1].email);
            SalvarContato();
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Pesquisando por contato\n");
            printf("Nome do contato:");
            scanf(" %s", nomeBus);
            for ( i = 0; i < total; i++)
            {
                if (strstr(agenda[i].nome,nomeBus)){
                    printf("id:%d\n", agenda[i].id);
                    printf("nome:%s\n",agenda[i].nome);
                    printf("telefone:%s\n",agenda[i].telefone);
                    printf("email:%s\n\n",agenda[i].email);
                }
            }
            printf("Precione Enter para voltar ao menu");
            while (getchar() != '\n');
            getchar();
            system("cls");
            
            
            break;
        case 3:
            
            system("cls");

            printf("Mostrando todos os contatos\n");
            for ( i = 0; i < total; i++)
            {
                printf("contato %d\n", i+1);
                printf("id:%d\n", agenda[i].id);
                printf("nome:%s\n",agenda[i].nome);
                printf("telefone:%s\n",agenda[i].telefone);
                printf("email:%s\n\n",agenda[i].email);
            }
            printf("Precione Enter para voltar ao menu");
            while (getchar() != '\n');
            getchar();
            system("cls");
                
            break;
        case 4:
            system("cls");
            printf("Deletando um contato\n\n");
            printf("Qual é o id do contato a ser deletado?");
            scanf(" %d", &idDel);

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if (idDel<=total && idDel>0){
                while (1)
                {
                
                    printf("certeza que quer deletar o contato de %s? (Y/N)\n", agenda[idDel-1].nome);
            
                    fgets(decide,sizeof(decide),stdin);


                        switch (decide[0])
                        {
                        case 'Y':
                        case 'y':
                            printf("contato deletado\n");

                            deletarContato(idDel);
                            SalvarContato();
                            printf("Precione Enter para voltar ao menu");
                            while (getchar() != '\n');
                            getchar();
                            system("cls");
                            goto end_loop;

                        case 'N':
                        case 'n':
                            system("cls");
                            goto end_loop;

                        default:
                            printf("Opção não existente\n");
                    }
                }
                end_loop: ;
            } else {printf("esse contato não existe ainda");}
            
            break;
        case 5:
            system("cls");
            printf("SAINDO");
            SalvarContato();
            trava=false;
            break;
        
        default:
        printf("Opção invalida\n");
            break;
        }

    }
    
    return 0;
}
