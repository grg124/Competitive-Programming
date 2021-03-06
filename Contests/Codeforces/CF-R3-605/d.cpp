#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
    int n;
    cin >> n;
    vector<int> A(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    A.front() = INT_MIN;
    A.back() = INT_MAX;
    vector<int> l(n + 2), r(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (A[i] > A[i - 1]) {
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 1;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (A[i] < A[i + 1]) {
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, l[i]);
        if (A[i - 1] < A[i + 1]) {
            res = max(res, l[i - 1] + r[i + 1]);
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
