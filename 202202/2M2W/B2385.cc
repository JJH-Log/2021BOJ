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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N;
vector<string> v;
vector<string> v2;

bool cmp(string A, string B) {
	return B + A > A + B;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, res;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);

	bool FLAG, FLAG2;
	if (v[0][0] == '0') {
		for (int i = 0; i < N; i++) {
			if (v[i][0] != '0') {
				string temp = v[i];
				for (int j = 0; j < N; j++) if (j != i) temp += v[j];
				v2.push_back(temp);
			}
		}
		if (!v2.size()) res = "INVALID";
		else {
			sort(v2.begin(), v2.end(), cmp);
			res = v2[0];
		}
	}
	else {
		res = "";
		for (int i = 0; i < N; i++) res += v[i];
	}
	cout << res;

	return 0;
}
