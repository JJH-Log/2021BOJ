#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<char> v = { '(', ')','+','-','*','/' };
stack<int> t;

int opefind(char c) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == c) return i + 2;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, temp;
	string s;
	cin >> s;
	//우선순위 : () < */ < +- 각각 234567 로 치환
	for (i = 0; i < s.size(); i++) {
		temp = opefind(s[i]);
		if (temp == 1) cout << s[i];
		if (temp == 2) t.push(temp);
		if (temp == 3) {
			while (t.top() != 2) {
				cout << v[t.top() - 2];
				t.pop();
			}
			t.pop();
		}
		if (temp >= 4) {
			while (!t.empty() && (t.top() / 2) >= (temp / 2)) {
				cout << v[t.top() - 2];
				t.pop();
			}
			t.push(temp);
		}
	}
	while (!t.empty()) {
		cout << v[t.top() - 2];
		t.pop();
	}
	return 0;
}