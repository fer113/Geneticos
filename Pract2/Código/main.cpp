#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generaBinario();
void generaGray();
void generaReales();
void generaEnteros();


int main(int argc, char** argv) {
	srand(time(NULL)); 
	int a;
	printf("Selecciona una opción: \n");
	printf("1. Binario \n");
	printf("2. Gray \n");
	printf("3. Reales \n");
	printf("4. Enteros \n");
	scanf("%i", &a);
	switch (a) {
		case 1:
  			generaBinario();
  			break;
		case 2:
			generaGray();
			break;
		case 3:
			generaReales();
			break;
		case 4:
			generaEnteros();
			break;
		default:
			printf("opción inválida");
			return 0;
			break;
	}
	
}

void generaBinario(){
	int binario[10][5];
	int i, j, MAX=10;

	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			binario[i][j]=rand()%2; 
		}		 
	}
	
	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			printf("%i  ", binario[i][j]); 
		}
		printf("\n");		 
	}	 
}

void generaGray(){
	int Gray[10][5];
	int bina[5];
	int i, j, MAX=10;

	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			bina[j]=rand()%2; 
		}
		Gray[i][0]=bina[0]; 
	
		for (int j = 1; j < 5; j++){
            	int a = bina[j];
            	int b = bina[j + 1];
            	int c = a^b;
            	Gray[i][j] = c;
        }
	}
	
	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			printf("%i  ", Gray[i][j]); 
		}
		printf("\n");		 
	}	 
}	


void generaReales(){
	double Reales[10][5];
	int i, j, MAX=10; 
	double ent, dec;
 
	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			ent = rand()%10;
			dec = (rand()%10) *0.1;
			Reales[i][j]=ent+dec; 
		}		 
	}
	
	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			printf("%.2lf  ", Reales[i][j]); 
		}
		printf("\n");		 
	}
}

void generaEnteros(){
	int Enteros[10][5];
	int i, j, MAX=10;

	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			Enteros[i][j]=1+rand()%9; 
		}		 
	}
	
	for(i=0;i<MAX;i++){ 
		for(j=0;j<5;j++){ 
			printf("%i  ", Enteros[i][j]); 
		}
		printf("\n");		 
	}	 
	
}



