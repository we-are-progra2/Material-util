#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct datosComida {
	
	int proteinas;
	int carbohidratos;
	int grasas;
	
};

bool suma(struct datosComida comidas[], int limiteProteinas, int limiteCarbohidratos, int limiteGrasas, int indice) {
	
	
	
	
}
suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,indice);

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
		
		if(suma(comidas,cantProteinas,cantCarbohidratos,cantGrasas,i)) {
			
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
