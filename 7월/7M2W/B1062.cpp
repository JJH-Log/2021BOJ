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

vector<bool> mask;
vector<set<int>> dict;
vector<int> counter;
int N;

void init() {
	mask.resize(26, true);
	mask[0] = false;
	mask[2] = false;
	mask[8] = false;
	mask[13] = false;
	mask[19] = false;
}

int check() {
	set<int>::iterator it;
	int cnt, result;
	result = 0;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (it = dict[i].begin(); it != dict[i].end(); it++) {
			if (!mask[(*it) - 'a']) cnt++;
		}
		if (cnt == counter[i]) result++;
	}
	return result;
}

int ans(int idx, int cnt, int mcnt) {
	int result = 0;
	if (cnt == mcnt) return check();
	for (int i = idx; i < 26; i++) {
		if (mask[i]) {
			mask[i] = false;
			result = max(result, ans(i + 1, cnt + 1, mcnt));
			mask[i] = true;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, K;
	
	string s, ts;
	cin >> N >> K;

	init();
	dict.resize(N);
	counter.resize(N, 0);
	for (i = 0; i < N; i++) {
		cin >> s;
		ts = s.substr(4, s.size() - 8);
		for (j = 0; j < ts.size(); j++) if (mask[ts[j] - 'a']) dict[i].insert(ts[j]);
		counter[i] = dict[i].size();
	}
	if (K < 5) cout << 0;
	else cout << ans(0, 0, K - 5);
	return 0;
}