#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, K, cnt;
	cin >> N >> K;
	for (i = 1; i <= N; i++) q.push(i);
	cnt = 1;
	cout << "<";
	while (!q.empty()) {
		if (q.size() == 1) { cout << q.front() << ">"; }
		else {
			if (cnt == K) {
				cout << q.front() << ", ";
				cnt = 1;
			}
			else {
				q.push(q.front());
				cnt++;
			}
		}
		q.pop();
	}
}

