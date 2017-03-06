#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct datosComida {
	
	int proteinas;
	int carbohidratos;
	int grasas;
	
};

bool sumaGrasas(struct datosComida comidas[],int limiteGrasas,int valor,int indiceLimite,int contador) {
	
		if(contador == indiceLimite) {
		
			if(valor == limiteGrasas) {
				
				return true;
			
			}else {
			
				return false;
			}
		
		}
		
		valor += comidas[contador].grasas;
		contador++;
		sumaGrasas(comidas,limiteGrasas,valor,indiceLimite,contador);
	
}

bool sumaCarbohidratos(struct datosComida comidas[],int limiteCarbohidratos,int limiteGrasas,int valor,
					   int indiceLimite,int contador) {
	
	if(contador == indiceLimite) {
		
		if(valor == limiteCarbohidratos) {
			
			if(sumaGrasas(comidas,limiteGrasas,0,indiceLimite,0)) {
				
				return true;
			}
			
		}else {
			
			return false;
		}
		
	}
		
	valor += comidas[contador].carbohidratos;
	contador++;
	sumaCarbohidratos(comidas,limiteCarbohidratos,limiteGrasas,valor,indiceLimite,contador);
}


bool suma(struct datosComida comidas[],int limiteProteinas,int limiteCarbohidratos,int limiteGrasas
		  ,int valor,int cantidad,int &contador) {
	
	if(contador == cantidad)
	{
		if(valor == limiteProteinas) {
			
			return true;
			
		}else {
			
			return false;
		}
	}else if(valor == limiteProteinas) {
		      
		      if(sumaCarbohidratos(comidas,limiteCarbohidratos,limiteGrasas,0,contador,0)) {
		      	
		      	return true;
		      	
		      }
	
	}
	
	valor += comidas[contador].proteinas;
	contador++;
	suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,valor,cantidad,contador);
}


bool Comidas(int cantProteinas, int cantCarbohidratos, int cantGrasas, fstream &archivo) {
	
	int cantComidas=0;
	int contador=0;
	bool bandera=false;
	
	archivo>>cantComidas;
	struct datosComida comidas[cantComidas];
	
	for(int i=0 ; i < cantComidas ; i++) {
		
		archivo>>comidas[i].proteinas;
		archivo>>comidas[i].carbohidratos;
		archivo>>comidas[i].grasas;
	}
	for(int i = 0 ;i < cantComidas ; i++) {
		
		if(suma(comidas,cantProteinas,cantCarbohidratos,cantGrasas,0,cantComidas,contador)) {
			
			return true;
			
		}
		
	}
	

	return false;
	
}

int main(int argc, char** argv) {
	
	fstream archivo;
	int numPruebas=0;
	int contNumPruebas=0;
	int cantCarbohidratos,cantProteinas,cantGrasas;
	
	archivo.open("Entrada.txt",ios::in);
	if(archivo.fail()) {
		
		cout<<"Error al abrir el archivo";
		
	}else {
		
		archivo>>numPruebas;
		
		while(contNumPruebas != numPruebas) {
			
			archivo>>cantProteinas;
			archivo>>cantCarbohidratos;
			archivo>>cantGrasas;
			contNumPruebas++;
			if(Comidas(cantProteinas,cantCarbohidratos,cantGrasas,archivo)) {
				
				cout<<"Caso#"<<contNumPruebas<<": SI"<<endl;
				
			}else {
				
				cout<<"Caso#"<<contNumPruebas<<": NO"<<endl;
				
			}
			
		}
		
	}
	archivo.close();
	return 0;
}
