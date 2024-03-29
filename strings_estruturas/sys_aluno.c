#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[120];
//    int idade;
//    float renda;
};

void pedir_dados(struct aluno *novoAluno);
void listar_alunos(struct aluno *alunos, int qtdAlunos);
void atualizar_aluno(struct aluno *alunos, int qtdAlunos);
void remover_aluno(struct aluno *alunos, int *qtdAlunos);
void buscar_aluno_matricula(struct aluno *alunos, int qtdAlunos, int mat);
void buscar_aluno_nome(struct aluno *alunos, int qtdAlunos, char *nome);

int main() {
    struct aluno *alunos;
    alunos = (struct aluno *)malloc(10 * sizeof(struct aluno));
    int qtdAlunos = 0;

    char menu[] = "\t\t>>> SysAlunos <<<\n1 - Adicionar aluno\n2 - Listar alunos\n3 - Atualizar aluno\n4 - Remover aluno\n5 - Buscar aluno pela matricula\n6 - Buscar aluno pelo nome\n0 - sair\n\ndigite aqui ->: ";
    int opcao;
    printf("%s", menu);
    scanf("%d", &opcao);

    while (opcao > 0) {
        if (opcao == 1) {
            printf("\nCadastrar novo aluno!\n");
            struct aluno novoAluno;
            pedir_dados(&novoAluno);
            alunos[qtdAlunos] = novoAluno;
            qtdAlunos++;
            printf("\nNovo aluno cadastrado com sucesso!\n");
        } else if (opcao == 2) {
            printf("\nListar alunos!\n");
            listar_alunos(alunos, qtdAlunos);
        } else if (opcao == 3) {
            printf("\nAtualizar aluno!\n");
			atualizar_aluno(alunos, qtdAlunos);
		} else if (opcao == 4) {
            printf("\nRemover aluno!\n");
            remover_aluno(alunos, &qtdAlunos);
        } else if (opcao == 5) {
            printf("\nBuscar aluno pela matricula!\n");
            printf("Digite a matricula do aluno: ");
            int mat;
            scanf("%d", &mat);

            buscar_aluno_matricula(alunos, qtdAlunos, mat);
        } else if (opcao == 6) {
            printf("\nBuscar aluno pelo nome\n");
            printf("Digite o nome do aluno: ");
            char nome[120];
            scanf(" %120[^\n]", &nome);

            buscar_aluno_nome(alunos, qtdAlunos, nome);  
        }

        printf("\n%s", menu);
        scanf("%d", &opcao);
    }
    
    return 0;
}

void pedir_dados(struct aluno *novoAluno) {
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

void listar_alunos(struct aluno *alunos, int qtdAlunos) {	
	int i;
	if (qtdAlunos >= 1) {
        printf("\nLista de alunos cadastrados:\n");
		for (i = 0; i < qtdAlunos; i++) {
			printf("Matricula: %d - Nome: %s\n", alunos[i].matricula, alunos[i].nome);	
    	}
    	printf("----------------------------\n");	
	} else {
        printf("Sem alunos para exibir!");
    }
}

void atualizar_aluno(struct aluno *alunos, int qtdAlunos) {
    int mat_user;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat_user);

	int i;
    for (i = 0; i < qtdAlunos; i++) {
        if (mat_user == alunos[i].matricula) {
            printf("\nAluno encontrado!\n");
            printf("Digite os novos dados do aluno...\n");
            pedir_dados(&alunos[i]);
            break;
        } else {
            printf("Aluno inexistente\n");
        }
    }

}

void remover_aluno(struct aluno *alunos, int *qtdAlunos) {
    int mat_user;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat_user);
	
    int i;
    for (i = 0; i < qtdAlunos; i++) {
        if (mat_user == alunos[i].matricula) {
            printf("Aluno encontrado!\n");
            alunos[i] = alunos[i + 1];
            printf("\nAluno removido com sucesso!\n");
            (*qtdAlunos --);
            break;
        }
    }
    
    printf("Aluno inexistente\n");
}

void buscar_aluno_matricula(struct aluno *alunos, int qtdAlunos, int mat) {
    int i;
    for (i = 0 ; i < qtdAlunos; i++) {
        if (mat == alunos[i].matricula) {
            printf("Aluno encontrado!\n");
            printf("%d - %s", alunos[i].matricula, alunos[i].nome);
            break;
        } else {
            printf("\nAluno inexistente!");
        }
    }
}

void buscar_aluno_nome(struct aluno *alunos, int qtdAlunos, char *nome) {
    int i;
    for (i = 0; i < qtdAlunos; i++) {
        if (strcmp(nome, alunos[i].nome) == 0) {
            printf("\nAluno encontrado!\n");
            printf("%d - %s", alunos[i].matricula, alunos[i].nome);
            break;
        } else {
            printf("\nAluno inexistente!");
        }
    }
}
