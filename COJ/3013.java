/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

/**
 *
 * @author Pablo
 */
public class camion {

    /**
     * @param args the command line arguments
     */
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner x = new Scanner (System.in);
        int n; 
        n = x.nextInt(); 
        int p=0;
        int k=0;
        while(n>0){
            k= x.nextInt();
        while(k>0){
            p=2*p+1;
            k--;
        }
        System.out.println(p);
        p=0;
        n--;
        }
        
    }
    
}
