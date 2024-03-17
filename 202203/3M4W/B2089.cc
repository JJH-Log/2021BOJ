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

string solve(int X){
	string ans = "";
	int p[2] = {-1, 1};
	int t = 0;
	
	while(X){
		if(X % 2) {
			ans += '1';
			X += p[t % 2];
		}
		else ans += '0';
		X /= 2;
		t++;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	if(!N) cout << 0;
	else cout << solve(N);
	
	return 0;
}