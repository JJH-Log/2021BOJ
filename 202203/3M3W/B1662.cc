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


string s;
stack<lld> st;
lld res, tmp;

void _push(lld X){
	if(!st.empty()) st.top() += X;
	else res += X;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	reverse(s.begin(), s.end());


	bool FLAG = false;
	for(auto c : s){
		if(c == '(') FLAG = true;
		else if(c == ')') st.push(0);
		else{
			if(FLAG){
				tmp = st.top() * (c - '0');
				st.pop();
				_push(tmp);
				FLAG = false;
			}
			else _push(1);
		}
	}
	cout << res;

	return 0;
}