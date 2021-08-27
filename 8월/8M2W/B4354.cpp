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
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v; //fail vector

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, len;
	string s;

	while (true) {
		cin >> s;
		if (s == ".") break;
		len = s.size();
		v.resize(len, 0);

		for (i = 1, j = 0; i < len; i++) {
			while (j > 0 && s[i] != s[j]) j = v[j - 1];
			if (s[i] == s[j]) v[i] = ++j;
		}
		if (!(len % (len - j))) cout << len / (len - j) << '\n';
		else cout << 1 << '\n';
		v.clear();
	}


	return 0;
}