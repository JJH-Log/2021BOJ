#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<pair<int,int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y;
	double result;
	scanf("%d", &N);
	v.resize(N + 1, { 0,0 });
	result = 0;
	for (i = 0; i < N; i++) {
		scanf("%d %d",&x, &y);
		if (!i) v[0] = v[N] = { x,y };
		else v[i] = { x,y };
	}
	for (i = 0; i < N; i++) {
		result += (double)v[i].first * v[i + 1].second;
		result -= (double)v[i].second * v[i + 1].first;
	}
	printf("%.1f", abs(result) / 2);
	return 0;
}