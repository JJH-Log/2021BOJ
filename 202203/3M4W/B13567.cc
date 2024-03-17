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

string mv[2] = {"2101", "1012"};
int M, N;
struct robot{
	int x, y, d;
	robot (int x, int y, int d) : x(x), y(x), d(x){}
	void _move(int w){
		x += (mv[0][d] - '1') * w;
		y += (mv[1][d] - '1') * w;
	}
	void _turn(int op){
		if(op) d = (d + 1) % 4;
		else d = (d + 3) % 4;
	}
	bool isInRange(){ return x >= 0 && x <= M && y >= 0 && y <= M; }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	robot r(0, 0, 0);
	for(int i = 0; i < N; i++){
		string s;
		int x;
		cin >> s >> x;
		if(s == "TURN") r._turn(x);
		else{
			r._move(x);
			if(!r.isInRange()){
				cout << -1;
				return 0;
			}
		}
	}
	cout << r.x << ' ' << r.y;
	return 0;
}