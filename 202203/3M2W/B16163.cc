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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

/*
 Reference : https://www.crocus.co.kr/1075
 Author : Lemonade255 
*/

string s;
int N, p, d[4000004];
lld res;

void manachers() {
    /*============================================
     string s : target string
     int p : end point of last palindrome
     int d[MAXN * 2] : array of manacher
     ============================================*/
    int sz = s.size();
    s += s.substr(1);
    for (int i = sz - 1; i > 0; i--) {
        s[2 * i] = s[i];
        s[2 * i - 1] = '#';
    }
    sz = s.size();
    for (int i = 1; i < sz; i++)
    {
        d[i] = p ? max(0, min(d[2 * p - i], p + d[p] - i)) : 0;
        while (i - d[i] - 1 >= 0 && i + d[i] + 1 < sz && s[i - d[i] - 1] == s[i + d[i] + 1]) d[i]++;
        if (i + d[i] > p + d[p]) p = i;
    }
    for (int i = 0; i < sz; i++) {
        d[i] += i % 2 == d[i] % 2;
        res += ((lld)d[i] + 1) / 2;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> s;
    manachers();
    cout << res;

	return 0;
}
