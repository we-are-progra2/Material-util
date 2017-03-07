#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
// Parentesis Balanceados - By: Jesus Olmedo.
int main(int argc, char** argv) 
{
	char frase[100];
	int cantidad;
	int longitud;
	int i, j;
	int parentesis;
	bool desbalance = false;
	bool emoticon = false;
	ifstream archivo;
	archivo.open ("frases.txt");
	archivo >> cantidad;
	archivo.getline (frase, 100, '\n');
	for (i = 0; i < cantidad; i++) {
		archivo.getline (frase, 100, '\n');
		parentesis = 0;
		longitud = strlen (frase);
		for (j = 0; j < longitud; j++) {
			if ((emoticon == false) && (frase[j] == '(')) {
				parentesis++;
			} else if ((emoticon == false) && (frase[j] == ')')) {
				parentesis--;
			} else if (emoticon == true) {
				emoticon = false;
			}
			if ((frase[j] == ':')|| (frase[j] == ';')) {
				emoticon = true;
			} else {
				emoticon = false;
			}
			if (parentesis < 0) {
				desbalance = true;
			}
		}
		if (parentesis == 0 && desbalance == false) {
			cout << "Caso #" << i+1 << " Si" << endl;
		} else {
			cout << "Caso #" << i+1 << " No" << endl;
		}
	}
	archivo.close ();
	return 0;
}
