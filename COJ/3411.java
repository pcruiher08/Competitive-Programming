import java.util.*;
import java.text.DecimalFormat;  
public class HelloWorld{  
public static void main (String[ ] args) {
  double pi = Math.acos(0)*2;
  Scanner in = new Scanner(System.in);
  int x = in.nextInt();
  double[] numero= new double[x];
  DecimalFormat df = new DecimalFormat("0.00");
    for( int i=0; i<x; i++){ 
      double r= in.nextDouble();
   numero[i]= (pi-2)*Math.pow(r,2);
  }
    for(int j=0; j<x; j++){  
System.out.println(df.format(numero[j]));}
      } 
}