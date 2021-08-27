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

map<string, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, result;
	string s, tar;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> s;
		if (m.count(s)) m[s]++;
		else m[s] = 1;
	}
	result = 0;
	for (auto& it : m) if (it.second > result) result = it.second, tar = it.first;
	cout << tar;

	return 0;
}