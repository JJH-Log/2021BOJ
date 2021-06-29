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

priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, t;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t;
		if (t == 0) {
			if (q.size() == 0) cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else q.push(t);
	}
}

