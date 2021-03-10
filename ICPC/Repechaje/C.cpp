#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<vector<long double>>> powers;

string numberToBase(long long int input, long long int base, string alphabet) {
	string output = "";
	while(input > 0) {
		output = alphabet[input % base] + output;
		input /= base;
	}
	return output;
}

vector<vector<long double>> multiply(vector<vector<long double>> a, vector<vector<long double>> b, int size) {
	vector<vector<long double>> newMatrix;
	for(int i = 0; i < size; i++) {
		vector<long double> row;
		for(int j = 0; j < size; j++) {
			long double sum = 0;
			for(int k = 0; k < size; k++) {
				sum += a[i][k] * b[k][j];
			}
			row.push_back(sum);
		}
		newMatrix.push_back(row);
	}
	return newMatrix;
}

int main() {
	int size, steps;
	scanf("%d %d", &size, &steps);
	vector<vector<long double>> probabilityMatrix;
	for(int i = 0; i < size; i++) {
		vector<long double> probabilityRow;
		for(int j = 0; j < size; j++) {
			long double probability;
			scanf("%Lf", &probability);
			probabilityRow.push_back(probability);
		}
		probabilityMatrix.push_back(probabilityRow);
	}
	powers.push_back(probabilityMatrix);

	for(int n = 0; n < 13; n++) {
		powers.push_back(multiply(powers[n], powers[n], size));
	}

	vector<vector<long double>> finalMatrix;
	for(int i = 0; i < size; i++) {
		vector<long double> row;
		for(int j = 0; j < size; j++) {
			row.push_back(0);
		}
		finalMatrix.push_back(row);
	}
	for(int i = 0; i < size; i++) {
		finalMatrix[i][i] = 1;
	}

	vector<bool> addPower;
	string powersTwo = numberToBase(steps, 2, "01");
	reverse(powersTwo.begin(), powersTwo.end());

	for(int i = 0; i < powersTwo.size(); i++) {
		if(powersTwo[i] == '1') {
			finalMatrix = multiply(finalMatrix, powers[i], size);
		}
	}

	for(int i = 0; i < size; i++) {
		printf("%.10Lf\n", finalMatrix[0][i]);
	}
}