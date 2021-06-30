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

map<int, int> m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, cnt;
	for (i = 0; i < 25; i++) {
		cin >> t;
		m[t] = i;
	}
	v.resize(12, 0);
	cnt = 0;
	for (i = 0; i < 25; i++) {
		cin >> t;
		v[m[t] / 5]++;
		v[m[t] % 5 + 5]++;
		if (m[t] % 6 == 0) v[10]++;
		if (m[t] != 0 && m[t] != 24 && m[t] % 4 == 0) v[11]++;
		cnt = 0;
		for (j = 0; j < 12; j++) {
			if (v[j] == 5) cnt++;
		}
		if (cnt > 2) {
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}