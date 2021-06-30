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

vector<int> v;
vector<int> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j;
	cin >> N;
	v.resize(N, 0);
	w.resize(N, 10000);
	for (i = 0; i < N; i++) cin >> v[i];
	w[0] = 0;
	for (i = 0; i < N; i++) {
		if(w[i] != 10000){
			for (j = 1; (j <= v[i]) && (i + j < N); j++) w[i + j] = min(w[i + j], w[i] + 1);
		}
	}
	if (w[N - 1] == 10000) cout << -1;
	else cout << w[N - 1];
	return 0;
}