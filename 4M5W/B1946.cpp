#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, t;
	cin >> N;
	s.push(make_pair(0, 100000001));
	for (i = 1; i <= N; i++) {
		cin >> t;
		while (s.top().second < t) s.pop();
		cout << s.top().first << " ";
		s.push(make_pair(i, t));
	}
	return 0;
}