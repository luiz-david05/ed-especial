#include <stdio.h>
#include <stdlib.h>
#include "sys_aluno.h"

int main()
{
    Aluno *alunos;
    alunos = (Aluno *)malloc(10 * sizeof(Aluno));
    int qtdAlunos = 0;

    exibeMenu();
    int opcao;
    scanf("%d", &opcao);

    while (opcao > 0)
    {
        if (opcao == 1)
        {
            printf("\nCadastrar novo aluno!\n");
            Aluno novoAluno;
            pedeDados(&novoAluno);
            alunos[qtdAlunos] = novoAluno;
            qtdAlunos++;
            printf("\nNovo aluno cadastrado com sucesso!\n");
        }
        else if (opcao == 2)
        {
            printf("\nListar alunos!\n");
            listaAlunos(alunos, qtdAlunos);
        }
        else if (opcao == 3)
        {
            printf("\nAtualizar aluno!\n");
            atualizaAluno(alunos, qtdAlunos);
        }
        else if (opcao == 4)
        {   
            printf("\nRemover aluno!\n");
            int matUser;
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matUser);
            removeAluno(alunos, &qtdAlunos, matUser);
        }
        else if (opcao == 5)
        {
            printf("\nBuscar aluno pela matricula!\n");
            printf("Digite a matricula do aluno: ");
            int mat;
            scanf("%d", &mat);

            buscaAlunoMatricula(alunos, qtdAlunos, mat);
        }
        else if (opcao == 6)
        {
            printf("\nBuscar aluno por parte do nome\n");
            printf("Digite o nome do aluno: ");
            char nome[120];
            scanf(" %120[^\n]", &nome);

            buscaAlunoParteNome(alunos, qtdAlunos, nome);
        }

        exibeMenu();
        scanf("%d", &opcao);
    }

    printf("\nFIM DO PROGRAMA!\n");

    return 0;
}