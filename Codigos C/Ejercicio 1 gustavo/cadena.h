#include <iostream>
#include <string.h>
#include <string.h>
using namespace std;
//Made by: Jesus Olmedo
class cadena
{
	public:
		char* cad;
		// Operador para igualar a otra "cadena"
		bool operator= (cadena & n)
		{
			strcpy (this->cad, n.cad);
		}
		// Operador para igualar con un valor
		bool operator= ( char n[100])
		{
			cad = n;
		}
		// Operador para comparar
		bool operator== (cadena n)
		{
			if(strcmp (this->cad, n.cad) == 0)
				return true;
			else
				return false;
		}
		// Operador para comparar menor
		bool operator< (cadena n)
		{
			if(strcmp (this->cad, n.cad) < 0)
				return true;
			else
				return false;
		}
		// Operador para comparar mayor
		bool operator> (cadena n)
		{
			if(strcmp (this->cad, n.cad) > 0)
				return true;
			else
				return false;
		}
		// Operador poder usar "cout"
		friend ostream& operator << (ostream &o, cadena n)
		{
			o<<n.cad;
			return o;
		}
		// Operador poder usar "cin"
		friend istream& operator >> (istream &o, cadena n)
		{
			o>>n.cad;
			return o;
		}
};
