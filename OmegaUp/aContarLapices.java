import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
     Scanner lectura = new Scanner(System.in);
     int k, n;
     int contador = 0;
     n=lectura.nextInt();
     k=lectura.nextInt();
     for(int i=0; i<n; i++){
     int x=lectura.nextInt();
     if(x==k){
     contador++;
     }
     }
         System.out.println(contador);
    }
}