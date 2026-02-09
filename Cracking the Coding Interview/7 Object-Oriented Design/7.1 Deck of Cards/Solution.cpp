#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

enum class Suit { Club, Diamond, Heart, Spade };

class Card {
 public:
  Card(int value, Suit suit) : faceValue(value), suit(suit) {}

  virtual ~Card() = default;

  virtual int getValue() const = 0;  // pure virtual

 protected:
  int faceValue;
  Suit suit;
};

class BlackJackCard : public Card {
 public:
  BlackJackCard(int value, Suit suit) : Card(value, suit) {}

  int getValue() const override {
    if (faceValue >= 11 && faceValue <= 13) return 10;
    return faceValue;
  }

  int getMinValue() const { return faceValue == 1 ? 1 : getValue(); }

  int getMaxValue() const { return faceValue == 1 ? 11 : getValue(); }
};

template <typename T>
class Hand {
 public:
  Hand() : cards() {}

  void addCard(const T& card) { cards.push_back(card); }
  const vector<T>& getCards() const { return cards; }

 protected:
  vector<T> cards;
};

class BlackJackHand : public Hand<BlackJackCard> {
 public:
  int getBestScore() const {
    vector<int> scores = {0};

    for (auto&& card : cards) {
      int minValue = card.getMinValue();
      int maxValue = card.getMaxValue();

      if (minValue == maxValue) {
        for (auto&& score : scores) {
          score += minValue;
        }
      } else {
        vector<int> doubled = scores;

        for (auto&& score : scores) {
          score += minValue;
        }
        for (auto&& score : doubled) {
          score += maxValue;
        }

        scores.insert(scores.end(), doubled.begin(), doubled.end());
      }
    }

    int best = -1;
    for (auto&& score : scores) {
      if (score <= 21 && score > best) {
        best = score;
      }
    }

    return best;
  }
};

template <typename T>
class Deck {
 public:
  Deck() : cards_() {}
  void addCard(const T& card) { cards_.push_back(card); }

  void shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards_.begin(), cards_.end(), g);
    currentIndex_ = 0;
  }

  T dealCard() {
    if (currentIndex_ >= cards_.size()) throw out_of_range("No more cards");
    return cards_[currentIndex_++];
  }

 private:
  vector<T> cards_;
  size_t currentIndex_ = 0;
};

static void testHand(const string& name,
                     const vector<pair<int, Suit>>& cardSpecs, int expected) {
  BlackJackHand h;
  for (const auto& p : cardSpecs) {
    h.addCard(BlackJackCard(p.first, p.second));
  }

  int got = h.getBestScore();
  cout << (got == expected ? "[PASS] " : "[FAIL] ") << name
       << " -> got: " << got << ", expected: " << expected << "\n";
}

int main() {
  // ---- Unit-ish tests for scoring ----
  // Values: 1 = Ace, 11/12/13 = J/Q/K (your getValue() makes them 10)
  testHand("A + K should be 21", {{1, Suit::Spade}, {13, Suit::Heart}}, 21);

  testHand("10 + 7 should be 17", {{10, Suit::Club}, {7, Suit::Diamond}}, 17);

  testHand("A + A + 9 should be 21 (11 + 1 + 9)",
           {{1, Suit::Club}, {1, Suit::Diamond}, {9, Suit::Heart}}, 21);

  // For bust behavior: many blackjack implementations return the smallest bust
  // total. If you instead want "best <= 21 else -1", change expected
  // accordingly.
  testHand("10 + 9 + 5 is bust (24)",
           {{10, Suit::Spade}, {9, Suit::Heart}, {5, Suit::Club}}, -1);

  cout << "\n";

  // ---- Smoke test for deck ----
  Deck<BlackJackCard> deck;
  for (int s = 0; s < 4; ++s) {
    for (int v = 1; v <= 13; ++v) {
      deck.addCard(BlackJackCard(v, static_cast<Suit>(s)));
    }
  }

  deck.shuffle();  // Make sure Deck::shuffle uses std::shuffle(...) [web:26]

  BlackJackHand randomHand;
  randomHand.addCard(deck.dealCard());
  randomHand.addCard(deck.dealCard());

  cout << "Random 2-card hand best score: " << randomHand.getBestScore()
       << "\n";

  return 0;
}
