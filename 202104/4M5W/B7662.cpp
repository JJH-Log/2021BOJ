#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

map<int, int> m;
map<int, int>::iterator it;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char c;
	int i, t, T, N, temp;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		m.clear();
		for (i = 0; i < N; i++) {
			cin >> c;
			cin >> temp;
			if (c == 'D') {
				if (m.size() != 0) {
					if (temp == 1) it = --m.end();
					else it = m.begin();
					temp = it->first;
					m[temp]--;
					if (m[temp] == 0) m.erase(temp);
				}
			}
			if (c == 'I') {
				if (!m.count(temp)) m[temp] = 1; //Automatically sorted (ascend)
				else m[temp]++;
			}
		}
		if (m.size() == 0) cout << "EMPTY\n";
		else {
			it = --m.end();
			cout << it->first << " ";
			it = m.begin();
			cout << it->first << "\n";
		}
	}
	
	return 0;
}