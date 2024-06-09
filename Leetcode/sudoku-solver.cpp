#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;

return 0;
}
class Solution {
public:
    bool checkRowSolved(vector<vector<int> >mat, int col){
        set<int> s;
        for(int i = 0; i < 9; i++){
            if(mat[i][col] != -1){
                s.insert(mat[i][col]);
            }
        }
        return (s.size() == 9);
    }

    bool checkColumnSolved(vector<vector<int> >mat, int row){
        set<int> s;
        for(int i = 0; i < 9; i++){
            if(mat[row][i] != -1){
                s.insert(mat[row][i]);
            }
        }
        return (s.size() == 9);
    }

    bool checkSubMatrixSolved(vector<vector<int> > mat, int row, int col){
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        set<int> s;

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                //cout<<mat[i][j]<<" ";
                if(mat[i][j] != -1){
                    s.insert(mat[i][j]);
                }
            }//cout<<endl;
        }

        return (s.size() == 9);;
    }

    bool checkRow(vector<vector<int> >mat, int col){
        set<int> s;
        int neg = 0;
        for(int i = 0; i < 9; i++){
            if(mat[i][col] != -1){
                s.insert(mat[i][col]);
            }else{
                neg++;
            }
        }
        return (s.size() + neg == 9);
    }

    bool checkColumn(vector<vector<int> >mat, int row){
        set<int> s;
        int neg = 0;
        for(int i = 0; i < 9; i++){
            if(mat[row][i] != -1){
                s.insert(mat[row][i]);
            }else{
                neg++;
            }
        }
        return (s.size() + neg == 9);
    }

    bool checkSubMatrix(vector<vector<int> > mat, int row, int col){
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        set<int> s;
        int neg = 0;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                //cout<<mat[i][j]<<" ";
                if(mat[i][j] != -1){
                    s.insert(mat[i][j]);
                }else{
                    neg++;
                }
            }//cout<<endl;
        }
    

        return (s.size() + neg == 9);;
    }

    bool isValid(vector<vector<int> > mat, int row, int col){
        cout<<"CHECK ROW: "<<checkRow(mat, col)<<endl;
        cout<<"CHECK COL: "<<checkColumn(mat, row)<<endl;
        cout<<"CHECK SUB: "<<checkSubMatrix(mat, row, col)<<endl;

        return checkRow(mat, col) && checkColumn(mat, row) && checkSubMatrix(mat, row, col);
    }

    bool isSolved(vector<vector<int> > mat){
        bool flag = true;
        for(int row = 0; row < 9; row++){
            if(!checkColumnSolved(mat, row)){
                flag = false;
            }
        }
        for(int col = 0; col < 9; col++){
            if(!checkRowSolved(mat, col)){
                flag = false;
            }
        }

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if(!checkSubMatrixSolved(mat, i, j)){
                    flag = false;
                }    
            }
        }

        return flag;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int> > mat;
        vector<pair<int, int> > coords;
        for(int i = 0; i < 9; i++){
            vector<int> fila;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    fila.push_back(-1);
                    coords.push_back({i,j});
                }else{
                    fila.push_back(board[i][j] - '0');
                }
            }
            mat.push_back(fila);
        }

        map< pair<int,int>, int> visited;
        queue< pair< vector<vector<int> > , int > > bfsq;
        bfsq.push({mat, 0});

        while(!bfsq.empty()){
            cout<<"BFS"<<endl;
            pair< vector<vector<int> >, int > state = bfsq.front();
            bfsq.pop();
            cout<<state.second<<" <= "<<coords.size()<<endl;
            cout<<state.first[coords[state.second].first][coords[state.second].second]<<", "<<coords[state.second].first<<", "<<coords[state.second].second<<endl;
            if(state.second <= coords.size() && isValid(state.first, coords[state.second].first, coords[state.second].second) && visited.find(coords[state.second]) == visited.end()){
                if(isSolved(state.first)){
                    cout<<"SOLVED"<<endl;
                    for(int i = 0; i < 9; i++){
                        for(int j = 0; j < 9; j++){
                            board[i][j] = '0' + state.first[i][j];
                        }
                    }
                    return;
                }
                visited[coords[state.second]]++;
                //expand
                cout<<"EXPANDING"<<endl;
                for(int i = 1; i <= 9; i++){
                    vector<vector<int> > cp;
                    for(int j = 0; j < 9; j++){
                        vector<int> fila;
                        for(int k = 0; k < 9; k++){
                            fila.push_back(state.first[j][k]);
                        }
                        cp.push_back(fila);
                    }
                    cout<<"----"<<endl;
                    cout<<coords[state.second].first<<", "<<coords[state.second].second<<endl;
                    cp[coords[state.second].first][coords[state.second].second] = i;
                    
                    for(int j = 0; j < 9; j++){
                        for(int k = 0; k < 9; k++){
                            cout<<cp[j][k]<<" ";
                        }cout<<endl;
                    }
                    

                    bfsq.push({cp, state.second + 1});
                    cout<<"adding coord: "<<state.second + 1<<endl;
                }
                
            }
        }

        
        return;
    

    }
};