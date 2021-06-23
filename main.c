#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


/*Nome: Inalda Mateus Cumbane
........ESda pratica1
*/


typedef struct {
	int id_equipe;
    char nome[100];
}Equipe;
	
	typedef struct {
		int dia;
		int mes;
		int ano;
	}Data;
	
	//Estrutura para jogadores
	typedef struct{
    int id_jogador;
    char nome[100];
    char apelido[15];
    int nr_golos;
    bool ativo;
    Data data_inicio;
    Data data_fim;
    int id_equipe;
}Jogador;
/**
PROTOTIPOS DAS FUNCOES 
*/
FILE *abrirArquivoEquipe(char modo[3]);
int geradorIdEquipe();
void adicionarEquipe();
void imprimirEquipe();
void registraJogadores();
void imprimirJogador();
void recuperaDados();
void meuMenu();

int main() {
      meuMenu();
//	recuperaDados();
		//imprimirJogador();
		return 0;

	}
	
	void meuMenu(){
			int a;
			//printf("\t\t\t\t\t\t*****Digite 1 para acessar ao menu e 0 para terminar o programa\n");
			//scanf("%d",a, "\n\n");

		printf("\t\t\t\t\t\t\t\t ....Bem vindo...\n\n\t\t\t\t ...O que deseja fazer?...\n\n\t\t 1. Cadastrar equipe");
		printf("\n\t\t 2. Listar as Equipes\n\t\t 3. Cadastrar jogadores numa determinada equipe"); 
		printf("\n\t\t 4. Listar os jogadores existentes \n\t\t 5. Eliminar o 3 jogador com mais golos.\n");
		int op;
		scanf("%d", &op);
		if(op==1){
			adicionarEquipe();
		}
		else if(op==2){
		
			imprimirEquipe();
		}
		else if(op==3){
			registraJogadores();
		}
		else if(op==4){
			imprimirJogador();
		}
	else if (op==5){
			eliminarJogador();
		}
		/*else(op==6){
			exit;
		}*/
	
}



//FUNCAO QUE ABRE ARQUIVO DE EQUIPES
FILE *abrirArquivoEquipe(char modo[3]){
    FILE *file;
    file = fopen("Equipes.dat", modo);
    if (file==NULL){
        modo = "rb";
        file = fopen("Equipes.dat", modo);
    }
    return file;
}

//FUNCAO QUE ABRE ARQUIVO DE jogadores
FILE *ficheiro(char modo[3]){
    FILE *arquivo;
    arquivo = fopen("Player.txt", modo);
    if (arquivo==NULL){
        modo = "w";
        arquivo = fopen("Player.txt", modo);
    }
    return arquivo;
}

//FUNÇÃO QUE GERA ID DE EQUIPES
int geradorIdEquipe(){
	
    int id=0;
    Equipe eq;
    FILE *file = abrirArquivoEquipe("rb");
    while(fread(&eq, sizeof(Equipe),1,file)){
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
    while(fread(&eq, sizeof(Equipe),1,file)==1){
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
    Jogador j;
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
         gets(joga[i].apelido);
          printf("\n\t\t\t\t\tNumero total de golos");
          setbuf(stdin, NULL);
          scanf("%d", &joga[i].nr_golos);
           printf("\n\t\t\t\t\t--Data do inicio do contrato no formato: dd//mm/YYYY");
           setbuf(stdin, NULL);
           scanf("%d %d %d", &joga[i].data_inicio.dia, &joga[i].data_inicio.mes, &joga[i].data_inicio.ano);
           setbuf(stdin, NULL);
            printf("\n\t\t\t\t\t--Data do fim do contrato no formato: dd//mm/YYYY");
            scanf("%d %d %d", &joga[i].data_fim.dia, &joga[i].data_fim.mes, &joga[i].data_fim.ano);

        //Armazenar os dados de cada equipe no arquivo
        FILE *arquivo = fopen("Player.txt","ab");
        //j = joga[i];
        fwrite(&joga[i],sizeof(Jogador),1,arquivo);
        fclose(arquivo);
        printf("\n\n");
    }
    printf("\n\t\t\t\t\tRegistrado com sucesso!!!\n\n");
}

//FUNÇCÃO QUE IMPRIME Jogadores
 void imprimirJogador(){
    Jogador joga;
    FILE *arquivo = fopen("Player.txt","r+b");
    while(fread(&joga, sizeof(Jogador),1,arquivo)==1){
        printf("\n\t\t\t\t\t Id Equipe: %d",joga.id_jogador);
        printf("\n\t\t\t\t\tNome do jogador: %s", joga.nome);
           printf("\n\t\t\t\t\tApelido do jogador: %s", joga.apelido);
              printf("\n\t\t\t\t\t Data inicio do contracto: %d/%d/%d", joga.data_inicio.dia, joga.data_inicio.mes, joga.data_inicio.ano);
                 printf("\n\t\t\t\t\tData fim do contracto:%d/%d/%d", joga.data_fim.dia, joga.data_fim.mes, joga.data_fim.ano);
                    printf("\n\t\t\t\t\tNr de golos: %d", joga.nr_golos);
        printf("\n\n");
    }
    fclose(arquivo);
}


int nrDeElementos(){
	FILE* arquivo = fopen("Player.txt","rb");
	Jogador j;
	int i=0;
	if(arquivo==NULL){
	printf("ERRRRRRRRRRRRRRRRRRRRRRO");
	return 0;
	}else{
	while(fread(&j, sizeof(Jogador), 1, arquivo)==1){
		i++;
	}
	return i;
	}
}


	void recuperaDados(Jogador *jg){
	Jogador jo;
	FILE* arquivo = fopen("Player.txt","rb");
	int i=0;
	if(arquivo ==NULL){
	printf("Errror");
	}
	else{
	//Criamos o vector com todos os elementos que estao na txt
	while(fread(&jo, sizeof(Jogador), 1, arquivo)==1){
	jg[i] = jo;
	i++;
	}
	fclose(arquivo);
	}
	}
	
		
	 void organizarDados(Jogador *jg){
	 	int aux = nrDeElementos();
	 		int k;
	int j;
	int l;
	//Organizamos de forma decrescente
	if(aux<2){
		printf("Erro");
	}
	else{
	Jogador jog[aux];
	for(k=0;k<aux;k++){
		for(j=k+1;j<aux;j++){
			if(jg[k].nr_golos < jg[j].nr_golos){
					jog[k] = jg[k];
					jg[k] = jg[j];
					jg[j] = jog[k];
			}
		}
}

	}
}
	
		void eliminarJogador(){
				int aux = nrDeElementos();
	 		Jogador jg[aux];
	 		recuperaDados(jg);
	 		organizarDados(jg);
	 			Jogador play;
	int k;
	int j;
	
		FILE* arquivo = fopen("Player.txt", "w");
	if(arquivo=NULL){
		printf("errro");
		}	 
	else{
		
	for(k=0; k<aux; k++){
	if(k!=2){
		printf("Nome: %s\n", jg[k].nome);
		play = jg[k];
	 	     fwrite(&play,sizeof(Jogador), 1, arquivo);
	}
       }
       
       fclose(arquivo);
}
}
