#pragma once
#define SYS_ALUNO

typedef struct
{
    int matricula;
    char nome[120];
    //    int idade;
    //    float renda;
} Aluno;

void exibeMenu();
void pedeDados(Aluno *novoAluno);
void listaAlunos(Aluno *alunos, int qtdAlunos);
void atualizaAluno(Aluno *alunos, int qtdAlunos);
void removeAluno(Aluno *alunos, int *qtdAlunos, int mat);
void buscaAlunoMatricula(Aluno *alunos, int qtdAlunos, int mat);
void buscaAlunoParteNome(Aluno *alunos, int qtdAlunos, char *nome);