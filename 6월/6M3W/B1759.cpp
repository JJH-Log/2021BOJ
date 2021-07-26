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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<char> v;
vector<char> w;
int L, C;
int c1, c2;

void ans(int cnt, int idx) {
	if (cnt == L) {
		if (c1 > 0 && c2 > 1) {
			for (int i = 0; i < L; i++) cout << w[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		w[cnt] = v[i];
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') c1++;
		else c2++;
		ans(cnt + 1, i + 1);
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') c1--;
		else c2--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	v.resize(C, 0);
	w.resize(L, 0);
	for (int i = 0; i < C; i++) cin >> v[i];
	sort(v.begin(), v.end());
	ans(0, 0);

	return 0;
}