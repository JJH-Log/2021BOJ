#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

map<string, pair<string, int>> m;

string findRoot(string me) {
	if (m[me].second) {
		return me;
	}
	else return findRoot(m[me].first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, T, N;
	string s1, s2;
	string t1, t2;
	pair<string, int> temp1, temp2;
	cin >> T;
	for (i = 0; i < T; i++) {
		m.clear();
		cin >> N;
		for (j = 0; j < N; j++) {
			cin >> s1 >> s2;
			if (!m.count(s1)) m[s1] = make_pair(s1, 1);
			if (!m.count(s2)) m[s2] = make_pair(s2, 1);

			t1 = findRoot(s1);
			t2 = findRoot(s2);

			if (t1 > t2) swap(t1, t2);
			if (t1 == t2) cout << m[t1].second << "\n";
			else {
				cout << m[t1].second + m[t2].second << "\n";
				m[t1].second += m[t2].second;
				m[t2].second = 0;
				m[t2].first = m[t1].first;
			}
		}
	}
	return 0;
}