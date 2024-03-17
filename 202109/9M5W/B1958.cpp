#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


int v[101][101][101];
int result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l1, l2, l3;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
	result = 0;
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			for (int k = 1; k <= l3; k++) {
				if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) v[i][j][k] = v[i - 1][j - 1][k - 1] + 1;
				else v[i][j][k] = max({ v[i - 1][j][k], v[i][j - 1][k], v[i][j][k - 1] });
			}
		}
	}
	cout << v[l1][l2][l3];

	return 0;
}