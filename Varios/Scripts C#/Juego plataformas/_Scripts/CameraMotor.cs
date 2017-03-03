using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
 * Codigo para que la camara siga al personaje. 
 * */


public class CameraMotor : MonoBehaviour {

    private Transform miraA;
    private Vector3 Offset;
	void Start () {
        miraA = GameObject.FindGameObjectWithTag ("Player").transform; //El personaje debe tener TAG de "Player"
        Offset = transform.position - miraA.position;
	}
	
	// Update is called once per frame
	void Update () {
        transform.position = miraA.position + Offset;
	}
}
