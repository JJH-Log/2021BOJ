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


vector<int> v, ans;
stack<int> st, rst;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string s;
	cin >> N;
	v.resize(N);
	ans.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'L') ans[i] = st.size();
		while ((!st.empty()) && st.top() < v[i]) st.pop();
		st.push(v[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == 'R') ans[i] = rst.size();
		while ((!rst.empty()) && rst.top() < v[i]) rst.pop();
		rst.push(v[i]);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << ' ';

	return 0;
}
