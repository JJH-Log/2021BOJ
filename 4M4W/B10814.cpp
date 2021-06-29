#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
using namespace std;

vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, t1;
	v.resize(200, vector<string>());
	string t2;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t1 >> t2;
		v[t1 - 1].push_back(t2);
	}
	for (i = 0; i < 200; i++) {
		for (j = 0; j < v[i].size(); j++) cout << i + 1 << " " << v[i][j] << "\n";
	}
}

