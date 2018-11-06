/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
/**
 *
 * @author Pablo
 */
public class TopTeenStrings {

    /**
     * @param args the command line arguments
     */boolean contiene(String x, String y){
        if(x.contains(y)) { 
            return true;
        } else {
            return false;
        }
        //return false;
    }
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner x = new Scanner(System.in);
        
        
        String a; 
        String b; 
        String[] palabras; 
        String p= x.nextLine();
        
        int n = Integer.parseInt(p);
        for(int i=0; i<n; i++){
        
        a=x.nextLine();
        //b=x.nextLine();
        palabras=a.split(" ");
        b=palabras[1];
        a=palabras[0];
        boolean si;
        int suma=0; 
        String nuevo="";
        while( a.contains(b)){
        suma++;
        a =a.replace(b,"");
        }
        System.out.println(suma);
    }
    }
    
    
}
