using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
 * 
 * 
 * Este Script es para tener un conocimiento basico sobre tener un movimiento en eje X y Z con gravedad por defecto simple
 * 
 * 
 * */


public class Personaje : MonoBehaviour
{
    // Update es llamado cada frame

    public CharacterController MiControl; //Input

    public float velocidad = 5f; //Constante que determina la velocidad a la que se movera el personaje

    public Transform TransformacionCamara; //Variable de transformacion

	void Update ()
    {
        /*float x = 3f;
        float y = 2f;                          |
        float z = 1f; Para esto se usa Vector3 V*/
        Vector3 mivector = new Vector3(0, 0, 0); //Variable Vector que ocupa 3 float que se modificara a lo largo del movimiento
        
        /*
        * Obtener entrada(Input) del jugador
        * usar la entrada para mover el personaje
        */

        mivector.x = Input.GetAxis("Horizontal");
        mivector.z = Input.GetAxis("Vertical");
        mivector.y = Input.GetAxis("Jump");
        mivector = mivector * velocidad;

        mivector = TransformacionCamara.rotation * mivector; //Rotar entrada dependiendo de la camara



        MiControl.SimpleMove(mivector);
	}
}
