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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1;

    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 != s2) {
        cout << s2.size();
        return 0;
    }
    s1 = s1.substr(1);
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 == s2) cout << -1;
    else cout << s2.size();

    return 0;
}