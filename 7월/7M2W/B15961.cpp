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
vector<int> w;
int result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, D, k, c, i, j, L;
	int now, cnt;
	cin >> N >> D >> k >> c;
	v.resize(N, 0);
	w.resize(D, 0);
	for (i = 0; i < N; i++) cin >> v[i], v[i]--;
	for (i = 0; i < k; i++) v.push_back(v[i]);
	c--;
	result = 0, cnt = 0;
	for (i = 0; i < k; i++) {
		now = v[i];
		if (!w[now]) cnt++;
		w[now]++;
	}
	if (!w[c]) result = cnt + 1;
	else result = cnt;
	for (i = k; i < N + k; i++) {
		now = v[i];
		if (!w[now]) cnt++;
		w[now] ++;
		now = v[i - k];
		w[now] --;
		if (!w[now]) cnt--;

		if (!w[c]) result = max(result, cnt + 1);
		else result = max(result, cnt);
	}
	cout << result;

	return 0;
}