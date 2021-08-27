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

vector<int> u; //unique
vector<bool> vtd; //selected

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M;

	cin >> N >> M;
	u.resize(N, 0);
	vtd.resize(M, false);

	int unique, temp;
	for (i = 0; i < N; i++) {
		unique = -1;
		for (j = 0; j < M; j++) {
			cin >> temp;
			if (temp) {
				if (unique == -1) unique = j;
				else unique = -2;
			}
		}
		u[i] = unique;
	}
	int result = 0;
	for (auto& now : u) {
		if (now == -2) result++;
		else if(now >= 0){
			if (!vtd[now]) vtd[now] = true;
			else result++;
		}
	}
	if (result) cout << result - 1;
	else cout << result;
	return 0;
}