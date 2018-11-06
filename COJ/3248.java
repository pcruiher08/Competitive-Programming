import java.util.*;

public class main {
  public static void main(String[] args) {
	int n; 
	int j; 
	int m; 
	int b; 
	int c=0; 
	int a=1;
	Scanner p=new Scanner(System.in);
	n=p.nextInt();
	m=p.nextInt();
	b=m;
	j=p.nextInt();

	int[] arr=new int[j+3*a];

	for(int i=0; i<=j; i++)
		if(i==0)
		  arr[i]=0;
		else 
		  arr[i]=p.nextInt();
	
	for(int i=1; i<j+1; i++){
		if(arr[i]>b){//atras
			c+=(arr[i]-b); // (-b+arr[i])
			a+=(arr[i]-b); 
			b=arr[i];
		}else if(arr[i]<a){//adelante
			c+=(a-arr[i]); //-arr[i]+a
			b-=(a-arr[i]);
			a=arr[i];
		}
	}
	/*
	Sample input
5 1
3
1
5
3
Sample output
6
Hint(s)
Sample input #2
5 2
3
1
5
3

Sample output #2
4
	*/
	System.out.println(c);
  }
}