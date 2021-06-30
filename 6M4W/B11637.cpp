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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, temp, t, T, N, ti, tn, cnt;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		ti = -1, tn = 0; cnt = 0;
		for (i = 1; i <= N; i++) {
			cin >> temp;
			if (temp > tn) ti = i, tn = temp;
			else if (temp == tn) ti = -1;
			cnt += temp;
		}
		if (ti == -1) cout << "no winner\n";
		else if (tn > cnt / 2) cout << "majority winner " << ti << '\n';
		else  cout << "minority winner " << ti << '\n';
	}
	return 0;
}