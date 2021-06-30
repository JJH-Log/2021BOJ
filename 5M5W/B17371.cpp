#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<pair<int, int>> v;

double dist(pair<int, int> A, pair<int, int> B) {
	return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M;
	double temp, ans;
	pair<int, int> result;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
	ans = 1e9;
	for (i = 0; i < N; i++) {
		temp = 0;
		for (j = 0; j < N; j++) {
			if (i != j) temp = max(temp, dist(v[i], v[j]));
		}
		if (temp < ans) {
			ans = temp;
			result = v[i];
		}
	}
	cout << result.first << ' ' << result.second;
	return 0;
}