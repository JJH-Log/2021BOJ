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
int N, M;

void ans(int idx, int num) {
	int i,j;
	for (i = num; i <= N; i++) {
		v[idx] = i;
		if (idx == M - 1) {
			for (j = 0; j < M; j++) cout << v[j] << " ";
			cout << "\n";
		}
		else ans(idx + 1, i + 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(M);
	ans(0, 1);

	return 0;
}
