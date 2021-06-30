#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int i, x, N;
	char t;
	v.resize(53, 0);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x;
		v[x]++;
	}

	while(!s.size()) getline(cin, s);

	for (i = 0; i < s.size(); i++) {
		t = s[i];
		if (t == ' ') v[0]--;
		else if (t >= 'A' && t <= 'Z') v[t - 'A' + 1]--;
		else if (t >= 'a' && t <= 'z') v[t - 'a' + 27]--;
	}

	for (i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			cout << "n\n";
			return 0;
		}
	}
	cout << "y\n";
	return 0;
}