#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo uma constante para a quantidade máxima de alunos aceitos no sistema
#define MAX_ALUNOS 50

// Definindo a struct que armazenará os dados dos alunos
typedef struct
{
    char nome[50];
    float notas[4];
    int ativo;
} Aluno;

// Array para armazenamento de notas e nomes dos alunos
Aluno alunos[MAX_ALUNOS];

// definindo os protótipos do Menu e dos "métodos" do Menu
void menu();
void cadastrar();
void remover();
void reprovados();
void pesquisar();
void listar();

// Método main
int main() {
    menu();
    return 0;
}

// Desenvolvendo o Menu do sistema
void menu() {


    int op;
    //printf("\nSistema De Controle Escolar - SCE\n");
    do {
        system("clear"); // For Linux
        //system("cls"); // For Windows
        printf("\n1 - Cadastrar Aluno \n2 - Remover Aluno");
        printf("\n3 - Alunos Reprovados \n4 - Pesquisar Aluno");
        printf("\n5 - Listar Alunos \n\n0 - Sair \n");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
            case 1:
                cadastrar();
                break;
            case 2:
                remover();
                break;
            case 3:
                reprovados();
                break;
            case 4:
                pesquisar();
                break;
            case 5:
                listar();
                break;

        }
        //getchar();
    } while (op != 0);
}

// Métodos Menu
void cadastrar() {
    char nome[50];
    float notas[4];

    int op;
    do {
        system("clear"); // For Linux
        //system("cls"); // For Windows
        printf("\nNome: ");
        fgets(nome, sizeof(nome), stdin);
        printf("\n1º Bimestre: ");
        scanf("%f", &notas[0]);
        printf("\n2º Bimestre: ");
        scanf("%f", &notas[1]);
        printf("\n3º Bimestre: ");
        scanf("%f", &notas[2]);
        printf("\n4º Bimestre: ");
        scanf("%f", &notas[3]);


        for (int i = 0; i < MAX_ALUNOS; ++i)
        {
            if ( alunos[i].ativo == 0 )
            {
                alunos[i].notas[0] = notas[0];
                alunos[i].notas[1] = notas[1];
                alunos[i].notas[2] = notas[2];
                alunos[i].notas[3] = notas[3];
                strcpy(alunos[i].nome, nome);
                alunos[i].ativo = 1;
                break;
            }
        }

        printf("\n1 - Continuar \n0 - Sair \n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}

void remover() {
    int matricula;
    listar();
    printf("\nDigite a matrícula do aluno a ser removido: ");
    scanf("%d", &matricula);
    --matricula;
    alunos[matricula].ativo = 0;
    printf("\nAluno excluido com sucesso.  \n");
    getchar();

}

void reprovados() {

    system("clear"); // For Linux
    //system("cls"); // For Windows
    float media;

    printf("\nLISTA DE ALUNOS REPROVADOS\n");
    for (int i = 0; i < MAX_ALUNOS; ++i)
    {
        if (alunos[i].ativo == 1)
        {
            media = 0;
            media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3]) / 4;

            if (media < 7.0)
            {
                printf("Matrícula: %d\n", i+1);
                printf("Nome: %s\n", alunos[i].nome);
                printf("1º Bimestre %0.2f\n", alunos[i].notas[0]);
                printf("2º Bimestre %0.2f\n", alunos[i].notas[1]);
                printf("3º Bimestre %0.2f\n", alunos[i].notas[2]);
                printf("4º Bimestre %0.2f\n", alunos[i].notas[3]);
                printf("\n---------------------------------------\n");
            }

        }
    }
    getchar();
}

void pesquisar() {
    char nome[50];
    int op;
    do {
        system("clear"); // For Linux
        //system("cls"); // For Windows
        printf("\nDigite o nome do aluno a ser pesquisado:\n ");
        fgets(nome,sizeof(nome),stdin);

        for (int i = 0; i < MAX_ALUNOS; ++i)
        {

            if (strstr(alunos[i].nome, nome) != NULL )
            {
                printf("Matrícula: %d\n", i+1);
                printf("Nome: %s\n", alunos[i].nome);
                printf("1º Bimestre %0.2f\n", alunos[i].notas[0]);
                printf("2º Bimestre %0.2f\n", alunos[i].notas[1]);
                printf("3º Bimestre %0.2f\n", alunos[i].notas[2]);
                printf("4º Bimestre %0.2f\n", alunos[i].notas[3]);
                printf("\n---------------------------------------\n");
            }
        }
        printf("\n1 - Continuar \n0 - Sair \n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);


}

void listar()
{
    system("clear"); // For Linux
    //system("cls"); // For Windows

    printf("\nLISTA DE ALUNOS\n");
    for (int i = 0; i < MAX_ALUNOS; ++i)
    {
        if (alunos[i].ativo == 1)
        {
            printf("Matrícula: %d\n", i+1);
            printf("Nome: %s\n", alunos[i].nome);
            printf("1º Bimestre %0.2f\n", alunos[i].notas[0]);
            printf("2º Bimestre %0.2f\n", alunos[i].notas[1]);
            printf("3º Bimestre %0.2f\n", alunos[i].notas[2]);
            printf("4º Bimestre %0.2f\n", alunos[i].notas[3]);
            printf("\n---------------------------------------\n");

        }
    }
    getchar();
}