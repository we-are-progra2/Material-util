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
			
			   for (int j=i;j<strlen(Caracter_a_Caracter);j++)
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
	
	
			
				
			
		
		
		
		
int Intentando_Cumplir_La_Dieta( int Cantidad_de_Comidas,int Proteinas,int Carbohidratos,int Grasas,int **Posibilidades,int Pos_,int aux_P,int aux_C,int aux_G )	
{
	int band;
	int aux_P2,aux_C2,aux_G2;	
	bool t=false;
	
	if( Cantidad_de_Comidas<=Pos_ )//1<5 primer paso de la funcion.
	{
		
	return -1;
	cout<<"entro"<<endl;
		
	}
	
	
	aux_P2=aux_P;
	aux_C2=aux_C;
	aux_G2=aux_G;	//0 en el primero,01 en el sgundo 012 en el tercerto
	
	for ( int i=Pos_;i<Cantidad_de_Comidas;i++ )
	{
	band=0;	
	aux_P=Posibilidades[i][0]+aux_P2;//01 en el primer ciclo. 01+2 en el segundo .01+2+3 en el tercero...
	aux_C=Posibilidades[i][1]+aux_C2;
	aux_G=Posibilidades[i][2]+aux_G2;
	
	cout<<aux_P<<" "<<aux_C<<" "<<aux_G<<" "<<Pos_-1<<i<<endl;// nR DE COMbinacion
	cin.get();
	
	
	
	if (aux_P==Proteinas && aux_C==Carbohidratos && aux_G==Grasas)
	{
		
		return 1;
		
	}

	
	else
	{
		
		band=Intentando_Cumplir_La_Dieta( Cantidad_de_Comidas,Proteinas, Carbohidratos,Grasas,Posibilidades,Pos_+1,aux_P,aux_C, aux_G );

	}
	if (band==1)
	{
		t=true;
	}
	
	}
	if (t)
	{
		return 1;
	}
	
}



void Problema02_Consumo_Alimenticio()
{

int Casos_de_Prueba,Proteinas, Carbohidratos,Grasas,Cantidad_de_Comidas;

ifstream Ejemplo02;
int band;


int Caso_Actual=0;
int aux_P,aux_C,aux_G;

Ejemplo02.open("Ejemplo02.txt");

	if ( Ejemplo02.fail() ) {

		cout<<"error al abrir el archivo";

	} else
	{
		Ejemplo02>>Casos_de_Prueba;
		while ( !Ejemplo02.eof() )
		{
		band=0;
		Caso_Actual++;	
		Ejemplo02>>Proteinas>>Carbohidratos>>Grasas>>Cantidad_de_Comidas;
		aux_P=aux_C=aux_G=0;
		int** Posibilidades  =		new int *[Cantidad_de_Comidas];
	
		for(int i = 0; i < Cantidad_de_Comidas; ++i)
    	{
		Posibilidades[i] = new int[3];
		}
		cout<<Proteinas<<" "<<Carbohidratos<<" "<<Grasas<<endl;
		cout<<Cantidad_de_Comidas<<endl;
		
		for(int i=0;i<Cantidad_de_Comidas;i++)
		{
			
			for( int j=0;j<3;j++)
			{
				
				Ejemplo02>>Posibilidades[i][j];
				cout<<Posibilidades[i][j]<<" ";
			}
			cout <<endl;
			
		}
		
		for(int i=0;i<Cantidad_de_Comidas;i++)
		{

		aux_P=Posibilidades[i][0]+aux_P; // Para una suma consecutiva no funcional pero necesaria.
		aux_C=Posibilidades[i][1]+aux_C;
		aux_G=Posibilidades[i][2]+aux_G;

			if( Posibilidades[i][0]==Carbohidratos && Posibilidades[i][1]==Proteinas && Posibilidades[i][2]==Grasas || ( aux_P==Proteinas && aux_G==Grasas && aux_C==Carbohidratos ))
			{
				
			band=1;
			break;	
			
			}
		
		}
		
		//------------------------------------------------
		
		if ( 1!=band )
		{
			
		aux_P=Posibilidades[0][0]; //Enviando la primera linea de cada caso de prueba .
		aux_C=Posibilidades[0][1];
		aux_G=Posibilidades[0][2];
			
		band=Intentando_Cumplir_La_Dieta(Cantidad_de_Comidas,Proteinas,Carbohidratos,Grasas,Posibilidades,1,aux_P,aux_C,aux_G);
				
		}
		
		//-----------------------------------------------
		
		if ( 1==band )
		{
			cout<<endl;
			cout<<"  \t Caso # "<<Caso_Actual<<" Si es posible"<<endl;
			cout<<endl;
			
		}
		else
		{
			cout<<endl;
			cout<<"  \t Caso # "<<Caso_Actual<<" No es posible"<<endl;	
			cout<<endl;
		}
		cin.get();
		
		}
		
	}
	Ejemplo02.close();
     
	
	
}


int main(int argc, char** argv) {

	//Problema01_Parentesis_Balanceados();
	Problema02_Consumo_Alimenticio();
	return 0;
	
}


