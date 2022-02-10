#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int T, K;
	cin >> T;
	while (T--) {
		pair<int, int> result = { 10001, -1 };
		cin >> s >> K;
		v.resize(26);
		for (int i = 0; i < s.size(); i++) {
			int tar = s[i] - 'a';
			v[tar].push_back(i);
			if (v[tar].size() >= K) {
				int last = v[tar].size() - 1;
				result.first = min(result.first, v[tar][last] - v[tar][last - K + 1]);
				result.second = max(result.second, v[tar][last] - v[tar][last - K + 1]);
			}
		}
		if (result.second == -1) cout << -1 << '\n';
		else cout << result.first + 1 << ' ' << result.second + 1 << endl;
		v.clear();
	}
	
	return 0;
}