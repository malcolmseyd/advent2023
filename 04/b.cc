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

regex card_pattern("((?:\\d+\\s+)+)\\s*\\|\\s+((?:\\d+\\s+)+\\d+)");

struct Solution {
  auto solve() {
    string line;
    ll sum = 0;
    ll card = 0;
    map<ll, ll> card_count;
    while (getline(cin, line)) {
      card += 1;

      int curr_count = 1;
      if (card_count.count(card)) {
        curr_count += card_count[card];
      }

      // lines.push_back(line);
      smatch match;
      regex_search(line, match, card_pattern);
      // DEBUG("{} | {}\n", match[1].str(), match[2].str());
      stringstream winning_nums(match[1]);
      stringstream game_nums(match[2]);
      ll num;

      set<ll> winning;
      while (winning_nums >> num) {
        winning.insert(num);
      }
      ll score = 0;
      while (game_nums >> num) {
        if (winning.contains(num)) {
          score += 1;
          card_count[card + score] += curr_count;
        }
      }
      sum += curr_count;

      DEBUG("curr_count={} card={} sum={}\n\n", curr_count, card, sum);
    }

    return sum;
  }
  // vector<string> lines;
};

int main() { cout << Solution().solve() << endl; }
