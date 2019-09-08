#include <iostream>
#include <vector>
#include <queue>

#define lli long long int

using namespace std;

int main() {
	vector<vector<lli> > tree;
	vector<lli> multipliers;
	vector<lli> money;
	int queries;
	cin >> queries;
	int startMult;
	cin >> startMult;
	int employees = 1;
	vector<lli> s;
	tree.push_back(s);
	multipliers.push_back(startMult);
	money.push_back(0);
	for(int i = 0; i < queries; i++) {
		int command;
		cin >> command;
		int employee;
		cin >> employee;
		employee--;
		if(command == 1) {
			tree[employee].push_back(employees++);
			vector<lli> v;
			tree.push_back(v);
			multipliers.push_back(startMult);
			money.push_back(0);
		} else if (command == 2) {
			int newMult;
			cin >> newMult;
			multipliers[employee] = newMult;
		} else if (command == 3) {
			lli bonus;
			cin >> bonus;
			queue<int> employeeList;
			employeeList.push(employee);
			while(employeeList.size() > 0) {
				money[employeeList.front()] += bonus * multipliers[employeeList.front()];
				for(int j = 0; j < tree[employeeList.front()].size(); j++) {
					employeeList.push(tree[employeeList.front()][j]);
				}
				employeeList.pop();
			}
		} else {
			cout << money[employee] << endl;
		}
	}
}
