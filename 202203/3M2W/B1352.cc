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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
bool res;
void solve(string now_string, char now_char, int lp, int rp);

string insert_char(string s, char now_char, int idx) {
	string s1 = s.substr(0, idx);
	s1 += now_char;
	return s1 + s.substr(idx);
}

void next_step(string now_string, char now_char, int lp, int rp) {
	for (int i = 0; i < rp; i++) now_string += now_char;
	now_string = insert_char(now_string, now_char, rp);
	solve(now_string, now_char + 1, rp + 1, now_string.size());
}

void solve(string now_string, char now_char, int lp, int rp) {
	if (rp > N || res) return;
	if (rp == N) {
		cout << now_string;
		res = true;
		return;
	}
	while (lp <= rp) next_step(now_string, now_char, lp, rp--);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	solve("A", 'B', 1, 1);
	if (!res) cout << -1;
	
	
	return 0;
}
