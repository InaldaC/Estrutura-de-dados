	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
typedef struct {
	char nome[30];
	int id_equipe[3];
}Equipe;


	//Arquivo para armazenar as equipes
	FILE*ficheiro(char mode[3]){
	FILE*arquivo;
		arquivo=fopen("C:\\Users\\Inalda Cumbane\\Desktop\\ESDA\\Pratica_1\\Equipas.dat",mode);
	if(arquivo==NULL){
		mode="w";
		arquivo=fopen("Equipas.dat",mode);
	}
	return arquivo;
}

//Prototipo das minhas funcoes
	registrarEquipe();
	imprimirEquipe();
	
	
		int main(){
		registrarEquipe();
		return 0;
	}
	//Registrar equipes
		void registrarEquipe(){
	    int tamanho[5];
	    printf("\t\t\t\t\t\t\(*-*)ESTA E A SESSAO CADASTRO");
	   	Equipe in;
	Equipe *peq = &in;
  	int i;
    for( i=0;i<tamanho; i++){
        printf("\n\t\t\t\t\tCadastrando a equipd: {%d}",i+1);
        printf("\n\t\t\t\t\t-------------------------------");
       setbuf(stdin,NULL);
        //peq*[i].id_equipe = geradorIdEquipe();
        setbuf(stdin, NULL);
        printf("\n\t\t\t\t\tNome da equipe: ");
        gets(peq*[i]->nome);}}

	//mesma coisa inicializar desse jeito: Equipe *peq; peq=&in
	
	

