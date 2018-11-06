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
     */
    
    
    
     String inverso(String s) {
       char c[] = s.toCharArray();
        int i = 0, j = c.length - 1;
        while (i < j) {
        char tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
        i++;
        j--;
        }
        return new String(c);
        }

    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner x = new Scanner(System.in);
        String a = x.nextLine();
        String a1;
        String a2;
        
        if(a.length()%2==0){
        a1= a.substring(0,a.length()/2);
        a2= a.substring(a.length()/2, a.length());
        }else{
        a1 = a.substring(0,a.length()/2);
        a2 = a.substring((a.length()/2)+1,a.length());
        }
        
        char[] c=a1.toCharArray();
        for(int i=c.length-1;i>=0;i--){
        System.out.print(c[i]);
        }
        if(a.length()%2!=0)
            System.out.print(a.charAt(a.length()/2));
        
        char[] d=a2.toCharArray();
        for(int i=d.length-1;i>=0;i--){
        System.out.print(d[i]);
        }   
    }
}
