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
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

pair<int, int> qr[9];
bool v[18];
int ans[9];
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, x, y, cnt, result, result2;
	bool FLAG;
	for (i = 0; i < 9; i++) {
		cin >> x >> y;
		qr[i] = { x, y - 1 };
		ans[i] = false;
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 18; j++) v[j] = false;
		for (j = 0; j < 9; j++) {
			if (i == j) qr[j].first ^= 1;
			v[qr[j].second + 9 * qr[j].first] = true;
			if (i == j) qr[j].first ^= 1;
		}
		cnt = result = 0;
		FLAG = true;
		for (j = 0; j < 9; j++) {
			if (!v[j] && v[j + 9]) cnt++, result = j;
			if (!v[j] && !v[j + 9]) s.push(j);
			if (v[j] && v[j + 9]) FLAG = false;
		}
		if (FLAG && cnt <= 1) {
			if (cnt == 1) ans[result] = true;
			else while (!s.empty()) ans[s.top()] = true, s.pop();
		}
	}
	cnt = result = 0;
	for (i = 0; i < 9; i++) {
		if (ans[i]) cnt++, result = i;
	}
	if (cnt == 1) cout << result + 1;
	else cout << -1;
	
	return 0;
}