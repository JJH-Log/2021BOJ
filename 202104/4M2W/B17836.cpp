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


typedef struct posInfo{
	int x;
	int y;
	int t;
} pos;

pos get_pos(int x, int y, int t) {
	pos temp; temp.x = x; temp.y = y; temp.t = t; return temp;
}

vector<vector<int>> v;
queue<pos> q;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int N, M, T;
	int i, j, result;
	int t1, t2, t3;
	scanf("%d %d %d", &N, &M, &T);
	v.resize(N + 2, vector<int>(M + 2, -1));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	result = 10001;
	v[1][1] = -1;
	v[N][M] = -2;
	q.push(get_pos(1,1,0));
	while (!q.empty()) {
		t1 = q.front().x;
		t2 = q.front().y;
		t3 = q.front().t;
		q.pop();
		if (t3 <= T) {
			for (int k = 0; k < 4; k++) {
				if (k == 0) { i = -1; j = 0; }
				if (k == 1) { i = 1; j = 0; }
				if (k == 2) { i = 0; j = -1; }
				if (k == 3) { i = 0; j = 1; }
				if (v[t1 + i][t2 + j] == 0) {
					v[t1 + i][t2 + j] = -1;
					q.push(get_pos(t1 + i, t2 + j, t3 + 1));
				}
				if (v[t1 + i][t2 + j] == -2) result = min(result, t3 + 1);
				if (v[t1 + i][t2 + j] == 2) {
					result = min(result, t3 + 1 + (abs(N - (t1 + i)) + abs(M - (t2 + j))));
					v[t1 + i][t2 + j] = -1;
					q.push(get_pos(t1 + i, t2 + j, t3 + 1));
				}
			}
		}
	}
	if (result > T) printf("Fail");
	else printf("%d", result);
	return 0;
}

