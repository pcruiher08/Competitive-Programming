/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pablo
 */


    /**
     * @param args the command line arguments
     */
   
    


import java.io.*;
import static java.lang.Math.acos;
import java.text.DecimalFormat;
import java.util.*;
  
public class COJ{

public static void main (String[ ] args) throws IOException{
 // TODO code application logic here
  Scanner in = new Scanner(System.in);
  int x = in.nextInt();

  int[] busca= new int[x];

  final double PI = acos(-1);
  
  DecimalFormat df = new DecimalFormat("0.0000"); 
  
    for(int i=0; i<x; i++){ 
      busca[i]=in.nextInt();
  }


     int j;
     boolean flag = true;   // set flag to true to begin first pass
     int temp;   //holding variable

     while (flag)
     {
            flag= false;    //set flag to false awaiting a possible swap
            for( j=0;  j < busca.length -1;  j++ )
            {
                   if ( busca[ j ] < busca[j+1] )   // change to > for ascending sort
                   {
                           temp = busca[ j ];                //swap elements
                           busca[ j ] = busca[ j+1 ];
                           busca[ j+1 ] = temp;
                          flag = true;              //shows a swap occurred  
                  } 
            } 
      }
      double suma = 0;

      for(int r=0; r<10; r++){
       
        suma+=busca[r];
      }

      System.out.println(df.format(suma/(PI*2)));






    
        
      }
 
  
}



