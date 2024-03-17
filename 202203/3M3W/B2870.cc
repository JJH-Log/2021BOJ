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

int N;
string s;
vector<string> v;


bool compare(string A, string B) {
	if (A.size() == B.size()) return A < B;
	return A.size() < B.size();
}

string encode(string X) {
	int idx = 0;
	while (idx < X.size() && X[idx] == '0') idx++;
	if (idx == X.size()) return "0";
	else return X.substr(idx);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		string ans = "";
		for (auto c : s) {
			if (c >= '0' && c <= '9') ans += c;
			else {
				if (ans.size()) v.push_back(encode(ans));
				ans = "";
			}
		}
		if(ans.size()) v.push_back(encode(ans));
	}
	sort(v.begin(), v.end(), compare);
	for (auto now : v) cout << now << '\n';

	return 0;
}