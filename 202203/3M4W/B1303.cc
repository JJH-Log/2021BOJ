#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos{
	int x, y;
};

int N, M;
int v[100][100];
bool vtd[100][100];
int res[2];
string s;
queue<pos> q;

bool isInRange(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		for (int j = 0; j < M; j++) if(s[j] == 'B') v[i][j] = 1;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (!vtd[i][j]){
				int cnt = 1;
				q.push({i, j});
				vtd[i][j] = true;
				while(!q.empty()){
					pos now = q.front();
					q.pop();
					for (int k = 0; k < 4; k++){
						int dx = now.x + "2011"[k] - '1';
						int dy = now.y + "1120"[k] - '1';
						if(isInRange(dx, dy) && !vtd[dx][dy] && v[dx][dy] == v[i][j]){
							cnt++;
							q.push({dx, dy});
							vtd[dx][dy] = true;
						}
					}
				}
				res[v[i][j]] += cnt * cnt;
			}
		}
	}
	cout << res[0] << ' ' << res[1];

	return 0;
}