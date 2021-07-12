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
set<pair<int, int>> s;
vector<lld> v;

int count(int mx, int my, int bx, int by) {
	int dx, dy;
	int FLAG, result;
	FLAG = 1, result = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dx = mx + "012"[i] - '1';
			dy = my + "012"[j] - '1';
			if (s.count({ dx, dy })) {
				if (FLAG) {
					if (dx == bx && dy == by) FLAG = 0;
					else return -1;
				}
				result++;
			}
		}
	}
	return result;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	v.resize(10, 0);
	cin >> H >> W >> N;
	int i, j, x, y;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		s.insert({ x - 1, y - 1 });
	}
	int dx, dy, ans;
	for (auto it = s.begin(); it != s.end(); it++) {
		x = it->first;
		y = it->second;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				dx = x + "012"[i] - '1';
				dy = y + "012"[j] - '1';
				if (dx > 0 && dx < H - 1 && dy > 0 && dy < W - 1) {
					ans = count(dx, dy, x, y);
					if (ans != -1) v[ans]++;
				}
			}
		}
	}

	v[0] = (lld)(H - 2) * (W - 2);
	for (i = 1; i < 10; i++) v[0] -= v[i];
	for (i = 0; i < 10; i++) cout << v[i] << '\n';


	return 0;
}