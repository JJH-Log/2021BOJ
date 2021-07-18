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

set<int> dict;
vector<int> v;
vector<int> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, K, temp;
	lld result;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> temp;
		dict.insert(temp);
	}
	cin >> K;
	N = dict.size();
	v.resize(N, 0);
	i = 0;
	for (auto it = dict.begin(); it != dict.end(); i++, it++) v[i] = (*it);

	w.resize(1000 * v[N - 1] + 1, 0);
	for (i = 0; i < N; i++) w[v[i]] = 1;
	
	for (i = 1; i <= 1000 * v[N - 1]; i++) {
		if (w[i] == 0) {
			if (i % 2 == 0) cout << "holsoon win at " << i; 
			else cout << "jjaksoon win at " << i;
			return 0;
		}
		if (w[i] != K) {
			for (j = 0; j < N; j++) {
				if (i + v[j] <= 1000 * v[N - 1]) {
					if (w[i + v[j]] == 0 || w[i] + 1 < w[i + v[j]]) w[i + v[j]] = w[i] + 1;
				}
			}
		}
	}

	int mcnt, mstep;
	mstep = 0, mcnt = 0;
	for (i = 1; i <= 1000 * v[N - 1]; i++) {
		if (mcnt < w[i]) {
			mcnt = w[i];
			mstep = i;
		}
	}
	result = ((lld)K - mcnt + 1) * v[N - 1] + mstep;

	if (result % 2 == 0) cout << "holsoon win at " << result;
	else cout << "jjaksoon win at " << result;
	return 0;
}