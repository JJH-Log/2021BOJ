#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
vector<vector<int>> d;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j, k;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	d.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j];
			if (!v[i][j]) v[i][j] = 10000;
		}
	}
	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (v[i][j] == 10000) v[i][j] = 0;
			else v[i][j] = 1;
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}