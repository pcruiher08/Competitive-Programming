#include <iostream>
#include <cmath>

using namespace std;



int gcd(int a,int b){
    if(a==0)
        return 0;
    if(b==0)
        return a;

    gcd(b,a%b);
}

int countDigits(int &i){
    int cont =4,mod = i%10;
    while(mod==0){
        i /= 10;
        mod = i%10;
        cont--;
    }
    return cont;
}

void check(int i){
    int myGCD,tenPow,digits;
    if(i==10000)
        cout << 1 << endl;
    else if(i==0)
        cout << 1 << endl;
    else{
        digits= countDigits(i);

            switch(digits){
                case 1:
                    tenPow=10;
                    break;
                case 2:
                    tenPow=100;
                    break;
                case 3:
                    tenPow=1000;
                    break;
                default:
                    tenPow=10000;
                    break;
            }
            //cout << num << " " << tenPow << " " << i.length() << endl;
            myGCD = gcd(i,tenPow);
            cout << tenPow/myGCD << endl;
        }
    }


int main()
{
    int n;
    cin >> n;
    int numbers[n];
    float m;
    for(int i=0;i<n;i++){
        cin >> m;
        m = round( m * 10000.0 );
        numbers[i] = m;
    }

    /*
    string add = "0.";
    for(int j=0,cont=0;j<10;j++)
        for(int k=0;k<10;k++)
            for(int i=0;i<10;i++)
                for(int l=0;l<10;l++,cont++){
                    char d1=j+48,d2=k+48,d3=i+48,d4=l+48;
                    numbers[cont]= add + d1 + d2 + d3 + d4;
                }
    */
    for(int i=0;i<n;i++){
        //cout << numbers[i] << " =";
        check(numbers[i]);
        //cout << " -";
    }

    return 0;
}