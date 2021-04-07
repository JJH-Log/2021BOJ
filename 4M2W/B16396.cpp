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

//vector<pair<int, int>> v;
vector<int> ar;
int main() {
	int i, j, x1, x2, N;
	cin >> N;
	int result = 0;
	//v.resize(N, make_pair(0, 0));
	ar.resize(10001, 0);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &x1, &x2);
		//v[i] = make_pair(x1, x2);
		for (j = x1; j < x2; j++) {
			ar[j] = 1;
		}
	}
	for (i = 0; i < 10001; i++) {
		if (ar[i] == 1) result++;
	}

	cout << result << endl;
	//sort(v.begin(), v.end());

}