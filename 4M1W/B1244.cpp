#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<int> v;


int main() {
	int i, j, N, M;
	int G, K, p;
	cin >> N;
	v.resize(N + 2, -1);
	for (i = 1; i <= N; i++) cin >> v[i];
	v[0] = -2;

	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> G >> K;
		if (G == 1) {
			for (j = 1; j <= N; j++) {
				if (j % K == 0) v[j] = (v[j] + 1) % 2;
			}
		}
		else { //G : 2
			p = 0;
			v[K] = (v[K] + 1) % 2;
			while (true) {
				p++;
				if (v[K - p] != v[K + p]) break;
				v[K - p] = (v[K - p] + 1) % 2;
				v[K + p] = (v[K + p] + 1) % 2;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		cout << v[i] << " ";
		if (i % 20 == 0) cout << endl;
	}
}

