#include "sys_aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void exibeMenu() {
    char menu[] = "\t\t\t>>> SysAlunos <<<\n1 - Adicionar aluno\n2 - Listar alunos\n3 - Atualizar aluno\n4 - Remover aluno\n5 - Buscar aluno pela matricula\n6 - Buscar aluno pelo nome\n0 - sair\n\ndigite aqui ->: ";
    printf("%s", menu);
}

void pedeDados(Aluno *novoAluno)
{
    printf("Matricula: ");
    scanf("%d", &novoAluno->matricula);

    printf("Nome: ");
    scanf(" %120[^\n]", &novoAluno->nome);

    //    printf("Idade: ");
    //    scanf("%d", &novoAluno->idade);
    //
    //    printf("Renda: ");
    //    scanf("%f", &novoAluno->renda);
}

void listaAlunos(Aluno *alunos, int qtdAlunos)
{
    int i;
    if (qtdAlunos >= 1)
    {
        printf("\nLista de alunos cadastrados:\n");
        for (i = 0; i < qtdAlunos; i++)
        {
            printf("Matricula: %d - Nome: %s\n", alunos[i].matricula, alunos[i].nome);
        }
        printf("\t\t\t----------------------\n");
    }
    else
    {
        printf("Sem alunos para exibir!");
    }
}

void atualizaAluno(Aluno *alunos, int qtdAlunos)
{
    int mat_user;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat_user);
    bool alunoEncontrado = false;

    int i;
    for (i = 0; i < qtdAlunos; i++)
    {
        if (mat_user == alunos[i].matricula)
        {
            printf("Digite os novos dados do aluno:\n");
            pedeDados(&alunos[i]);
            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com a matricula '%d'.\n", mat_user);
    }
}

void removeAluno(Aluno *alunos, int *qtdAlunos, int mat)
{   
    bool alunoEncontrado = false;

    int i;
    for (i = 0; i < *qtdAlunos; i++)
    {
        if (mat == alunos[i].matricula)
        {
            // Movendo os elementos da matriz para preencher o espaço do aluno removido
            for (int j = i; j < *qtdAlunos - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }

            (*qtdAlunos)--;
            printf("\nAluno removido com sucesso!\n");
            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com a matricula '%d'.\n", mat);
    }
}


void buscaAlunoMatricula(Aluno *alunos, int qtdAlunos, int mat)
{
    int i;
    bool alunoEncontrado = false;

    printf("\nResultados da busca pela matricula '%d':\n", mat);
    for (i = 0; i < qtdAlunos; i++)
    {
        if (mat == alunos[i].matricula)
        {
            printf("Matricula: %d - Nome: %s\n", alunos[i].matricula, alunos[i].nome);
            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com  a matricula '%d'.\n", mat);
    }
}

void buscaAlunoParteNome(Aluno *alunos, int qtdAlunos, char *nome) {
    int i;
    bool alunoEncontrado = false;

    printf("\nResultados da busca por '%s':\n", nome);

    for (i = 0; i < qtdAlunos; i++) {
        if (strstr(alunos[i].nome, nome) != NULL) {
            printf("Matricula: %d - Nome: %s\n", alunos[i].matricula, alunos[i].nome);
            alunoEncontrado = true;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com '%s' no nome.\n", nome);
    }
}