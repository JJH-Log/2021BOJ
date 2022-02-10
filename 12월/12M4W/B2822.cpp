#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

vector<pii> v;
int w[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 8; i++) {
		int x;
		cin >> x;
		v.push_back({ x, i });
	}
	sort(v.begin(), v.end(), greater<pii>());

	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += v[i].first;
		w[i] = v[i].second;
	}
	sort(w, w + 5);
	cout << ans << '\n';
	for (int i = 0; i < 5; i++) cout << w[i] << ' ';



	return 0;
}
