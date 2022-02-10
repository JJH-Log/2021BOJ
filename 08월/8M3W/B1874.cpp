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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

stack<int> s;
queue<char> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, now, t;

	cin >> N;
	now = 1;
	for (i = 0; i < N; i++) {
		cin >> t;
		while (now <= t) {
			s.push(now);
			ans.push('+');
			now++;
		}
		if (s.top() == t) {
			s.pop();
			ans.push('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << '\n';
		ans.pop();
	}

	return 0;
}