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
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


stack<lld> st;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto c : s) {
		if (c == '(') st.push(-2);
		if (c == '[') st.push(-3);

		if (c == ')') {
			lld now = 0;
			while (!st.empty() && st.top() != -2) {
				if (st.top() == -3) {
					cout << 0;
					return 0;
				}
				now += st.top();
				st.pop();
			}
			if (st.empty()) {
				cout << 0;
				return 0;
			}

			st.pop();
			if (now == 0) st.push(2);
			else st.push(now * 2);
		}
		if (c == ']') {
			lld now = 0;
			while (!st.empty() && st.top() != -3) {
				if (st.top() == -2) {
					cout << 0;
					return 0;
				}
				now += st.top();
				st.pop();
			}
			if (st.empty()) {
				cout << 0;
				return 0;
			}
			st.pop();
			if (now == 0) st.push(3);
			else st.push(now * 3);
		}
	}
	lld res = 0;
	while (!st.empty()) {
		if (st.top() == -2 || st.top() == -3) {
			cout << 0;
			return 0;
		}
		res += st.top();
		st.pop();
	}
	cout << res;


	return 0;
}