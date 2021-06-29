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

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, t, T, result;
	int xr, yr;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		v1.resize(N);
		v2.resize(N);
		for (i = 0; i < N; i++) {
			cin >> xr >> yr;
			v1[i] = make_pair(xr, yr);
			v2[i] = make_pair(yr, xr);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		xr = N + 1;  yr = N + 1;
		i = 0; result = 0;
		while (true) {
			if (i + 1 > xr || i + 1 > yr) break;
			if (v1[i].first == v1[i].second) {
				result++;
				break;
			}
			if (v1[i].first < xr && v1[i].second < yr) { result++; yr = v1[i].second; }
			if (v2[i].first < yr && v2[i].second < xr) { result++; xr = v2[i].second; }
			i++;
		}
		cout << result << "\n";
		v1.clear();
		v2.clear();
	}

	return 0;
}