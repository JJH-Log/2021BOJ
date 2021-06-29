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

vector<int> t;
vector<int> v;

int N, M;

void ans(int cnt, int pos) {
	if (cnt == M) {
		for (const auto& it : v) cout << it << ' ';
		cout << "\n";
		return;
	}
	int before = 0;
	for (int i = pos; i < N; i++) {
		if(!before || t[i] != before) {
			v[cnt] = t[i];
			ans(cnt + 1, i);
			before = t[i];
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(M, 0);
	t.resize(N, 0);

	for (int i = 0; i < N; i++) cin >> t[i];
	sort(t.begin(), t.end());
	ans(0, 0);
}