#include <iostream>
#include <fstream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//	Using Only K&R
using namespace std;

void Problema01_Parentesis_Balanceados() {

int Casos_de_Prueba=0,ContadorLineasReales,i;
string Mensaje_por_lineas2;
bool band;

ifstream Ejemplo01;

Ejemplo01.open("Ejemplo01.txt");

	if ( Ejemplo01.fail() ) {

		cout<<"error al abrir el archivo";

	} else
     
	Ejemplo01>>Casos_de_Prueba;
	while( !Ejemplo01.eof() )  {
         
		band=false;
		getline ( Ejemplo01, Mensaje_por_lineas2 );
		char* Caracter_a_Caracter = new char[ Mensaje_por_lineas2.length() + 1 ];
		strcpy(Caracter_a_Caracter,Mensaje_por_lineas2.c_str());
		
		cout<<Caracter_a_Caracter;
		cout<<" Caso # "<<ContadorLineasReales;
		
		for	(i=0;i<strlen(Caracter_a_Caracter);i++)
		{
			
			if(i-1>-1)
			{
					
			if ( ( ':'==Caracter_a_Caracter[i-1] && '('==Caracter_a_Caracter[i] ) || ( ':'==Caracter_a_Caracter[i-1] && ')'==Caracter_a_Caracter[i] ) )//Validando emoticonos.
			{
				band=true;
			}
			else if ( ( ')'==Caracter_a_Caracter[i-1] && '('==Caracter_a_Caracter[i] )  )
			{
				band=false;
			}
			if('('==Caracter_a_Caracter[i])//Con los parentesis de apertura y cierre correctamente puestos
				{
			
			   for (j=i;j<strlen(Caracter_a_Caracter);j++)
			   {
			   		if ( ')'==Caracter_a_Caracter[j] )
			   		{
			   		band=true;
			   		break;	
					}
			   }
				
				}
			}
			
			
		}
		if ( ""==Caracter_a_Caracter || " "==Caracter_a_Caracter )//Si cadena vacia
			{
				
			band=true;	
				
			}
		
		
		
		if ( band )
		{
			
			cout<<"Parentesis Balanceados"<<endl;
			
		}else
		{
			cout<<"Parentesis no balanceados"<<endl;
		}
		
		ContadorLineasReales++;
		cin.get();
	//	cout<<Mensaje_por_lineas;
	//	cout<<" Caso # "<<ContadorLineasReales<<endl;

	}

	}

int main(int argc, char** argv) {

	Problema01_Parentesis_Balanceados();
	return 0;
	
}


