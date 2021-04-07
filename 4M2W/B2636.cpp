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

vector<vector<int>> v;

bool checkVal(int X, int Y, int tar, int update) {
	if (v[X][Y] == tar) {
		v[X][Y] = update;
		return true;
	}
	return false;
}

int main() {
	int i, j, N, M;

	cin >> N >> M;

	if ((N == 1) && (M == 1)) {
		cin >> N;
		if(N == 1) printf("%d\n%d", 1, 1);
		return 0;
	}
	v.resize(N + 2, vector<int>(M + 2, 0));

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &v[i][j]);
			if ((i == 1) || (i == N) || (j == 1) || (j == M)) {
				if (v[i][j] == 0) v[i][j] = -1;
			}
		}
	}

	int left = 0;
	int result = 0;
	int phase = -1;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (v[i][j] == 1) left++;
		}
	}

	bool flag1 = true;
	while (true) {
		result = left;
		left = 0;
		flag1 = true;
		while(true) {
			if (flag1 == false) break;
			flag1 = false;
			for (i = 1; i <= N; i++) {
				for (j = 1; j <= M; j++) {
					if (v[i][j] == phase) {
						flag1 = flag1 | checkVal(i + 1, j, 0, phase);
						flag1 = flag1 | checkVal(i - 1, j, 0, phase);
						flag1 = flag1 | checkVal(i, j + 1, 0, phase);
						flag1 = flag1 | checkVal(i, j - 1, 0, phase);
						flag1 = flag1 | checkVal(i + 1, j, 1, phase - 1);
						flag1 = flag1 | checkVal(i - 1, j, 1, phase - 1);
						flag1 = flag1 | checkVal(i, j + 1, 1, phase - 1);
						flag1 = flag1 | checkVal(i, j - 1, 1, phase - 1);
					}
				}
			}
		}
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (v[i][j] == 1) left++;
			}
		}
		if (left == 0) break;
		phase--;
	}
	printf("%d\n%d", (-1)*phase, result);
}

