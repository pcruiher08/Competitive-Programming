import java.math.BigInteger;
import java.util.*;

public class Main {
  /*
  bool esTri(unsigned long long int n){
  
  
  unsigned long long int e = sqrt(2*n);
  return e*(e+1)/2 == n;
}

int main(){
  //unsigned long long n; 
unsigned long long int n;
  do{
    cin>>n;
    if(n==0)
    exit(0);
   
      if(esTri(n))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
  }while(n!=0);
}
  */

    public static void main(String[] args) {
      Scanner x = new Scanner(System.in);
      BigInteger cero = new BigInteger("0");
     BigInteger n;
      do{
n = x.nextBigInteger();
    if(n.equals(cero))
    break;
   
      if(esTri(n)==true)
        System.out.println("YES");
        else
        System.out.println("NO");
  }while(true);
        
    }
     public static boolean esTri(BigInteger n){
       BigInteger uno = new BigInteger("1");
  BigInteger dos = new BigInteger("2");
    BigInteger t = new BigInteger(""+n);

   BigInteger e = new BigInteger("1");
   e=((t.multiply(dos)));
   e=sqrt(e);
  e=e.multiply(e.add(uno)); 
  n= n.multiply(dos);
  return e.equals(n);
}
//a la clase biginteger le falta el metodo sqrt 
public static BigInteger sqrt(BigInteger x) {
    BigInteger div = BigInteger.ZERO.setBit(x.bitLength()/2);
    BigInteger divideDos = div; for(;;) {BigInteger y = div.add(x.divide(div)).shiftRight(1);
        if (y.equals(div) || y.equals(divideDos))
            return y;
            
            
        divideDos = div;
        div = y;
    }
}

}

