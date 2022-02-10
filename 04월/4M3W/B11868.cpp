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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp, result;
	cin >> N;
	result = 0;
	for (i = 0; i < N; i++) {
		cin >> temp;
		result = result ^ temp;
	}
	if (result == 0) cout << "cubelover";
	else cout << "koosaga";
	return 0;
}
