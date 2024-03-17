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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<lld>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, K;
	string result = "";
	cin >> N >> M >> K;
	v.resize(N + 1, vector<lld>(M + 1, 0));
	
	for (i = 1; i <= N; i++) v[i][0] = 1;
	for (i = 1; i <= M; i++) v[0][i] = 1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			v[i][j] = v[i - 1][j] + v[i][j - 1];
			if (v[i][j] > 1e9 + 1) v[i][j] = 1e9 + 1;
		}
	}
	i = N, j = M;
	if (K > v[N][M]) {
		cout << -1;
		return 0;
	}
	while (i > 0 && j > 0) {
		if (K <= v[i - 1][j]) result += "a", i--;
		else result += "z", K -= v[i - 1][j], j--;
	}
	while (i) result += "a", i--;
	while (j) result += "z", j--;
	cout << result;
	return 0;
}