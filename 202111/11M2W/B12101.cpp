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
#include <sstream>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


stack<int> s;
int N, K, cnt;
bool check;

void printing() {
	stack<int> rs;
	while (!s.empty()) {
		rs.push(s.top());
		s.pop();
	}
	s.push(rs.top());
	cout << rs.top();
	rs.pop();
	while (!rs.empty()) {
		s.push(rs.top());
		cout << '+' << rs.top();
		rs.pop();
	}
}

void backTracking(int num) {
	if (num > N || check) return;
	if (num == N) {
		if (cnt == K - 1) printing(), check = true;
		else cnt++;
	}
	for (int i = 1; i <= 3; i++) {
		s.push(i);
		backTracking(num + i);
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	cnt = 0, check = false;
	backTracking(0);
	if (!check) cout << -1;
	return 0;
}
