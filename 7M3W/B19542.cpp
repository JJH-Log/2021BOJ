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

vector<vector<int>> v;
int N, S, D;
pair<int, int> dfs(int parent, int X) { //나의 depth와 return 의 차이가 D보다 크면 return값의 first를 result에 쌓기
	pair<int, int> result = { 0, 0 };
	pair<int, int> ans;
	for (int i = 0; i < v[X].size(); i++) {
		int next = v[X][i];
		if (parent != next) {
			ans = dfs(X, next);
			result.first += ans.first;
			result.second = max(result.second, ans.second);
		}
	}
	result.second++;
	if (result.second > D) result.first++;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y;
	cin >> N >> S >> D;
	S--;
	v.resize(N);
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		x--, y--;
		if(y != S) v[x].push_back(y);
		if(x != S) v[y].push_back(x);
	}
	cout << max(0, 2 * (dfs(-1, S).first - 1));

	return 0;
}