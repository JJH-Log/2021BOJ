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
vector<int> v2;
int N, M;

void ans(int cnt) {
	int i,j;
	bool FLAG;
	for (i = 0; i < N; i++) {
		FLAG = true;
		for (j = 0; j < cnt; j++) {if (v[j] == v2[i]) FLAG = false; }
		if (FLAG) {
			v[cnt] = v2[i];
			if (cnt == M - 1) {
				for (j = 0; j < M; j++) cout << v[j] << " ";
				cout << "\n";
			}
			else ans(cnt + 1);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v2.resize(N);
	v.resize(M);
	for (int i = 0; i < N; i++) cin >> v2[i];
	sort(v2.begin(), v2.end());
	ans(0);

	return 0;
}
