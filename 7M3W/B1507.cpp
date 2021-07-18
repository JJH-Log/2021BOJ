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
vector<vector<int>> w; //for check
int N;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	w.resize(N, vector<int>(N, 1));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> v[i][j];
	}

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (i != k && k != j) {
					if (v[i][j] == v[i][k] + v[k][j]) w[i][j] = 0;
					else if (v[i][j] > v[i][k] + v[k][j]) {
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	int result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (w[i][j]) result += v[i][j];
		}
	}
	cout << result / 2;
	return 0;
}