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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, k;
	int N, K;
	v.resize(201, vector<int>(201, 0));
	
	for (i = 1; i <= 200; i++) {
		for (j = 0; j <= 200; j++) {
			if (i == 1) v[i][j] = 1;
			else {
				for (k = 0; k <= j; k++) v[i][j] = (v[i][j] + v[i - 1][j - k]) % MOD;
			}
		}
	}
	cin >> N >> K;
	cout << v[K][N];

	return 0;
}