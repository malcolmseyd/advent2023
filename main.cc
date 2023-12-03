#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <typename T>
T nxt() {
  T x;
  cin >> x;
  return x;
}

#ifndef NDEBUG
#define DEBUG(args...) (cout << format(args))
#else
#define DEBUG(...) 0
#endif

struct Solution {
  auto solve() {
    string line;
    while (getline(cin, line)) {
      lines.push_back(line);
    }
    DEBUG("{} {}\n", 1, 2);
    return "TODO";
  }
  vector<string> lines;
};

int main() { cout << Solution().solve() << endl; }
