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
#include <sstream>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, P;
int v[3000001];
vector<int> fibo;

int getGrundy(int X) {
	bool flag[20] = { 0, };
	for (int i = 0; X - fibo[i] >= 0; i++) flag[v[X - fibo[i]]] = 1;
	for (int i = 0; i < 20; i++) if (!flag[i]) return i;
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, x2;
	x1 = x2 = 1;
	fibo.push_back(1);
	while (x1 < 3000000) {
		x2 = x1 + x2;
		fibo.push_back(x2);
		swap(x1, x2);
	}

	for (int i = 1; i <= 3000000; i++) {
		v[i] = getGrundy(i);
		assert(v[i] != -1);
	}

	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P;
		result = result ^ v[P];
	}
	if (!result) cout << "cubelover";
	else cout << "koosaga";

	return 0;
}
