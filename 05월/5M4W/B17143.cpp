#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct info {
	int s;
	int d;
	int z;
};

vector<map<int, info>> v; //vector with C , map with R
vector<map<int, info>> w; //copy vector
int R, C, M;

pair<int, int> getPos(int now, int s, int dx, int L) {
	int result = now + s * dx;
	if (result < 0) {
		if (result < -L) return { 2 * L + result, dx };
		else return { -result, -dx };
	}
	if (result > L) {
		if (result > 2 * L) return { result - 2 * L, dx };
		return { 2 * L - result, -dx };
	}
	return { result, dx };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, info>::iterator it;
	int i, j, r, c, s, d, z;
	int nr, nc, nd, ns, nz;
	int now, result;
	pair<int, int> temp;
	cin >> R >> C >> M;
	v.resize(C);
	w.resize(C);
	for (i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d <= 2) s = s % (2 * (R - 1));
		else s = s % (2 * (C - 1));
		v[c - 1][r - 1] = { s,d,z };
	}
	result = 0;
	for (c = 0; c < C; c++) {

		if (!v[c].empty()) {
			result += v[c].begin()->second.z;
			v[c].erase(v[c].begin());
		}

		for (i = 0; i < C; i++) {
			if (!v[i].empty()) {
				for (it = v[i].begin(); it != v[i].end(); it++) {
					ns = it->second.s;
					nd = it->second.d;
					nz = it->second.z;
					if (nd == 1) {
						temp = getPos(it->first, ns, -1, R - 1);
						if (temp.second == 1) nd = 2;
						nr = temp.first;
						nc = i;
					}
					else if (nd == 2) {
						temp = getPos(it->first, ns, 1, R - 1);
						if (temp.second == -1) nd = 1;
						nr = temp.first;
						nc = i;
					}
					else if (nd == 3) {
						temp = getPos(i, ns, 1, C - 1);
						if (temp.second == -1) nd = 4;
						nr = it->first;
						nc = temp.first;
					}
					else if (nd == 4) {
						temp = getPos(i, ns, -1, C - 1);
						if (temp.second == 1) nd = 3;
						nr = it->first;
						nc = temp.first;
					}
					if (w[nc].count(nr)) {
						if (w[nc][nr].z < nz) w[nc][nr] = { ns, nd, nz };
					}
					else w[nc][nr] = { ns, nd, nz };
				}
				v[i].clear();
			}
		}
		swap(v, w);
	}
	cout << result;
	return 0;
}
