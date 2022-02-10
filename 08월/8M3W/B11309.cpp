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
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<lld>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j;
	v.resize(32, vector<lld>(32, 0)); //달걀 개수, 사용 횟수
	for (i = 0; i < 32; i++) v[0][i] = i + 1;
	for (i = 0; i < 32; i++) v[i][0] = 1;
	for (i = 1; i < 32; i++) {
		for (j = 1; j < 32; j++) v[i][j] = v[i][j - 1] + v[i - 1][j - 1] + 1;
	}
	
	int x, y;
	int t, T, ans;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> x >> y;
		for (ans = 0; ans < 32; ans++) {
			if (v[y - 1][ans] >= x) break;
		}
		if (ans == 32) cout << "Impossible\n";
		else cout << ans + 1 << '\n';
	}

	return 0;
}