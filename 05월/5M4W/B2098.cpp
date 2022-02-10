#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

int N;
int FIN;
vector<vector<int>> w;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, i, j, next;
	cin >> N;
	FIN = (1 << N) - 1;
	v.resize(FIN + 1, vector<int>(N, (int)1e9));
	w.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> w[i][j];
	}
	v[0][0] = 0;
	for (t = 0; t < FIN; t++) {
		for (i = 0; i < N; i++) {
			if (v[t][i] != (int)1e9) {
				for (j = 0; j < N; j++) {
					if (w[i][j] && ((t & (1 << j)) == 0)) {
						next = t | (1 << j);
						v[next][j] = min(v[next][j], v[t][i] + w[i][j]);
					}
				}
			}
		}
	}
	cout << v[FIN][0];
	return 0;
}
