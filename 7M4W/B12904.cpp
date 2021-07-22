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

    string key, tar;
    cin >> key >> tar;

    int i, j, dir, now;
    i = 0, j = tar.size() - 1; dir = -1;
    while (j - i + 1 != key.size()) {
        if (dir == -1) now = j;
        else now = i;
        if (tar[now] != 'A' && tar[now] != 'B') {
            cout << 0;
            return 0;
        }
        else {
            if (dir == -1) j += dir;
            else i += dir;
            if (tar[now] == 'B') dir *= -1;
        }
    }
    if(dir == 1) reverse(key.begin(), key.end());
    if (key == tar.substr(i, j - i + 1)) cout << 1;
    else cout << 0;

    return 0;
}