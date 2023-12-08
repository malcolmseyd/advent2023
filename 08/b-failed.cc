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

// int encode(string input) {
//   return (int)input[2] | ((int)input[1] << 8) | ((int)input[0] << 16);
// }

struct Solution {
  void next(string& s, ll& i) {
    if (instr_[i] == 'L') {
      s = graph_[s].first;
    } else {
      s = graph_[s].second;
    }
    i++;
    i %= instr_.size();
  }
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
      // graph_[encode(node)] = {encode(match[2]), encode(match[3])};
      if (node[2] == 'A') {
        // state_.push_back(encode(node));
        state_.push_back(node);
        // start_.push_back(node);
        // len_.push_back(0);
      }
    }
  }
  pair<ll, ll> find_cycle(string start) {
    string tortoise = start;
    ll ti = 0;
    next(tortoise, ti);
    string hare = start;
    ll hi = 0;
    next(hare, hi);
    next(hare, hi);
    while (tortoise != hare) {
      next(tortoise, ti);
      next(hare, hi);
      next(hare, hi);
    }

    ll mu = 0;
    tortoise = start;
    ti = 0;
    while (tortoise != hare) {
      next(tortoise, ti);
      next(hare, hi);
      mu++;
    }
    ll lam = 0;
    hare = tortoise;
    hi = ti;
    next(hare, hi);
    while (tortoise != hare) {
      next(hare, hi);
      lam += 1;
    }
    return {mu, lam};
  }
  ll naive_cycle(string start) {
    string curr = graph_[start].first;
    ll i = 1;

    while (curr != start) {
      next(curr, i);
    }
    return i;
  }
  void advance_all(ll& i) {
    for (int j = 0; j < state_.size(); j++) {
    }
    i++;
    i %= instr_.size();
  }
  auto solve() {
    init();
    ll ans = 0;
    for (int i = 0; i < state_.size(); i++) {
      auto [mu, lam] = find_cycle(state_[i]);
      DEBUG("i={} lam={} mu={}\n", i, lam, mu);
    }

    // ll n = instr_.size();
    // ll m = state_.size();
    // m = 2;
    // ll done = 0;
    // while (done != m) {
    //   done = 0;
    //   for (int i = 0; i < m; i++) {
    //     if (instr_[ans % n] == 'L') {
    //       state_[i] = graph_[state_[i]].first;
    //     } else {
    //       state_[i] = graph_[state_[i]].second;
    //     }
    //     // len_[i]++;
    //     // if (state_[i] == start_[i]) {
    //     //   DEBUG("len[{}] = {}\n", i, len_[i]);
    //     // }
    //     // if ((state_[i] & 0xFF) == (int)'Z') {
    //     if (state_[i][2] == 'Z') {
    //       done += 1;
    //     }
    //     // DEBUG("{} ", state_[i]);
    //   }
    //   // DEBUG("\n");
    //   ans += 1;
    // }
    return ans;
  }
  string instr_;
  vector<string> state_;
  // vector<ll> cur;
  unordered_map<string, pair<string, string>> graph_;
};

int main() { cout << Solution().solve() << endl; }
