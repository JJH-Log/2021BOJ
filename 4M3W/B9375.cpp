#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


vector<int> v;

int comb_sum(int P, int n) {
	vector<int> temp;
	temp.resize(n, 0);

	int i;
	for (i = 0; i < n; i++) temp[i] = i;
	
	int result = 0;
	int tmp = 0;
	int mp = 1;
	while (temp[0] != v.size() - n) {
		tmp = 1;
		for (i = 0; i < n; i++) tmp *= v[temp[i]];
		result += tmp;

		mp = 1;
		while (temp[n - mp] == v.size() - mp) mp++;
		temp[n - mp]++;
		for (i = mp; i >= 1; i--) temp[n - i] = temp[n - mp] + (mp - i);
	}
	tmp = 1;
	for (i = 0; i < n; i++) tmp *= v[temp[i]];
	result += tmp;

	return result;
}

//vector<int> v;



int ans() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> m;
	int i, N, result;
	string s1, s2;
	cin >> N;
	
	result = 0;
	for (i = 0; i < N; i++) {
		cin >> s1 >> s2;
		if (!m.count(s2)) m[s2] = 1;
		else m[s2]++;
	}
	v.clear();
	for (auto it = m.begin(); it != m.end(); ++it) v.push_back(it->second);
	for (i = 1; i <= v.size(); i++) result += comb_sum(v.size(), i);

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i,T;
	cin >> T;
	for (i = 0; i < T; i++) {
		cout << ans() << "\n";
	}

	return 0;
}
