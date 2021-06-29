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

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; //절댓값을 second에

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, t;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t;
		if (t == 0) {
			if (pq.size() == 0) cout << "0\n";
			else {
				cout << pq.top().first << "\n";
				pq.pop();
			}
		}
		else pq.push(make_pair(t, abs(t)));
	}
}

