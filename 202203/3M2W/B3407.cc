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
int dp[50001], sz;
bool vtd[50001];
char c1[] = { 'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u' };
char c2[][3] = {
	"ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
};

queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof dp);
		memset(vtd, 0, sizeof vtd);
		cin >> s;
		sz = s.size();
		q.push(0);
		vtd[0] = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto t : c1) {
				if (s[now] == t && !vtd[now + 1]) {
					vtd[now + 1] = true;
					q.push(now + 1);
				}
			}
			for (auto t : c2) {
				if (now + 1 < sz && s[now] == t[0] && s[now + 1] == t[1] && !vtd[now + 2]) {
					vtd[now + 2] = true;
					q.push(now + 2);
				}
			}
		}
		cout << (vtd[sz] == 1 ? "YES" : "NO") << '\n';
	}

	return 0;
}