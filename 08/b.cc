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
      string node = match[1];
      graph_[node] = {match[2], match[3]};
      if (node[2] == 'A') {
        state_.push_back(node);
      }
    }
  }
  auto solve_one(string curr) {
    ll ans = 0;
    ll n = instr_.size();
    ll done = 0;
    while (curr[2] != 'Z') {
      if (instr_[ans % n] == 'L') {
        curr = graph_[curr].first;
      } else {
        curr = graph_[curr].second;
      }
      ans += 1;
    }
    DEBUG("ans={} curr={}\n", ans, (curr));
    return ans;
  }
  ll solve() {
    init();
    ll ans = solve_one(state_[0]);
    for (int i = 1; i < state_.size(); i++) {
      ans = lcm(ans, solve_one(state_[i]));
    }
    return ans;
  }
  string instr_;
  vector<string> state_;
  unordered_map<string, pair<string, string>> graph_;
};

int main() { cout << Solution().solve() << endl; }
