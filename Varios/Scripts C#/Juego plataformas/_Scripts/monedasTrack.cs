using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class monedasTrack : MonoBehaviour {

    static Text scoreText;
    static int Score = 0;


	// Use this for initialization
	void Start ()
    {
        scoreText = GameObject.FindGameObjectWithTag("GUImoneda").GetComponent<Text>();
        UpdateScore(Score);
	}


    public static void UpdateScore(int Valor)
    {
        Score += Valor;
        scoreText.text = "" + Score;
    }
	
	// Update is called once per frame
	void Update () {
		
	}


}
