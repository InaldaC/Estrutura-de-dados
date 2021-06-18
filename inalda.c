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
	//Estrutura para jogadores
	typedef struct{
    int id_jogador;
    char nome[100];
    char apelido[15];
    int nr_golos;
    bool ativo;
    char data_inicio;
    char data_fim;
    int id_equipe;
}Jogador;
/**
PROTOTIPOS DAS FUNCOES DE EQUIPE
*/
FILE *abrirArquivoEquipe(char modo[3]);
int geradorIdEquipe();
void adicionarEquipe();
void imprimirEquipe();


int main(int argc, char *argv[]) {
	registraJogadores();
	return 0;
}

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
//FUNCAO QUE ABRE ARQUIVO DE jogadores
FILE *ficheiro(char modo[3]){
    FILE *arquivo;
    arquivo = fopen("Players.dat", modo);
    if (arquivo==NULL){
        modo = "w";
        arquivo = fopen("Players.dat", modo);
    }
    return arquivo;



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

int geraIdJogador(){
    int id=0;
    Jogador joga;
    FILE *arquivo = ficheiro("rb");
    while(fread(&joga, sizeof(joga),1,arquivo)){
        if(joga.id_jogador>id) id=joga.id_jogador;
    }
    fclose(arquivo);
    return (id+1);

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


//Funcao para cadastrar jogadores
void registraJogadores(){
    int num;
    printf("\n\t\t\t\t\tDigite o número de jogadores que pretende registar:");
    scanf("%d",&num);
 printf("\n\t\t\t\t\t------ESTA E A SECCAO CADASTRO--------");
    Jogador joga[num];
		int i;
    for(i=0;i<num; i++){
        printf("\n\t\t\t\t\tREGISTRANDO O JOGADOR: {%d}",i+1);
        printf("\n\t\t\t\t\t***********************\n\t\t\t\t\tDados do jogador\n");
        setbuf(stdin,NULL);
        joga[i].id_jogador = geraIdJogador();
        setbuf(stdin, NULL);
        printf("\n\t\t\t\t\tNome do jogador: ");
        gets(joga[i].nome);
         printf("\n\t\t\t\t\tApelido do jogador");
          printf("\n\t\t\t\t\tNUmero total de golos");
          scanf("%s",joga[i].nr_golos);
           printf("\n\t\t\t\t\t--Data do inicio do contrato no formato: dd//mm/YYYY");
            gets(joga[i].data_inicio);
            printf("\n\t\t\t\t\t--Data do fim do contrato no formato: dd//mm/YYYY");
            gets(joga[i].data_fim);
         
        //

        //Armazenar os dados de cada equipe no arquivo
        FILE *arquivo = ficheiro("ab");
        fwrite(&joga[i],sizeof(joga[i]),1,joga);
        fclose(arquivo);
        printf("\n\n");
    }
    printf("\n\t\t\t\t\tRegistrado com sucesso!!!\n\n");
}

//FUNÇCÃO QUE IMPRIME Jogadores
void imprimirEquipe(){
    Jogador joga;
    FILE *arquivo = ficheiro("r+b");
    while(fread(&joga, sizeof(joga),1,arquivo)==1){
        printf("\n\t\t\t\t\tId Id Equipe: %d",joga.id_jogador);
        printf("\n\t\t\t\t\tNome da equipe: %s", joga.nome);
           printf("\n\t\t\t\t\tNome da equipe: %s", joga.apelido);
              printf("\n\t\t\t\t\tNome da equipe: %s", joga.data_inicio);
                 printf("\n\t\t\t\t\tNome da equipe: %s", joga.data_fim);
                    printf("\n\t\t\t\t\tNome da equipe: %d", joga.nr_golos);
        printf("\n\n");
    }
    fclose(arquivo);
}
