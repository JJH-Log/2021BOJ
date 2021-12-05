#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, M, temp, cnt;
	cin >> T;
	while (T--) {
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> temp;
			if (l.empty() || l.top() < temp) {
				r.push(temp);
				if (r.size() > l.size() + 1) l.push(r.top()), r.pop();
			}
			else if (l.top() >= temp) {
				l.push(temp);
				if (l.size() > r.size()) r.push(l.top()), l.pop();
			}
			if (i % 2 == 0) q.push(r.top());
		}
		cout << q.size() << '\n';
		cnt = 0;
		while (!q.empty()) {
			cout << q.front() << ' ', q.pop();
			cnt++;
			if (cnt % 10 == 0) cout << '\n';
		}
		if (cnt % 10) cout << '\n';
		l = priority_queue<int>();
		r = priority_queue<int, vector<int>, greater<int>>();
	}
	
	return 0;
}