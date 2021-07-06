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

vector<int> v1, v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, k, L1, L2, result, cnt, FLAG;
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) swap(s1, s2);
	L1 = s1.size();
	L2 = s2.size();
	v1.resize(L1);
	v2.resize(L2);
	result = L1 + L2;
	for (i = 0; i < L1; i++) v1[i] = s1[i] - '1';
	for (i = 0; i < L2; i++)	v2[i] = s2[i] - '1';
	i = 0; j = L2 - 1; cnt = 1;
	while(true){
		FLAG = 1;
		for (k = 0; j + k < L2; k++) {
			if (v1[i + k] + v2[j + k] > 1) FLAG = 0;
		}
		if (FLAG) result = min(result, L1 + L2 - cnt);
		if (j == 0) break;
		j--; cnt++;
	}
	while (true) {
		FLAG = 1;
		for (k = 0; i + k < L1 && k < L2; k++) {
			if (v1[i + k] + v2[j + k] > 1) FLAG = 0;
		}
		if (FLAG) result = min(result, L1 + L2 - cnt);
		if (i == L1 - 1) break;
		i++;
		if (i + L2 > L1) cnt--;
	}
	cout << result;
	return 0;
}