#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<pair<int, int>> w;
vector<vector<lld>> v;
int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> N >> K;
	v.resize(K, vector<lld>(N + 1, 0));
	w.resize(K);
	for (i = 0; i < K; i++) cin >> w[i].first >> w[i].second;
	for (j = 0; j + w[0].second <= N; j++) v[0][j + w[0].second] = w[0].first;
	for (i = 1; i < K; i++) {
		for (j = 0; j <= N; j++) {
			v[i][j] = v[i - 1][j];
			if (j >= w[i].second) v[i][j] = max(v[i][j], v[i - 1][j - w[i].second] + w[i].first);
		}
	}
	lld result = 0;
	for (j = 0; j <= N; j++) result = max(result, v[K - 1][j]);
	cout << result;
	
	return 0;
}