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
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<set<int>> v;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, temp, now;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		v[x - 1].insert(y - 1);
		v[y - 1].insert(x - 1);
	}
	cin >> temp;
	temp--;
	if (temp != 0 || v[temp].size() == 0) {
		cout << 0;
		return 0;
	}
	s.push(temp);
	for (i = 0; i < N - 1; i++) {
		if (s.empty()) {
			cout << 0;
			return 0;
		}
		cin >> temp;
		
		temp--;
		now = s.top();
		if (!v[now].count(temp)) {
			cout << 0;
			return 0;
		}
		v[now].erase(temp);
		v[temp].erase(now);
		if (!v[now].size()) s.pop();
		if (v[temp].size()) s.push(temp);
	}
	cout << 1;
	return 0;
}