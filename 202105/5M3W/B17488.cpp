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

vector<int> v;
vector<vector<int>> su;
vector<vector<int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, temp;
	cin >> N >> M;
	v.resize(M + 1, 0);
	su.resize(M + 1);
	st.resize(M + 1);
	for (i = 1; i <= M; i++) cin >> v[i];
	for (i = 1; i <= N; i++) {
		while (true) {
			cin >> temp;
			if (temp == -1) break;
			su[temp].push_back(i);
		}
	}
	for (i = 1; i <= M; i++) {
		if (su[i].size() <= v[i]) {
			v[i] -= su[i].size();
			for (j = 0; j < su[i].size(); j++) st[su[i][j]].push_back(i);
			su[i].clear();
		}
	}
	for (i = 1; i <= N; i++) {
		while (true) {
			cin >> temp;
			if (temp == -1) break;
			su[temp].push_back(i);
		}
	}
	for (i = 1; i <= M; i++) {
		if (su[i].size() <= v[i]) {
			v[i] -= su[i].size();
			for (j = 0; j < su[i].size(); j++) st[su[i][j]].push_back(i);
		}
	}
	for (i = 1; i <= N; i++) {
		if (!st[i].size()) cout << "망했어요";
		else {
			sort(st[i].begin(), st[i].end());
			for (j = 0; j < st[i].size(); j++) cout << st[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}