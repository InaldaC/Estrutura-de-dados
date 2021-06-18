#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>


typedef struct {
	int id_equipe;
    char nome[100];
}Equipe;
/**
PROTOTIPOS DAS FUNCOES DE EQUIPE
*/
FILE *abrirArquivoEquipe(char modo[3]);
int geradorIdEquipe();
void adicionarEquipe();
void imprimirEquipe();


int main(int argc, char *argv[]) {
	adicionarEquipe();
	return 0;
}
/*DESENVOLVIMENTO DAS FUNÇÕES DA EQUIPE*/
//FUNCAO QUE ABRE ARQUIVO DE EQUIPES
FILE *abrirArquivoEquipe(char modo[3]){
    FILE *file;
    file = fopen("Equipes.dat", modo);
    if (file==NULL){
        modo = "w";
        file = fopen("Equipes.dat", modo);
    }
    return file;
}


//FUNÇÃO QUE GERA ID DE EQUIPES
int geradorIdEquipe(){
    int id=0;
    Equipe eq;
    FILE *file = abrirArquivoEquipe("rb");
    while(fread(&eq, sizeof(eq),1,file)){
        if(eq.id_equipe>id) id=eq.id_equipe;
    }
    fclose(file);
    return (id+1);
}


//Funcao para cadastrar Equipe
void adicionarEquipe(){
    int tam;
    printf("\n\t\t\t\t\tInforme o número de equipes que deseja adicionar:");
    scanf("%d",&tam);

    Equipe eq[tam];
		int i;
    for(i=0;i<tam; i++){
        printf("\n\t\t\t\t\tCadastrando a equipd: {%d}",i+1);
        printf("\n\t\t\t\t\t-------------------------------");
        setbuf(stdin,NULL);
        eq[i].id_equipe = geradorIdEquipe();
        setbuf(stdin, NULL);
        printf("\n\t\t\t\t\tNome da equipe: ");
        gets(eq[i].nome);
        //

        //Para escrever os dados de cada equipe no arquivo
        FILE *file = abrirArquivoEquipe("ab");
        fwrite(&eq[i],sizeof(eq[i]),1,file);
        fclose(file);
        printf("\n\n");
    }
    printf("\n\t\t\t\t\tCadastro feito com sucesso!!!\n\n");
}

//FUNÇCÃO QUE IMPRIME EQUIPES
void imprimirEquipe(){
    Equipe eq;
    FILE *file = abrirArquivoEquipe("r+b");
    while(fread(&eq, sizeof(eq),1,file)==1){
        printf("\n\t\t\t\t\tId Id Equipe: %d",eq.id_equipe);
        printf("\n\t\t\t\t\tNome da equipe: %s", eq.nome);
        printf("\n\n");
    }
    fclose(file);
}
