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
	bool isValid(pos t){
		if(abs(t.x - x) == 2 && abs(t.y - y) == 1) return true;
		if(abs(t.x - x) == 1 && abs(t.y - y) == 2) return true;
		return false;
	}
};

int dpo(int x1, int x2) { return abs(x1 - x2); }
pos decode(string s){ return {s[0] - 'A', s[1] - '1'}; }


pos v[36];
bool vtd[6][6];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < 36; i++) {
		cin >> s;
		v[i] = decode(s);
	}
	vtd[v[0].x][v[0].y] = 1;

	for(int i = 1; i < 36; i++){
		if(vtd[v[i].x][v[i].y]){
			cout << "Invalid";
			return 0;
		}
		vtd[v[i].x][v[i].y] = 1;
		if(!v[i].isValid(v[i - 1])){
			cout << "Invalid";
			return 0;
		}
	}
	if(v[35].isValid(v[0])) cout << "Valid";
	else cout << "Invalid";
	return 0;
}