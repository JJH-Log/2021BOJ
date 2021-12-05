#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N, S;
vector<int> v;
map<int, int> l, r;


void backTracking(int idx, int e, int total, bool isFirst) {
	for (int i = idx; i < e; i++) {
		backTracking(i + 1, e, total + v[i], false);
	}
	if (isFirst) return;
	if (e == N) {
		if (!r.count(total)) r[total] = 1;
		else r[total]++;
	}
	else {
		if (!l.count(total)) l[total] = 1;
		else l[total]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (N == 1) {
		cout << (v[0] == S);
		return 0;
	}
	backTracking(0, N / 2, 0, true);
	backTracking(N / 2, N, 0, true);
	int result = 0;
	for (auto num : l) {
		if (r.count(S - num.first)) result += (l[num.first] * r[S - num.first]);
		if (num.first == S) result += num.second;
	}
	for (auto num : r) if (num.first == S) result += num.second;
	cout << result;
	
	return 0;
}