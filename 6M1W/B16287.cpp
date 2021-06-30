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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
vector<vector<int>> w;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, M, N;
	cin >> M >> N;
	v.resize(N, 0);
	w.resize(400001, vector<int>(3, 0));
	for (i = 0; i < N; i++) cin >> v[i];
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			t = v[i] + v[j];
			if (!w[t][0]) w[t] = { 1,i,j };
		}
	}
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			t = M - v[i] - v[j];
			if (t >= 0 && t <= 400000) {
				if (w[t][0]) {
					if (w[t][1] != i && w[t][1] != j && w[t][2] != i && w[t][2] != j) {
						cout << "YES";
						return 0;
					}
				}
			}
		}
	}
	cout << "NO";
	return 0;
}