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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int H, W, N;
vector<vector<int>> v;

void star(int start_l, int start_r, int start_h, int end_h, int dir) {
	int gap = 0;
	bool FLAG;
	//cout << "PARAM : " << start_l << ' ' << start_r << ' ' << start_h << ' ' << end_h << ' ' << dir << endl;
	FLAG = 1;
	for (int i = start_h; FLAG; i += dir) {
		if (i == start_h) {
			for (int j = start_l; j <= start_r; j++) v[i][j] = 1;
		}
		else v[i][start_l + gap] = 1, v[i][start_r - gap] = 1;
		gap++;
		if (dir == 1) FLAG = i < end_h;
		else FLAG = i > end_h;
	}
	if (start_h != end_h) {
		gap = (gap - 1) / 2;
		star(start_l + gap + 1, start_r - gap - 1, (start_h + end_h) / 2, start_h + dir, -dir);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	H = (1 << N) - 1;
	W = (H << 1) - 1;
	v.resize(H, vector<int>(W, 0));
	if (N % 2) star(0, W - 1, H - 1, 0, -1);
	else star(0, W - 1, 0, H - 1, 1);

	string s;
	for (int i = 0; i < H; i++) {
		s = "";
		for (int j = 0; j < W; j++) {
			if (v[i][j] == 0) s += ' ';
			else cout << s + '*', s = "";
		}
		cout << '\n';
	}

	return 0;
}