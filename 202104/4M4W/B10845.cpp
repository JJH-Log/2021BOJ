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

	int i, N, temp;
	string s;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> temp;
			q.push(temp);
		}
		if (s == "pop") {
			if (!q.size()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if (s == "size") cout << q.size() << "\n";
		if (s == "empty") cout << q.empty() << "\n";
		if (s == "front") {
			if (!q.size()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		if (s == "back") {
			if (!q.size()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}

