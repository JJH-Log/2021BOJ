#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v; //for tree
vector<int> w; // for check

pair<int, int> ans(int x) { //1, 0
	pair<int, int> temp;
	int i, A, B;
	A = 0; B = 0;
	w[x] = 0;
	for (i = 0; i < v[x].size(); i++) {
		if (w[v[x][i]]) {
			temp = ans(v[x][i]);
			A += min(temp.first, temp.second);
			B += temp.first;
		}
	}
	return { A + 1, B };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y;
	pair<int, int> result;
	cin >> N;
	v.resize(N + 1);
	w.resize(N + 1, 1);
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	result = ans(1);
	cout << min(result.first, result.second);
	return 0;
}
