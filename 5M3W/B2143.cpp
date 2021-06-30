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
vector<int> w;
map<int, int> mv;
map<int, int> mw;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, T, N, M, temp;
	long long result;
	cin >> T >> N;
	v.resize(N + 1, 0);
	for (i = 1; i <= N; i++) {
		cin >> temp;
		v[i] = v[i - 1] + temp;
	}
	for (i = 1; i <= N; i++) {
		for (j = i; j <= N; j++) {
			temp = v[j] - v[i - 1];
			if (!mv.count(temp)) mv[temp] = 1;
			else mv[temp]++;
		}
	}
	cin >> M;
	w.resize(M + 1, 0);
	for (i = 1; i <= M; i++) {
		cin >> temp;
		w[i] = w[i - 1] + temp;
	}
	for (i = 1; i <= M; i++) {
		for (j = i; j <= M; j++) {
			temp = w[j] - w[i - 1];
			if (!mw.count(temp)) mw[temp] = 1;
			else mw[temp]++;
		}
	}
	result = 0;
	if (mv.size() <= mw.size()) {
		for (auto it = mv.begin(); it != mv.end(); it++) {
			if (mw.count(T - it->first)) result += (long long)it->second * mw[T - it->first];
		}
	}
	else {
		for (auto it = mw.begin(); it != mw.end(); it++) {
			if (mv.count(T - it->first)) result += (long long)it->second * mv[T - it->first];
		}
	}
	cout << result;
	return 0;
}