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

vector<int> v;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string T;
	int i, j, N, M;
	getline(cin, S);
	getline(cin, T);
	N = S.size();
	M = T.size();
	v.resize(M, 0);
	
	//make fail
	for (i = 1, j = 0; i < M; i++) {
		while (j > 0 && T[i] != T[j]) j = v[j - 1];
		if (T[i] == T[j]) v[i] = ++j;
	}

	//KMP
	for (i = 0, j = 0; i < N; i++) {
		while (j > 0 && S[i] != T[j]) j = v[j - 1];
		if (S[i] == T[j]) {
			if (j == M - 1) {
				ans.push_back(i - M + 2);
				j = v[j];
			}
			else j++;
		}
	}

	cout << ans.size() << '\n';
	for (int it : ans) cout << it << ' ';

	return 0;
}