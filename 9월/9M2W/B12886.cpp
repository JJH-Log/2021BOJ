#define _CRT_SECURE_NO_WARNINGS
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
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct group {
	short a, b, c;
};

vector<set<pair<int, int>>> v;
queue<group> q;

group sorting(group g) {
	if (g.a < g.b) swap(g.a, g.b);
	if (g.b < g.c) swap(g.b, g.c);
	if (g.a < g.b) swap(g.a, g.b);
	return g;
}

void check_push(short x, short y, short z) {
	group g = sorting({ x, y, z });
	if (!v[g.a].count({ g.b, g.c })) {
		v[g.a].insert({g.b, g.c});
		q.push(g);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	short x, y, z;
	bool result = false;
	group temp, now;

	v.resize(1501);
	cin >> temp.a >> temp.b >> temp.c;
	temp = sorting(temp);
	if ((temp.a + temp.b + temp.c) % 3) {
		cout << 0;
		return 0;
	}
	if (temp.a == temp.b && temp.a == temp.c) {
		cout << 1;
		return 0;
	}
	x = (temp.a + temp.b + temp.c) / 3;
	q.push({ x, x, x });
	v[x].insert({ x, x });
	int cnt = 0;
	while (!q.empty() && !v[temp.a].count({ temp.b,temp.c })) {
		now = q.front();
		x = now.a; y = now.b; z = now.c;
		if (x == y && x == z) result = true;
		q.pop();
		if (z % 2 == 0) {
			check_push(x + z / 2, y, z / 2);
			check_push(x, y + z / 2 , z / 2);
		}
		if (y % 2 == 0) {
			check_push(x + y / 2, y / 2, z);
			check_push(x, y / 2, z + y / 2);
		}
		if (x % 2 == 0) {
			check_push(x / 2, y, z + x / 2);
			check_push(x / 2, y + x / 2, z);
		}
	}
	cout << v[temp.a].count({ temp.b, temp.c });

	return 0;
}