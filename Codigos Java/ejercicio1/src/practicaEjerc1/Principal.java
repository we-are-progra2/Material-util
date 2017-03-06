/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practicaEjerc1;

/**
 *
 * @author luisfernando
 */
public class Principal implements Entrada{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        System.out.println(datos[0]);
        for (int i = 1; i <= Integer.parseInt(datos[0]); i++) {
            
            if(equilibrado(datos[i])) {
                
                System.out.println(datos[i]+"\tCaso #"+i+": SI");
                
            }else {
                
                System.out.println(datos[i]+"\tCaso #"+i+": NO");
                
            }
            
        }
       
       /*if(equilibrado(datos[2])) {
                
                System.out.println("Caso #"+3+": SI");
                
            }else {
                
                System.out.println("Caso #"+3+": NO");
                
            }*/
        
    }
    public static boolean equilibrado(String mensaje) {
        
        boolean bandera = false;
        
        if(mensaje.equals("")) {
            
            return true;
            
        }else {
            
            for (int i = 0; i < mensaje.length(); i++) {
                
                if(mensaje.charAt(i) == ' ' || mensaje.charAt(i) == ':') {
                    
                    bandera = true;
                    
                }
                
            }
            if(!bandera) {
                
                return false;
                
            }
            for (int i = 0; i < mensaje.length(); i++) {
                
                if(mensaje.charAt(i) == '(' && i != 0) {
                    
                    if(mensaje.charAt(i-1) != ':') {
                        
                        if(cerrado(mensaje, i+1)) {
                        
                            bandera = true;
                        
                        }else {
                        
                            return false;
                        
                        }
                    }
                }
            }
            
            for (int i = mensaje.length()-1; i > -1; i--) {
                
                if(mensaje.charAt(i) == ')' && i != 0) {
                    
                    if(mensaje.charAt(i-1) != ':') {
                        
                        if(abierto(mensaje, i-1)) {
                        
                            bandera = true;
                        
                        }else {
                        
                            return false;
                        
                        }
                        
                    }
                    
                }
            }
            
            for (int i = 0; i < mensaje.length(); i++) {
                
                if(mensaje.charAt(i) == ':') {
                    
                    if(mensaje.charAt(i+1) == '(' || mensaje.charAt(i+1) == ')') {
                        
                        bandera = true;
                        
                    }
                }
            }
            
        }
       return bandera; 
    }
    public static boolean cerrado(String mensaje, int indice) {
        
        for (int i = indice; i < mensaje.length(); i++) {
            
            if(mensaje.charAt(i) == ')') {
                
                if(mensaje.charAt(i-1) == ':') {
                    break;
                }
                return true;
                
             }
        }
        return false;
    }
    public static boolean abierto(String mensaje, int indice) {
        
        for (int i = indice; i > -1; i--) {
            
            if(mensaje.charAt(i) == '(') {
                
                if(i != 0) {
                    if(mensaje.charAt(i-1) != ':') {
                    
                        return true;
                    
                    }    
                }else {
                    
                    return true;
                }
                
                
            }
            
        }
        return false;
    }
    
}
