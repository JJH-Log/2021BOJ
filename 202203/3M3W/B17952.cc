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

struct info {
	int point, left;
};

stack<info> s;
int N;
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x;
		if(x){
			cin >> y >> z;
			s.push({y, z});
		}
		if(!s.empty()){
			s.top().left--;
			if(s.top().left == 0){
				res += s.top().point;
				s.pop();
			}
		}
	}
	cout << res;
	
	return 0;
}