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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, t;
	cin >> T;
	while (T--) {
		string op;
		cin >> op;
		if (op == "push") cin >> t, q.push(t);
		else if (op == "size") cout << q.size() << '\n';
		else if (op == "empty") cout << (int)q.empty() << '\n';
		else {
			if (q.empty()) cout << "-1\n";
			else if (op == "pop") cout << q.front() << '\n', q.pop();
			else if (op == "front") cout << q.front() << '\n';
			else if (op == "back") cout << q.back() << '\n';
		}
	}

	return 0;
}
