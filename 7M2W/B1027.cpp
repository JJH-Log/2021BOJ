#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
vector<vector<bool>> w;

bool isNotCollide(int x1, int x2) {
	int length, i;
	double div;
	length = x2 - x1;
	div = ((double)v[x2] - v[x1]) / length;
	for (i = 1; i < length; i++) {
		if (v[x1] + div * i <= v[x1 + i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, N, flag, result, cnt;
	cin >> N;
	v.resize(N, 0);
	w.resize(N, vector<bool>(N, 0));
	for (i = 0; i < N; i++) cin >> v[i];

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			flag = isNotCollide(i, j);
			w[i][j] = flag;
			w[j][i] = flag;
		}
	}
	result = 0;
	for (i = 0; i < N; i++) {
		cnt = 0;
		for (j = 0; j < N; j++) {
			if (w[i][j]) {
				cnt++;
			}
		}
		result = max(result, cnt);
	}
	cout << result;

	return 0;
}