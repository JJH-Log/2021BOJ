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
stack<int> s;

vector<int> getDiviser(int X) {
	vector<int> result;
	for (int i = 1; i <= X; i++) {
		if (!(X % i)) result.push_back(i);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, temp;
	cin >> N;
	v = getDiviser(N);
	L = v.size();
	for (int i = 0; i < L / 2; i++) {
		temp = v[i] + v[L - 1 - i];
		if (!(temp % 2)) {
			s.push(temp / 2);
		}
	}
	if (!s.size()) cout << "-1\n";
	else {
		while (!s.empty()) {
			cout << s.top() << '\n';
			s.pop();
		}
	}

	return 0;
}