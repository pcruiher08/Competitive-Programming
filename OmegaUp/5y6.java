import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String a;
        Scanner lectura = new Scanner(System.in);
        a= lectura.nextLine();
       a = a.substring(0,a.indexOf(" "))+ a.substring(a.lastIndexOf(" "));
        String viejo = a.replace("6","5");
        int sumaMenor = Integer.parseInt(viejo.substring(0,viejo.indexOf(" "))) + Integer.parseInt(viejo.substring(viejo.indexOf(" ")+1));
       String nuevo = a.replace("5","6");
         int sumaMayor = Integer.parseInt(nuevo.substring(0,nuevo.indexOf(" "))) + Integer.parseInt(nuevo.substring(nuevo.indexOf(" ")+1));    
        String mayor = " "+sumaMayor;
        String menor = ""+sumaMenor;
        System.out.println(menor + mayor);
    }
}