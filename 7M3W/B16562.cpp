#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<pair<int, int>> v;
int N, M, K;

int find(int X) {
	if (v[X].first == X) return X;
	return v[X].first = find(v[X].first);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	v.resize(N);
	int i, x, y;
	for (i = 0; i < N; i++) cin >> v[i].second, v[i].first = i;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		x = find(x - 1);
		y = find(y - 1);
		if (v[x].second > v[y].second) v[x].first = y;
		else if (v[x].second < v[y].second) v[y].first = x;
		else if (x > y) v[x].first = y;
		else v[y].first = x;
	}
	int result = 0;
	for (i = 0; i < N; i++) {
		x = find(i);
		if (v[x].second) {
			result += v[x].second;
			v[x].second = 0;
		}
	}
	if (result > K) cout << "Oh no";
	else cout << result;
	return 0;
}