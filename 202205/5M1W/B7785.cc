#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

map<string, bool> m;
int T;
string name, op;
vector<string> res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> name >> op;
		if (op == "enter") m[name] = true;
		else m[name] = false;
	}
	map<string, bool>::iterator it;
	it = m.end();
	it--;
	while (true) {
		if (it->second) cout << it->first << '\n';
		if (it == m.begin()) break;
		it--;
	}


	
	return 0;
}
