#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>

//Busca el caracter indicado por la posicion "pos", de la cadena mensaje en el alfabeto y
//guarda en esa misma posicion en la cadena cifrado, el caracter correspondiente del alfabeto2
void buscar(int pos, int tamalfabeto,char *mensaje,char *cifrado,char *alfabeto,char *alfabeto2){
	int j;
	for (j=0;j< tamalfabeto; j=j+1){
		if(mensaje[pos]==alfabeto[j]){
			cifrado[pos] = alfabeto2[j];
		}
	}
}

int main ()
{
	char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alfabeto2[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char mensaje[]="ROLANDO";
	char cifrado[sizeof(mensaje)];
	strcpy(cifrado,mensaje);
	int k=3;//Clave de cifrado
	int i,j;
	int tammensaje=sizeof(mensaje)-1;
	int tamalfabeto=sizeof(alfabeto)-1;
	
	//Contruye alfabeto2 para cifrado, rotando k elementos a izquierda
	for (i=0,j=k;j< tamalfabeto; j=j+1,i=i+1){
		alfabeto2[i]=alfabeto[j];
	}
	for (i=tamalfabeto-k,j=0;j< k;j=j+1,i=i+1){
		alfabeto2[i]=alfabeto[j];
	}
	
	printf("\n Clave cifrado %d  \n",k);
	printf("\n Alfabeto  %s  \n",alfabeto);
	printf("\n Alfabeto2 %s  \n",alfabeto2);
		
	time_t inicio,fin;
	time(&inicio);
	  
	#pragma omp parallel
	{
		//En cada proceso paralelo se ejecuta buscar() para una posicion i
		for (i=0;i< tammensaje; i=i+1){
			  buscar(i, tamalfabeto,mensaje,cifrado,alfabeto,alfabeto2);
		}
	}

	printf("\n mensaje: %s  \n",mensaje);
    printf("\n cifrado: %s  \n",cifrado);

	time(&fin);     
	printf("\n Tiempo: %.2f segundos",difftime(fin,inicio)); 

	return 0;
}	  
