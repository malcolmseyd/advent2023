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

enum Type { kHiCard, k1Pair, k2Pair, k3Kind, kFullHouse, k4Kind, k5Kind };

char card_score(char card) {
  switch (card) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return card - '0';
    case 'T':
      return 10;
    case 'J':
      return 11;
    case 'Q':
      return 12;
    case 'K':
      return 13;
    case 'A':
      return 14;
    default:
      assert(false);
  }
}

Type hand_type(string& hand) {
  array<char, 128> count;
  fill(all(count), 0);
  ll fives = 0;
  ll fours = 0;
  ll threes = 0;
  ll twos = 0;
  for (int i = 0; i < 5; i++) {
    char c = hand[i];
    char& curr = count[c];
    curr += 1;
    if (curr == 2) {
      twos++;
    } else if (curr == 3) {
      twos--;
      threes++;
    } else if (curr == 4) {
      threes--;
      fours++;
    } else if (curr == 5) {
      fours--;
      fives++;
    }
  }
  // DEBUG("rating hand={} 5={} 4={} 3={} 2={}\n", hand, fives, fours, threes,
  //       twos);
  if (fives) return k5Kind;
  if (fours) return k4Kind;
  if (threes && twos) return kFullHouse;
  if (threes) return k3Kind;
  if (twos >= 2) return k2Pair;
  if (twos) return k1Pair;
  return kHiCard;
}

struct Hand {
  Type type;
  string cards;
};

struct Solution {
  void read() {
    string line;
    while (getline(cin, line)) {
      string handStr = line.substr(0, 5);
      ll bid = stoll(line.substr(6));
      bids_[handStr] = bid;
      Hand hand;
      hand.cards = handStr;
      hand.type = hand_type(handStr);
      hands_.push_back(hand);
      // DEBUG("{}={}\n", handStr, bid);
    }
  }
  auto solve() {
    read();
    sort(all(hands_), [](Hand& a, Hand& b) {
      if (a.type < b.type) return true;
      if (a.type > b.type) return false;
      for (int i = 0; i < 5; i++) {
        char sa = card_score(a.cards[i]);
        char sb = card_score(b.cards[i]);
        if (sa < sb) return true;
        if (sa > sb) return false;
      };
      // equal
      return false;
    });
    ll ans = 0;
    for (int i = 0; i < hands_.size(); i++) {
      Hand& hand = hands_[i];
      ll bid = bids_[hand.cards];
      ans += bid * (i + 1);
      // DEBUG("hand={} type={} rank={}\n", hand.cards, (ll)hand.type, i + 1);
    }
    return ans;
  }
  vector<Hand> hands_;
  map<string, ll> bids_;
};

int main() { cout << Solution().solve() << endl; }
