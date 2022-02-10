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
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<vector<int>> w;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> N >> M;
	w.resize(N, vector<int>(N, 1e9));
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		x--, y--;
		w[x][y] = 1;
		w[y][x] = 1;
	}
	for (int i = 0; i < N; i++) w[i][i] = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
		}
	}
	int result, ri, rj;
	result = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int total = 0;
			for (int k = 0; k < N; k++) total += 2 * min(w[k][i], w[k][j]);
			if (total < result) {
				result = total;
				ri = i, rj = j;
			}
		}
	}
	cout << ri + 1 << ' ' << rj + 1 << ' ' << result;
	return 0;
}