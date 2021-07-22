#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<bool>> w; //check visited

pair<int, int> simulation(pair<int, int> start) {
	pair<int, int> pos = start;
	pair<int, int> next;
	int i, x, y, dir, ndir;

	for (i = 0; i < 4; i++) {
		x = pos.first + "1201"[i] - '1';
		y = pos.second + "2110"[i] - '1';
		if (v[x][y]) pos = { x, y }, dir = i;
	}
	while (true) {

		next = { 0, 0 };
		//cout << "now : " << pos.first << ' ' << pos.second << ' ' << dir << endl;
		x = pos.first + "1201"[dir] - '1';
		y = pos.second + "2110"[dir] - '1';

		if (v[x][y]) next = { x, y }, ndir = dir;
		else {
			for (i = 0; i < 4; i++) {
				if ((i != (dir ^ 3)) && (i != dir)) {
					//cout << "now i : " << i << endl;
					x = pos.first + "1201"[i] - '1';
					y = pos.second + "2110"[i] - '1';
					if (v[x][y]) next = { x, y }, ndir = i;
				}
			}
		}
		if (next.first == 0) break;
		pos = next; dir = ndir;
	}
	return pos;
}

pair<int, int> getCenter(pair<int, int> A, pair<int, int> B) {
	int x, y;
	if (A.first < B.first) x = B.first;
	else x = A.first;
	if (A.second < B.second) y = B.second;
	else y = A.second;
	if (!(x % 2)) x--;
	if (!(y % 2)) y--;
	return { x, y };
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, x, y, R, C;
	pair<int, int> posM;
	pair<int, int> posZ;
	pair<int, int> center;
	char block;
	string s;
	cin >> R >> C;
	v.resize(2 * R + 1, vector<int>(2 * C + 1, 0));
	w.resize(2 * R + 1, vector<bool>(2 * C + 1, false));
	for (i = 0; i < R; i++) {
		cin >> s;
		for (j = 0; j < C; j++) {
			x = 2 * i + 1;
			y = 2 * j + 1;
			if (s[j] == '|') v[x][y] = 1, v[x - 1][y] = 1, v[x + 1][y] = 1;
			if (s[j] == '-') v[x][y] = 1, v[x][y - 1] = 1, v[x][y + 1] = 1;
			if (s[j] == '1') v[x][y] = 1, v[x + 1][y] = 1, v[x][y + 1] = 1;
			if (s[j] == '2') v[x][y] = 1, v[x - 1][y] = 1, v[x][y + 1] = 1;
			if (s[j] == '3') v[x][y] = 1, v[x - 1][y] = 1, v[x][y - 1] = 1;
			if (s[j] == '4') v[x][y] = 1, v[x + 1][y] = 1, v[x][y - 1] = 1;
			if (s[j] == '+') v[x][y] = 1, v[x - 1][y] = 1, v[x + 1][y] = 1, v[x][y - 1] = 1, v[x][y + 1] = 1;
			if (s[j] == 'M') posM = { x, y };
			if (s[j] == 'Z') posZ = { x, y };
		}
	}
	posM = simulation(posM);
	posZ = simulation(posZ);
	center = getCenter(posM, posZ);
	x = center.first;
	y = center.second;
	if (v[x - 1][y] && v[x + 1][y] && v[x][y - 1] && v[x][y + 1]) block = '+';
	else if (v[x - 1][y] && v[x + 1][y]) block = '|';
	else if (v[x][y - 1] && v[x][y + 1]) block = '-';
	else if (v[x + 1][y] && v[x][y + 1]) block = '1';
	else if (v[x - 1][y] && v[x][y + 1]) block = '2';
	else if (v[x - 1][y] && v[x][y - 1]) block = '3';
	else if (v[x + 1][y] && v[x][y - 1]) block = '4';
	cout << center.first / 2 + 1 << ' ' << center.second / 2 + 1 << ' ' << block;

	return 0;
}