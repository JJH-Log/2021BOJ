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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

bool cmp(string A, string B) {
	return A + B > B + A;
}
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	bool FLAG;
	cin >> N;
	v.resize(N);
	FLAG = true;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] != "0") FLAG = false;
	}
	if(v.size() > 1) sort(v.begin(), v.end(), cmp);
	if (FLAG) cout << 0;
	else for (int i = 0; i < N; i++) cout << v[i];

	return 0;
}
