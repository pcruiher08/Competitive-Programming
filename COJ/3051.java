import java.util.*;
import java.text.DecimalFormat;

public class kirro {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int see= in.nextInt();
     double[] si= new double[see];
     DecimalFormat df = new DecimalFormat("#,###,##0.00");
     for(int i=0; i<see; i++){
    double one= in.nextDouble();
     double two= in.nextDouble();
     double d2= one/two;
     si[i]= d2;
     }
for(int j=0; j<see; j++){
    System.out.println(df.format(si[j]));
     }
  }
}