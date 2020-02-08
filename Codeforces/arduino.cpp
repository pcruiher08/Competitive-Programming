#include <iostream>

using namespace std;

struct Punto {
    int x;
    int y;        
};

void imprimePunto(Punto q) {
    cout << q.x << ", " << q.y << endl;
}

int main() {
    Punto a;
    Punto b;
    a.x = 5;
    a.y = 27;
    b.x = 13;
    b.y = -3;
    imprimePunto(a);
    imprimePunto(b);
}