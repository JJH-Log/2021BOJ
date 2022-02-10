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

vector<string> v;
vector<bool> w;


bool isSame(string s1, string s2, int i) {
	string s = s1.substr(i, s2.size());
	return s == s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	int i, j, N;
	cin >> s1 >> N;
	v.resize(N);
	w.resize(s1.size(), false);
	for (i = 0; i < N; i++) {
		cin >> v[i];
		if (isSame(s1, v[i], 0)) w[v[i].size() - 1] = true;
	}
	for (i = 0; i < w.size(); i++) {
		if (w[i]) for (j = 0; j < v.size(); j++) if (isSame(s1, v[j], i + 1)) w[i + v[j].size()] = true;
	}
	cout << w[s1.size() - 1];
	return 0;
}