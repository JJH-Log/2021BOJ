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

vector<int> v;
int D, N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, l, r, mid, ans;
	cin >> D >> N >> M;
	v.resize(N + 2, 0);
	for (i = 1; i <= N; i++) cin >> v[i];
	v[N + 1] = D;
	sort(v.begin(), v.end());
	l = 0, r = D;
	while (l <= r) {
		mid = (l + r) / 2;
		int pos = 0, cnt = 0;
		for (i = 1; i < v.size(); i++) {
			if (v[i] - v[pos] < mid) cnt++;
			else pos = i;
		}
		if (cnt > M) r = mid - 1;
		else l = mid + 1, ans = mid;
	}
	cout << ans;
	return 0;
}