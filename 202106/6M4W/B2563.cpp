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

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(100, vector<int>(100, 0));
	int T, i, j, t, a, b, cnt;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> a >> b;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				v[a + i][b + j] = 1;
			}
		}
	}
	cnt = 0;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (v[i][j]) cnt++;
		}
	}
	cout << cnt;
}