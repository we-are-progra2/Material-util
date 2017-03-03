using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/* *
 * 
 * 
 * Este Script es para mover al personaje 
 * 
 * 
 * */


public class PersonajeAvanzado : MonoBehaviour
{

    public float velocidad = 6.0F;
    public float velocidadSalto = 6.0F;
    public float gravedad = 20.0F;

    public Vector3 direccionMovimiento = new Vector3(0, 0, 0);
    public Transform TransformacionCamara; //Variable de transformacion
                                           // Update is called once per frame
    void Update ()
    {
        CharacterController control = GetComponent<CharacterController>();
		
        if(control.isGrounded)
        {
            
           // direccionMovimiento.z = Input.GetAxis("Vertical");
            direccionMovimiento.y = 0F;
            direccionMovimiento = transform.TransformDirection(direccionMovimiento);
            direccionMovimiento *= velocidad;
            if (Input.GetButton("Jump"))
            {
                direccionMovimiento.y = velocidadSalto * 3;
            }
        }
        direccionMovimiento.x = Input.GetAxis("Horizontal");
        direccionMovimiento.x *= velocidad;
        direccionMovimiento.y -= gravedad * Time.deltaTime;
        control.Move(direccionMovimiento * Time.deltaTime);
	}
}
