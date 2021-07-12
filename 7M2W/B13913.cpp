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

vector<int> v;
queue<int> q;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, now, temp;
	vector<int> next;
	v.resize(100001, 1000000);
	cin >> N >> K;
	v[N] = 0;
	q.push(N);
	while (v[K] == 1000000 && !q.empty()) {
		now = q.front();
		q.pop();
		next = { now - 1, now + 1, 2 * now };
		for (auto ne : next) {
			if (ne >=0 && ne < 100001 && v[ne] > v[now] + 1) v[ne] = v[now] + 1, q.push(ne);
		}
	}
	while (!q.empty()) q.pop();
	cout << v[K] << '\n';
	now = K;
	while (now != N) {
		next = { now + 1, now - 1 };
		if (now % 2 == 0) next.push_back(now / 2);
		for (auto ne : next) {
			if (ne >= 0 && ne < 100001 && v[ne] == v[now] - 1) temp = ne;
		}
		s.push(temp);
		now = temp;
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << K;
	return 0;
}