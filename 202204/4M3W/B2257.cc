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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string s;
stack<int> st;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	for (auto c : s) {
		if (c == 'C') st.push(12);
		else if (c == 'O') st.push(16);
		else if (c == 'H') st.push(1);
		else if (c == '(') st.push(-1);
		else if (c == ')') {
			int total = 0;
			while (!st.empty()) {
				int now = st.top(); st.pop();
				if (now == -1) break;
				total += now;
			}
			st.push(total);
		}
		else {
			int now = st.top(); st.pop();
			st.push(now * (c - '0'));
		}
	}
	int res = 0;
	while (!st.empty()) res += st.top(), st.pop();
	cout << res; 

	return 0;
}