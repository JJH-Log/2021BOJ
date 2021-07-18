#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp;
	v.resize(41, 0);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		v[temp]++;
	}

	int allowCnt, powCnt;
	lld result;
	allowCnt = 2;
	powCnt = 0;
	result = 1;

	for (i = 0; i <= 40; i++) {
		if (v[i] > allowCnt) result = 0;
		else if (v[i] == 2) powCnt++;
		else if (v[i] == 1 && allowCnt != 1) powCnt++, allowCnt = 1;
		else if (v[i] == 0) allowCnt = 0;
	}

	cout << (result << powCnt);

	return 0;
}