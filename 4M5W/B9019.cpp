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

queue<pair<int, string>> q;
vector<int> v; //visit

int DSLR(int target, int i) {
	if(i == 0) return (2 * target) % 10000;
	if (i == 1) {
		if (!target) return 9999;
		else return target - 1;
	}
	if (i == 2) return (target * 10) % 10000 + (target * 10) / 10000;
	if (i == 3) return (target % 10) * 1000 + (target / 10);
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, T, A, B, i, x;
	pair<int, string> temp;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> A >> B;
		v.resize(10000, 1);
		q.push(make_pair(A, ""));
		while (true) {
			temp = q.front();
			q.pop();
			if (temp.first == B) { cout << temp.second << "\n"; break; }
			for (i = 0; i < 4; i++) {
				x = DSLR(temp.first, i);
				if (v[x]) v[x] = 0, q.push(make_pair(x, temp.second + "DSLR"[i]));
			}
		}
		while (!q.empty()) q.pop();
		v.clear();
	}
	return 0;
}