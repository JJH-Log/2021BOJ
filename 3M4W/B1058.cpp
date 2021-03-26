#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<vector<int>> v;

int two_friend(int A, int B) {
	if (A == B) return 0;
	int i;
	for (i = 0; i < size(v); i++) {
		if ((i == A) && (v[i][B] == 1)) return 1;
		if ((i == B) && (v[A][i] == 1)) return 1;
		if ((v[A][i] + v[i][B]) == 2) return 1;
	}
	return 0;
}

int main() {

	int N, i, j;
	int num, result, count;
	string temp;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		cin >> temp;
		for (j = 0; j < N; j++) {
			if (temp[j] == 'Y') v[i][j] = 1;
			if (temp[j] == 'N') v[i][j] = 0;
		}
	}

	result = -1;
	for (i = 0; i < N; i++) {
		count = 0;
		for (j = 0; j < N; j++) {
			if (two_friend(i, j) == 1) count++;
		}
		result = max(result, count);
	}

	cout << result;
	return 0;
}