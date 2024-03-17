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
#define MOD 1000000007
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


string tar = "[&*,;";

string S, types;
vector<string> var;
vector<string> v;

void _add(string s, int FLAG) {
	int i = 0;
	for (; i < s.size(); i++) if (tar.find(s[i]) != string::npos) break;
	var.push_back(s.substr(0, i));
	string tmp = "";

	if (!FLAG) v.push_back(s.substr(i));
	else {
		for (int j = i; j < s.size(); j++) {
			if (s[j] == ',' || s[j] == ';') continue;
			if (s[j] == ']') tmp += '[';
			else if (s[j] == '[') tmp += ']';
			else tmp += s[j];
		}
		reverse(tmp.begin(), tmp.end());
		v.push_back(tmp);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool FLAG = false;

	getline(cin, S);
	int before, cnt;
	before = cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ' ') {
			_add(S.substr(before, cnt), before);
			before = i + 1;
			cnt = 0;
		}
		else cnt++;
	}
	if (cnt) _add(S.substr(before, cnt), 1);

	for (int i = 1; i < v.size(); i++) cout << var[0] << v[0] << v[i] << ' ' << var[i] << ";\n";

	return 0;
}