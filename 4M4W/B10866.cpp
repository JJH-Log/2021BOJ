#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

deque<int> dq;





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp;
	string s;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		if (s == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		if (s == "pop_front") {
			if (!dq.size()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if (s == "pop_back") {
			if (!dq.size()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if (s == "size") cout << dq.size() << "\n";
		if (s == "empty") cout << dq.empty() << "\n";
		if (s == "front") {
			if (!dq.size()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		if (s == "back") {
			if (!dq.size()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}
}

