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
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
vector<vector<int>> w;
int N, M;
int L;

pair<int,int> check(int state, int mask) { //현재 취할 state / 현재의 mask
	int i, FLAG, cnt;
	int temp, before, next;
	temp = state; FLAG = 1; before = 0; cnt = 0; next = 0;
	while (temp) {
		if ((temp % 2) && before) return { -1, -1 };
		if (temp % 2) before = 1;
		else before = 0;
		temp /= 2;
	}
	for (i = 0; i < M; i++) {
		if (state & (1 << i)) {
			if (mask & (1 << i)) return { -1, -1 };
			if (i + 1 < M) next = (next | (1 << (i + 1)));
			if (i - 1 >= 0) next = (next | (1 << (i - 1)));
			cnt++;
		}
	}
	return { next, cnt };//다음 state, 배치에 사용된 학생 cnt
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, i, j, k, T, result;
	pair<int, int> temp;
	string s;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> M;
		L = pow(2, M);
		v.resize(N, 0);
		w.resize(N, vector<int>(L, -1));
		for (i = 0; i < N; i++) {
			cin >> s;
			k = 1;
			for (j = 0; j < M; j++) {
				if (s[j] == 'x') v[i] += k;
				k *= 2;
			}
		}
		for (i = 0; i < N; i++) w[i][v[i]] = 0;
		result = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < L; j++) {
				if (w[i][j] != -1) {
					for (k = 0; k < L; k++) {
						temp = check(k, j);
						
						if (temp.first != -1) {
							if (i != N - 1) {
								temp.first = temp.first | v[i + 1];
								w[i + 1][temp.first] = max(w[i + 1][temp.first], w[i][j] + temp.second);
							}
							else result = max(result, w[i][j] + temp.second);
						}
					}
				}
			}
		}
		cout << result << '\n';
		v.clear();
		w.clear();
	}
	return 0;
}