#include "omp.h"
#include "stdio.h"
#include "string.h"
#define TAM 40

char palindromo[TAM];
int longitud;
int inicio=0,fin;
                        
int main(void){
	
	printf("Ingresar palabra : ");
	scanf("%s",palindromo);
	longitud=strlen(palindromo);

        #pragma omp parallel
        {
		int x = omp_get_thread_num();
            	if(x != 1){
            		printf("--- %d\n", x);
        }
            	
        #pragma omp critical
        {
                for(fin=longitud-1; palindromo[fin]==palindromo[inicio] && fin>=0; inicio++,fin--);
		if(x == 1){
			 if(inicio==longitud){
			  printf("--- %d Verdadero\n", x);
		 }  else { printf ("--- %d  Falso\n", x);
	     } 
		}
        }
        }
                         
	return 0;
}