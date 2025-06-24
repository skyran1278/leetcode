#include <climits>
#include <list>
#include <queue>
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
  void addCard(const T &card) { cards.push_back(card); }
  const vector<T> &getCards() const { return cards; }

 protected:
  vector<T> cards;
};

class BlackJackHand : public Hand<BlackJackCard> {
 public:
  int getBestScore() const {
    vector<int> scores = {0};

    for (auto &&card : cards) {
      int minValue = card.getMinValue();
      int maxValue = card.getMaxValue();

      if (minValue != maxValue) {
        for (auto &&score : scores) {
          score += minValue;
        }
      } else {
        vector<int> doubled = scores;

        for (auto &&score : scores) {
          score += minValue;
        }
        for (auto &&score : doubled) {
          score += maxValue;
        }

        scores.insert(scores.end(), doubled.begin(), doubled.end());
      }
    }

    int best = INT_MIN;
    for (auto &&score : scores) {
      if (score < 21 && score > best) {
        best = score;
      }
    }

    return best;
  }
};

template <typename T>
class Deck {
 public:
  void addCard(const T &card) { cards_.push_back(card); }

  void shuffle() {
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
    currentIndex = 0;
  }

  T dealCard() { return cards[currentIndex_++]; }

 private:
  vector<T> cards_;
  size_t currentIndex_ = 0;
};
