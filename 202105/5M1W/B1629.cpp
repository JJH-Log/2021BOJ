#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> b; //bit
vector<int> r; //result

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long x, y, z, result;
	cin >> x >> y >> z;
	x = x % z;

	while (y) {
		b.push_back(y % 2);
		y /= 2;
	}

	r.push_back(x);
	while (r.size() != b.size()) {
		x = (x * x) % z;
		r.push_back(x);
	}
	result = 1;
	for (int i = 0; i < b.size(); i++) {
		if (b[i]) result = (result * r[i]) % z;
	}
	cout << result;
}