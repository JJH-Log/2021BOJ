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

vector<int> parse(int N, int b){
	vector<int> ans;
	while(N){
		ans.push_back(N % b);
		N /= b;
	}
	return ans;
}

bool isPalindrome(vector<int> x){
	int i, j;
	for(i = 0, j = x.size() - 1; i <= j; i++, j--){
		if(x[i] != x[j]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N;
	bool FLAG;
	cin >> T;
	while(T--){
		cin >> N;
		FLAG = false;
		for(int i = 2; i <= 64; i++) FLAG = FLAG || isPalindrome(parse(N, i));
		cout << FLAG << '\n';
	}

	return 0;
}