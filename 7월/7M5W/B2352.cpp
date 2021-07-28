#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>::iterator it;
    int i, temp, N;
    v.push_back(0);
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> temp;
        it = lower_bound(v.begin(), v.end(), temp);
        if (it == v.end()) v.push_back(temp);
        else v[(int)(it - v.begin())] = temp;
    }
    cout << v.size() - 1;
    return 0;
}