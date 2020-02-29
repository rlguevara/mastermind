//Algoritmos y Programacion 2
//Rosa Linda Guevara

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*INICIALIZA TODOS LOS ARREGLOS*/
void inicializacion(char cod_jugador[], char fichas[], char otro[], int tam){
int i=0;	
		for(i=0; i<tam; i++){ 
			cod_jugador[i]='\0';
			fichas[i]='\0';
			otro[i]='\0';
	}
}

/*CODIGO SECRETO CON LETRAS REPETIDAS*/
void Codigo_secreto_repetidos(char codigo[],char num_colores,char colores[],int tam){
int i,randomnumero;		
		for(i=0; i<tam; i++){
			randomnumero= rand() % (num_colores);
			codigo[i]=colores[randomnumero];
		}
}

/*VALIDACION DE LAS PISTAS*/
void validacion_con_repeticion(char codigo[], char cod_jugador[], char fichas[],char aux[], int tam){
int i,j,conttt=0,cont=0,k=0;
char cod_jugador2[tam], codigo2[tam];
	
	//Variables auxiliares
	for(i=0; i<tam; i++){
		codigo2[i]=codigo[i];
	}
	
	for(i=0; i<tam; i++){
		cod_jugador2[i]=cod_jugador[i];
	}
			
		//Funcion de las fichas negras
		for(i=0; i<tam; i++){
			if(cod_jugador[i]==codigo[i]){
							codigo2[i]='1';
							cod_jugador2[i]='0';
							conttt++;
					}
		}
		
		//Auxiliar
		for(i=0; i<tam; i++)
			aux[i]=cod_jugador2[i];
			
		//Funcion de las fichas blancas
		for(i=0; i<tam; i++){
				for(j=0; j<tam; j++){
					while((codigo2[j]=='1') || (cod_jugador2[j]=='0') || (aux[j]=='@'))
						j++;
					if((cod_jugador2[i]==codigo2[j]) && (i!=j)){
						codigo2[i]='@';
						aux[i]='@';
						cont++;
						break;	
					}
			}
		}
		
		//Se rellena el arreglo con N y B
		for(i=0; i<conttt; i++){
				fichas[i]='N';
		}
		
		while(k!=cont){
			fichas[++conttt]='B';
			k++;
			}
			
		//funcion de las vacias
		for(i=0; i<tam; i++){
			if((fichas[i]!='N') && (fichas[i]!='B'))
				fichas[i]='O';
		}

}
/*MUESTRA PISTAS CON COLORES REPETIDOS*/
void arreglo_fichas_repetidas(char fichas[], char otro[], int tam){
int i=0,j=0,m;
char auxiliar[tam];
		//Random de posiciones
		for(i=0; i<tam; i++){
			m=rand() % tam;	
		if(i>0){  
		for(j=0; j<i; j++)     
          if(m==auxiliar[j]){
             m=rand() % tam;
             j=-1;                         
          }
    }
    auxiliar[i]=m;
    otro[m]=fichas[i];
}
		//Muestra el arreglo ya con el random 	
		printf("\n");
		printf("Pistas:");
		for(i=0; i<tam; i++)
			printf("%c", otro[i]);
		printf("\n");	
}

int main(){
int tam,intentos,num_colores,i,repeat=0,aux2=1,letra;
char codigo[tam], cod_jugador[tam], fichas[tam],otro[tam],aux[tam];
char colores[8]={'A','V','R','M','N','B','G','P'};
srand(time(NULL));

	//Inicializa codigo secreto
	for(i=0; i<tam; i++)
		codigo[i]='\0';
		
	printf("*************************M A S T E R M I N D************************************");	
	printf("\n");
	printf("B I E N V E N I D O!!!");
	printf("\n");
	printf("\n");
	printf("Mastermind es un juego de estrategia,\n"); 
	printf("en el que tienes que adivinar un codigo secreto (*****)\n");
	printf("\n");
	printf("Para jugar se debe ingresar un codigo del jugador\n");
	printf("Para esto tendra que elegir el tama;o del codigo\n");
	printf("El numero de colores para el codigo\n");
	printf("Y la cantidad de veces que quiera intentarlo\n");
	printf("Si logra adivinar el codigo secreto, usted habra ganado el juego!!\n");
	printf("\n");
	printf("\n");
	printf("Los colores disponibles para el juego son:\n");
	printf("A: Amarillo\n");
	printf("V: Verde\n");
	printf("R: Rojo\n");
	printf("M: Morado\n");
	printf("N: Naranja\n");
	printf("B: Blanco\n");
	printf("G: Gris\n");
	printf("P: Plateado\n");
	printf("\n");
	printf("\n");
	printf("Listo para jugar...?");
	printf("\n");
	printf("\n");
	printf("Presione ENTER para continuar\n");
	getchar();
	system("clear");


	//Comienza el menu
	printf("Indique el tama;o del codigo secreto (4,5 o 6):");
	scanf("%d",&tam);
	printf("\n");
	printf("\n");
	
	switch (tam){	
		case 4:{
				goto numero_colores;	
			break;
			}
			case 5:{
				goto numero_colores;		
			break;		
			}
			case 6:{
				goto numero_colores;		
			break;
			}
			default:{
				printf("CARACTER NO VALIDO\n");
				printf("Vuelva a intentarlo\n");
				while((tam!=4) && (tam!=5) && (tam!=6)){
					printf("Indique el tama;o del codigo secreto (4,5 o 6):");
					scanf("%d",&tam);
				}
				}
		}
		
	numero_colores:	
	printf("Introduzca el numero de colores(4,6 o 8):");
	scanf("%d",&num_colores);
	printf("\n");
	printf("\n");
	
	switch (num_colores){	
		case 4:{
				goto intento;	
			break;
			}
			case 6:{
				goto intento;		
			break;		
			}
			case 8:{
				goto intento;		
			break;
			}
			default:
				printf("CARACTER NO VALIDO\n");
				printf("Vuelva a intentarlo\n");
				while((num_colores!=4) && (num_colores!=6) && (num_colores!=8)){
					printf("Introduzca el numero de colores(4,6 o 8):");
					scanf("%d",&num_colores);
					}
		}
		
intento:

	printf("Indique el numero de intentos (8,10 o 12):");
	scanf("%d",&intentos);
	printf("\n");
	printf("\n");
	
switch (intentos){	
					case 8:{
	
							Codigo_secreto_repetidos(codigo,num_colores,colores,tam);
							
	
	for(i=0; i<8; i++){		inicializacion(cod_jugador,fichas,otro,tam);
							repeat=0;
							
							do
							{
							printf("\nIntroduzca el codigo:");
							scanf("%s", cod_jugador);	
							
							for(i=0; i<tam; i++){
								letra=isalpha(cod_jugador[i]);
								

							if(letra==0){
								aux2=letra;
								}
							else{
								aux2=letra;
								
								}
							}
							if(aux2==0)
								printf("La cadena no es valido\n");
								} while(aux2==0);
							
							validacion_con_repeticion(codigo,cod_jugador,fichas,aux,tam);
							arreglo_fichas_repetidas(fichas,otro,tam);
							
							for(i=0; i<tam; i++){
									if(otro[i]=='N'){
										repeat++;
										}
							}
								
							if(repeat==tam){
								printf("\nFELICIDADES!! GANO EL JUEGO :D\n");
								exit(0);}
	}						
						printf("Supero el numero de intentos :(\n");
						break;
					}
					case 10:{
								Codigo_secreto_repetidos(codigo,num_colores,colores,tam);
	
	
	for(i=0; i<10; i++){	inicializacion(cod_jugador,fichas,otro,tam);
		
							repeat=0;
							
							do{
							printf("\nIntroduzca el codigo:");
							scanf("%s", cod_jugador);	
							
							for(i=0; i<tam; i++){
								letra=isalpha(cod_jugador[i]);

							if(letra!=0){
								aux2=letra;
								}
								else{
								aux2=letra;	
								}
							}		
							if(aux2==0)
								printf("La cadena no es valido\n");}
							while(aux2==0);
							
							validacion_con_repeticion(codigo,cod_jugador,fichas,aux,tam);
							arreglo_fichas_repetidas(fichas,otro,tam);
							
							for(i=0; i<tam; i++){
									if(otro[i]=='N'){
										repeat++;
										}
							}
								
							if(repeat==tam){
								printf("\nFELICIDADES!! GANO EL JUEGO :D\n");
								exit(0);}
	}						
							printf("Supero el numero de intentos :(\n");
						break;
					}
					case 12:{
								Codigo_secreto_repetidos(codigo,num_colores,colores,tam);
	
	
	for(i=0; i<12; i++){	inicializacion(cod_jugador,fichas,otro,tam);
		
							repeat=0;
							
							do{
							printf("\nIntroduzca el codigo:");
							scanf("%s", cod_jugador);	
							
							for(i=0; i<tam; i++){
								letra=isalpha(cod_jugador[i]);

							if(letra!=0){
								aux2=letra;
								}
								else{
								aux2=letra;	
								}
							}
							if(aux2==0)
								printf("La cadena no es valido\n");}
							while(aux2==0);
	
							validacion_con_repeticion(codigo,cod_jugador,fichas,aux,tam);
							arreglo_fichas_repetidas(fichas,otro,tam);
							
							for(i=0; i<tam; i++){
									if(otro[i]=='N'){
										repeat++;
										}
							}
								
							if(repeat==tam){
								printf("\nFELICIDADES!! GANO EL JUEGO :D\n");
								exit(0);}
	}						
						printf("Supero el numero de intentos :(\n");
						break;
					}
				default:
				printf("CARACTER NO VALIDO\n");
				printf("Vuelva a intentarlo\n");
				while((intentos!=8) && (intentos!=10) && (intentos!=12)){
					printf("Indique el numero de intentos (8,10 o 12):");
					scanf("%d",&intentos);
				}
		}	


return 0;
}
