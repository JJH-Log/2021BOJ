#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, N;
	long long cnt;
	cnt = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x;
		while (true) {
			if (s.empty() || s.top().first >= x) break;
			else cnt += s.top().second , s.pop();
		}
		if (s.empty()) s.push({ x, 1 });
		else if (s.top().first == x) {
			if (s.size() != 1) cnt += (s.top().second + 1);
			else cnt += s.top().second;
			s.top().second++;
		}
		else cnt += 1, s.push({ x, 1 });
	}
	cout << cnt;
	return 0;
}