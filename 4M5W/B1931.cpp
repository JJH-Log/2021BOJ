#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) return a.first > b.first;
		else return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, t1, t2;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t1 >> t2;
		pq.push(make_pair(t1, t2));
	}
	int result = 1;
	int tr = pq.top().second;
	pq.pop();
	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		if (temp.first >= tr) {
			result++;
			tr = temp.second;
		}
	}
	cout << result;
}

