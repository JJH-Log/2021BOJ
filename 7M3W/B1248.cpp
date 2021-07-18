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

vector<int> result;
vector<int> pass;
vector<vector<int>> v;
vector<vector<int>> w;
int N;

void printW() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << w[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

bool findAnswer(int cnt) {
	if (cnt == N) return true;
	int check = 0;

	if (pass[cnt]) {
		result[cnt] = 0;
		w[cnt][cnt] = 0;
		check = 0;
		for (int j = 0; j < cnt; j++) {
			w[j][cnt] = w[j][cnt - 1];
			if (v[j][cnt] == 0) {
				if (w[j][cnt] == 0) check++;
				else j = cnt;
			}
			else {
				if (v[j][cnt] * w[j][cnt] > 0) check++;
				else j = cnt;
			}
		}
		if (check == cnt) if (findAnswer(cnt + 1)) return true;
	}
	else {
		for (int i = 1; i <= 10; i++) {
			result[cnt] = i;
			w[cnt][cnt] = v[cnt][cnt] * i;
			check = 0;
			for (int j = 0; j < cnt; j++) {
				w[j][cnt] = w[j][cnt - 1] + w[cnt][cnt];
				if (v[j][cnt] == 0) {
					if (w[j][cnt] == 0) check++;
					else j = cnt;
				}
				else {
					if (v[j][cnt] * w[j][cnt] > 0) check++;
					else j = cnt;
				}
			}
			if (check == cnt) if (findAnswer(cnt + 1)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t;
	string s;
	cin >> N >> s;
	v.resize(N, vector<int>(N, 0));
	w.resize(N, vector<int>(N, 0));
	result.resize(N, 0);
	pass.resize(N, false);
	t = 0;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++, t++) {
			if (s[t] == '-') v[i][j] = -1;
			else if (s[t] == '+') v[i][j] = 1;
		}
	}
	for (i = 0; i < N; i++) if (v[i][i] == 0) pass[i] = 1;
	findAnswer(0);
	for (i = 0; i < N; i++) cout << v[i][i] * result[i] << ' ';

	return 0;
}