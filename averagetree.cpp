
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



struct Node {
	double data;
	struct Node *left, *right;
    int sumOfDescendants = 0;
    int numberOfDescendants = 0;
};

Node* newNode(double data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

bool isAvgOfDescendants(struct Node* node){
	if(node == NULL)
		return true;

	bool isLeft = isAvgOfDescendants(node->left);
    bool isRight = isAvgOfDescendants(node->right);
	//cout << node->data << " " << endl;
    if(node->right != NULL){
        node->sumOfDescendants += node->right->sumOfDescendants + node->right->data;
        node->numberOfDescendants += node->right->numberOfDescendants + 1;
    }
    if(node->left != NULL){
        node->sumOfDescendants += node->left->sumOfDescendants + node->left->data;
        node->numberOfDescendants += node->left->numberOfDescendants + 1;
    }
    if(node -> numberOfDescendants){
        if(node->sumOfDescendants * 1.0 / node->numberOfDescendants != node->data){
            //cout<<"fallo el promedio"<<endl;
            return false;
        }
    }

    return isLeft && isRight;
}

int main(){
    sync;
	struct Node* root = newNode(2);
	root->left = newNode(1);
	root->right = newNode(3);
	root->left->left = newNode(1);
	root->left->right = newNode(1);	
    root->right->left = newNode(3);
	root->right->right = newNode(3);


	cout<<(isAvgOfDescendants(root)?"TRUE":"FALSE")<<endl;

	return 0;
}
