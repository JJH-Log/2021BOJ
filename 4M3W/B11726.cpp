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


vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, N;
	cin >> N;
	v.resize(1001, 0);
	v[1] = 1;
	v[2] = 2;
	for (i = 3; i <= N; i++) v[i] = (v[i - 1] + v[i - 2]) % 10007;
	cout << v[N];
	return 0;
}
