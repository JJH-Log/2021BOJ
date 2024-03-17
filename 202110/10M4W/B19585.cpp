#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

bool v[2000];
int C, N, Q;

struct Node {
    bool fin;
    map<char, Node*> next;
    Node() {
        fin = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    Node* rc = new Node();
    Node* rn = new Node();
    Node* curr;
    cin >> C >> N;
    for (int i = 0; i < C; i++) {
        curr = rc;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (!curr->next.count(s[j] - 'a')) {
                curr->next[s[j] - 'a'] = new Node();
            }
            curr = curr->next[s[j] - 'a'];
            if (j == s.size() - 1) curr->fin = true;
        }
    }
    for (int i = 0; i < N; i++) {
        curr = rn;
        cin >> s;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (!curr->next.count(s[j] - 'a')) {
                curr->next[s[j] - 'a'] = new Node();
            }
            curr = curr->next[s[j] - 'a'];
            if (j == 0) curr->fin = true;
        }
    }
    cin >> Q;
    for (int t = 0; t < Q; t++) {
        bool FLAG = false;
        cin >> s;
        curr = rc;
        for (int j = 0; j < s.size(); j++) {
            if (!curr->next.count(s[j] - 'a')) break;
            curr = curr->next[s[j] - 'a'];
            if (curr->fin) v[j] = true;
        }
        curr = rn;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (!curr->next.count(s[j] - 'a')) break;
            curr = curr->next[s[j] - 'a'];
            if (curr->fin && j && v[j - 1]) FLAG = true;
        }
        if (FLAG) cout << "Yes\n";
        else cout << "No\n";
        memset(v, false, sizeof(v));
    }
    return 0;
}