#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>  
#include "miniwin.h"

using namespace miniwin;
 
int main() {
	srand (time(NULL));
	int x, y=51, z=100;
	int nums[10];
	for(x=0;x<10;x++){
		nums[x] = rand() % 500 +50;
	}
	
  	vredimensiona(600, 600);
  	linea(50, 50, 50, 550);
  	texto(40,550, "0");
  	texto(30,500, "50");
  	texto(20,450, "100");
  	texto(20,400, "150");
  	texto(20,350, "200");
  	texto(20,300, "250");
  	texto(20,250, "300");
  	texto(20,200, "350");
  	texto(20,150, "400");
  	texto(20,100, "450");
  	texto(20, 50, "500");
  	
  	linea(50, 550, 550, 550);
  	texto(90,550, "1");
  	texto(140,550, "2");
  	texto(190,550, "3");
  	texto(240,550, "4");
  	texto(290,550, "5");
  	texto(340,550, "6");
  	texto(390,550, "7");
  	texto(440,550, "8");
  	texto(490,550, "9");
  	texto(540,550, "10");
  	
  	color(AZUL);
  	
	for(x=0;x<10;x++){
		rectangulo_lleno(y, 550, z, nums[x] );
		y+=50;		
		z+=50;
	}
  	/*rectangulo_lleno(51, 550, 100, 450);
  	rectangulo_lleno(101, 550, 150, 350);
  	rectangulo_lleno(151, 550, 200, 250);
  	rectangulo_lleno(201, 550, 250, 450);
  	rectangulo_lleno(251, 550, 300, 350);
  	rectangulo_lleno(301, 550, 350, 150);
  	rectangulo_lleno(351, 550, 400, 350);
  	rectangulo_lleno(401, 550, 450, 250);
  	rectangulo_lleno(451, 550, 500, 450);
  	rectangulo_lleno(501, 550, 550, 150);*/
  	refresca();  
}
