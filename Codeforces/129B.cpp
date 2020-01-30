#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Persona {
    int n;
    vector<Persona*> enlaces;
};

int main() {
    int n, l, r = 0;
    cin >> n >> l;
    Persona estudiantes[n];
    for(int i = 0; i < n; i++) {
        estudiantes[i].n = 0;
    }
    for(int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        estudiantes[a].enlaces.push_back(&estudiantes[b]);
        estudiantes[b].enlaces.push_back(&estudiantes[a]);
        estudiantes[a].n++;
        estudiantes[b].n++;
        cerr << "Pablo estuvo aqui" << endl;
    }
    bool quitando = false;
    queue<Persona*> expulsados;
    do {
        quitando = false;
        for(int i = 0; i < n; i++) {
            if(estudiantes[i].n == 1) {
                expulsados.push(&estudiantes[i]);
                quitando = true;
            }
        }
        if(quitando) {
            r++;
        }
        while(expulsados.size() > 0) {
            for(int i = 0; i < expulsados.front()->enlaces.size(); i++) {
                expulsados.front()->enlaces[i]->n--;
            }
            expulsados.front()->n = 0;
            expulsados.pop();
        }
    } while(quitando);
    cout << r << endl;
}