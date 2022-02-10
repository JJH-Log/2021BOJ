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

	string s1, s2;
	cin >> s1 >> s2;
	int result = 0;
	v.resize(s1.size(), vector<int>(s2.size(), 0));
	for (int j = 0; j < s2.size(); j++) if (s1[0] == s2[j]) v[0][j] = 1;
	for (int i = 0; i < s1.size(); i++) if (s1[i] == s2[0]) v[i][0] = 1;
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				result = max(v[i][j], result);
			}
		}
	}
	cout << result;
	
	return 0;
}