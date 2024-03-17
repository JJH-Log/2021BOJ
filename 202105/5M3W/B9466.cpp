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

stack<int> st;
vector<int> v;
vector<int> w;
int cnt;
int check(int X) {
	if (w[X] == 2) { w[X] = 5; return 1; }
	if (w[X] == 0 || w[X] == 5) return 0;
	w[X]++;
	int flag = check(v[X]);
	if (w[X] == 5) return 0;
	if (flag) { w[X] = 5; return 1; }
	cnt++;
	w[X] = 0;
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, N, T;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		v.clear();
		w.clear();
		v.resize(N + 1, 0);
		w.resize(N + 1, 1);
		cnt = 0;
		for (i = 1; i <= N; i++) cin >> v[i];
		for (i = 1; i <= N; i++) if (w[i] == 1) check(i);
		cout << cnt << '\n';
	}
	return 0;
}