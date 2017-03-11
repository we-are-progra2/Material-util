#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct datosComida {
	
	int proteinas;
	int carbohidratos;
	int grasas;
	
};

suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,valorP,valorC,valorG,cantidad,auxiliar,contador);
bool suma(struct datosComida comidas[],int limiteProteinas,int limiteCarbohidratos,int limiteGrasas
		  ,int valorP,int valorC,int valorG,int cantidad,bool bandera,int indice) {
	
	if(indice == cantidad)
	{
		return false;
	}
	
	if(valorP < limiteProteinas) {
		
		valorP += comidas[indice].proteinas;
		suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,valorP,valorC,valorG,cantidad,auxiliar,contador,indice+1);
	}
	if(valorP > limiteProteinas) {
		
		valorP -= comidas[indice].proteinas;
		suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,valorP,valorC,valorG,cantidad,auxiliar,contador,indice+1);
		
	}
	if(valorP == limiteProteinas) {
		
		bandera = true;
		return true;
	}else {
		
		valorP -= comidas[indice].proteinas;
		suma(comidas,limiteProteinas,limiteCarbohidratos,limiteGrasas,valorP,valorC,valorG,cantidad,auxiliar,contador,indice+1);
	}
	return false;
	
	
	
	
	
	
	
	
	
	
	
	
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
