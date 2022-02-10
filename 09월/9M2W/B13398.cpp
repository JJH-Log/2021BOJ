#define _CRT_SECURE_NO_WARNINGS
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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	int now, temp, sum1, sum2, maxv, result;
	cin >> N;
	maxv = -1001; sum1 = sum2 = 0; result = -1001;
	for (i = 0; i < N; i++) {
		cin >> temp;
		maxv = max(maxv, temp);
		sum2 = max({ 0, sum1, sum2 + temp });
		sum1 = max(0, sum1 + temp);
		result = max({ result, sum1, sum2 });
		//cout << sum1 << ' ' << sum2 << ' ' << result << endl;
	}
	if (maxv <= 0) cout << maxv;
	else cout << result;
	
	return 0;
}