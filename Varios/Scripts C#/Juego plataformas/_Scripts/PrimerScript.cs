using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
    Script de prueba para ver como funciona imprimir en c# 
*/


public class PrimerScript : MonoBehaviour {

    // Use this for initialization

    public string imprimir=" Esto es un dos: ";
    public int entero = 2;

	void Start ()
    {
        print("Hola Mundo!"+imprimir+entero);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}