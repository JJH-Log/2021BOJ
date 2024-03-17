#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> v;
long long result;
long long ans(int parent, int target) {
	int i;
	long long r1 = 0;
	long long r2 = 0;
	//cout << target << " : " << v[target].size() << endl;
	if (v[target].size() == 1) return 0;
	for (i = 0; i < v[target].size(); i += 2) {
		if (v[target][i] != parent) {
			r2 = max(r2, ans(target, v[target][i]) + v[target][i + 1]);
			if (r2 > r1) swap(r1, r2);
		}
	}
	result = max(result, r1 + r2);
	return max(r1, r2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, num, temp, dist;
	result = 0;
	cin >> N;
	v.resize(N + 1);
	for (i = 0; i < N - 1; i++) {
		cin >> num >> temp >> dist;
		v[num].push_back(temp);
		v[num].push_back(dist);
	}
	ans(0, 1);
	cout << result;
}

