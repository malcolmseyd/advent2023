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
  void init() {
    regex line_pattern("(...) = \\((...), (...)\\)");
    string line;
    getline(cin, line);
    instr_ = line;
    getline(cin, line);  // blank
    smatch match;
    while (getline(cin, line)) {
      regex_match(line, match, line_pattern);
      graph_[match[1]] = {match[2], match[3]};
    }
  }
  auto solve() {
    init();
    ll ans = 0;
    ll n = instr_.size();
    string curr = "AAA";
    while (curr != "ZZZ") {
      if (instr_[ans % n] == 'L') {
        curr = graph_[curr].first;
      } else {
        curr = graph_[curr].second;
      }
      ans += 1;
    }
    return ans;
  }
  string instr_;
  map<string, pair<string, string>> graph_;
};

int main() { cout << Solution().solve() << endl; }
