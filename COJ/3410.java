import java.util.*;
import java.text.DecimalFormat;

public class HelloWorld {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int cantidad= in.nextInt();
     int datos[][] = new int[cantidad][2];

     for(int i=0; i<cantidad; i++){
        datos[i][0]=in.nextInt();
        datos[i][1]=in.nextInt();
     }
     for(int j=0; j<cantidad; j++){
        for(int k=j+1; k<cantidad; k++){
            if(datos[j][0]==datos[k][0]&&datos[j][0]!=0){
                datos[j][1]+=datos[k][1];
                datos[k][0]=0;
                datos[k][1]=0;
            }
        }
     }
     
      boolean swapped = true;
    while (swapped) {
       swapped = false;
       for(int r=1; r<cantidad; r++) {
           int temp=0;
           int temp2=0;
           if(datos[r-1][0] > datos[r][0]) {
               temp = datos[r-1][0];
                datos[r-1][0] = datos[r][0];
                datos[r][0] = temp;
                temp2 = datos[r-1][1];
                datos[r-1][1] = datos[r][1];
                datos[r][1] = temp2;
                swapped = true;
            }
        }
    }

     for(int q=0; q<cantidad; q++){
       //for(int p=0; p<datos; p++){
       if(datos[q][0]!=0)
            System.out.println(datos[q][0]+" "+datos[q][1]);
        //}
     }

     

  }
}