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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
int rm;

int dfs(int X) {
	int i, cnt, next;
	if (!v[X].size()) return 1;
	cnt = 0;
	for (i = 0; i < v[X].size(); i++) {
		next = v[X][i];
		if (next == rm) {
			if (v[X].size() == 1) return 1;
		}
		else cnt += dfs(next);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, N, temp, root;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else v[temp].push_back(i);
	}
	cin >> rm;
	if (root == rm) cout << 0;
	else cout << dfs(root);
	return 0;
}