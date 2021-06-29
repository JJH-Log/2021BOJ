#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
using namespace std;


queue<pair<int, int>> q;
vector<int> cnt;

int cntcheck(int target) {
	int i;
	for (i = target + 1; i <= 9; i++) {
		if (cnt[i]) return 0;
	}
	return 1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, t;
	int i, N, M, temp, ans, result;
	pair<int, int> now;
	cin >> T;
	for (t = 0; t < T; t++) { 
		cin >> N >> M;
		cnt.clear();
		cnt.resize(10, 0);
		for (i = 0; i < N; i++) {
			cin >> temp;
			cnt[temp]++;
			if(i == M) q.push(make_pair(temp, 1));
			else q.push(make_pair(temp, 0));
		}
		ans = 0; result = 0;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (cntcheck(now.first)) {
				cnt[now.first]--;
				ans++;
				if (now.second) result = ans;
			}
			else q.push(now);
		}
		cout << result << endl;
	}
}

