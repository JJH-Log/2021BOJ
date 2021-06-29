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

vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, ans;
	cin >> ans;

	v.resize(50001, 4);
	for (i = 1; i <= 223; i++) v1.push_back(i * i);
	for (i = 0; i < 223; i++) {
		for (j = 0; j < 223; j++) {
			if ((v1[i] + v1[j]) <= 50000) v2.push_back(v1[i] + v1[j]);
			else j = 223;
		}
	}
	sort(v2.begin(), v2.end());
	for (i = 0; i < 223; i++) {
		for (j = 0; j < v2.size(); j++) {
			if (v1[i] + v2[j] <= 50000) v3.push_back(v1[i] + v2[j]);
			else j = v2.size();
		}
	}
	for (i = 0; i < v3.size(); i++) v[v3[i]] = 3;
	for (i = 0; i < v2.size(); i++) v[v2[i]] = 2;
	for (i = 0; i < v1.size(); i++) v[v1[i]] = 1;
	
	
	cout << v[ans];
	return 0;
}
