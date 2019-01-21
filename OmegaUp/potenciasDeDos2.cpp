#include "conio.h"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

class BigInt{
   vector<int> digits;
public:
   BigInt(const BigInt& a);
   BigInt(string num="000000000");
   BigInt operator+(const BigInt& a);
   BigInt& operator+=(const BigInt& a);
   BigInt operator=(BigInt a);
   friend std::ostream& operator<<(std::ostream& out,BigInt a);
};

struct Ascii2Int { int operator()(int c) {return c-'0';} };

BigInt::BigInt(const BigInt& other):digits(other.digits){}

BigInt BigInt::operator=(BigInt a){
   for(unsigned int i=0; i<digits.size();i++){
     digits[i] = a.digits[i];	
   } 
   return *this;
}

BigInt::BigInt(string num){
   transform(num.rbegin(), num.rend(), back_inserter(digits),Ascii2Int());
}
BigInt& BigInt::operator +=(const BigInt& a)
{
   unsigned int maxSize;
   unsigned int num = 0;
   unsigned int carry = 0;
   BigInt Temp; 
 
   //size for output variable

   if(digits.size()>a.digits.size()){
	   maxSize = digits.size();
	   Temp.digits.resize(digits.size());
   }
   else{
	   maxSize = a.digits.size();
	   digits.resize(a.digits.size());
   }

   copy(a.digits.begin(), a.digits.end(), Temp.digits.begin());

   for(unsigned int i = 0; i < maxSize; i++)
   {
       num = digits[i] + Temp.digits[i] + carry;

	   if(num >= 10)
       {
           num = num - 10;
           carry = 1;
	   }
	   else{
		   carry = 0;
	   }

	   digits[i] = num;
   }
   if (carry){
	   digits.push_back(1);
   }
   
   return *this;
}

BigInt BigInt::operator +(const BigInt& a)
{
    return BigInt(*this) += a;

}

std::ostream& operator <<(std::ostream& out,BigInt a)
{
   for(unsigned int i=0; i < a.digits.size(); i++){
      out << a.digits[i] << endl;
   }
   return out;
}

int main(){
    BigInt base("2"); 
    int num;
    cin>>num;
    BigInt B1(base);
    for(int i=0; i<=num; i++){
        base+=base;
    }


   cout <<base<< endl;
   return 0;
}