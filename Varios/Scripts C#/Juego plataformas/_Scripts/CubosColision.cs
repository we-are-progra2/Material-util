using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CubosColision : MonoBehaviour {

    public GameObject guimoneda;
    static Text scoreText;
    static int Score = 0;

    //Esto sirve para cuando el personaje pasa A traves de un Trigger

    void OnTriggerEnter(Collider col)
    {

    }

    //Este es para cuando el personaje choca con algo

    void OnCollisionEnter(Collision col)
    {
        switch (col.gameObject.tag)
        {
            case "Moneda":
                {
                    UpdateScore(1);
                    
                    break;
                }
                
        }
    }

     public static void UpdateScore(int Valor)
    {
        Score += Valor;
        scoreText.text = "" + Score;
    }



    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
