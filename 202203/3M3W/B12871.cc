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


int gcd(int X, int Y){
	if(X < Y) return gcd(Y, X);
	if(Y == 0) return X;
	return gcd(Y, X % Y);
}

string s1, s2, s3, s4;
int G;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> s1 >> s2;
	G = s1.size() * s2.size() / gcd(s1.size(), s2.size());
	s3 = "";
	s4 = "";
	for(int i = 0; i < G / s1.size(); i++) s3 += s1;
	for(int i = 0; i < G / s2.size(); i++) s4 += s2;

	cout << (s3 == s4);

	
	return 0;
}