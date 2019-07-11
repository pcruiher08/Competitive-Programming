import java.util.*;
import java.math.*;

class Main {
  public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  BigInteger n;
  BigInteger k; 
  
  n = sc.nextBigInteger();

  boolean flag = false;
  BigInteger bacteria = new BigInteger("1");
  BigInteger i = new BigInteger("0");
  int j = 0;

  while(n.compareTo(i) == 1){
  //System.out.println(n);
  i = i.add(new BigInteger("1"));


  BigInteger two = new BigInteger("2");

  bacteria = bacteria.multiply(BigInteger.valueOf(2));

  //System.out.println(bacteria);

  k = sc.nextBigInteger();

  bacteria = bacteria.subtract(k);

  if(bacteria.compareTo(new BigInteger("0")) == -1){
    flag = true;
    break;
  }

  }

  if(!flag){
  System.out.println(bacteria.mod(new BigInteger("1000000007")));
  //System.out.println("hola");
  }
  else{
  System.out.println("error");
  }
  }
}