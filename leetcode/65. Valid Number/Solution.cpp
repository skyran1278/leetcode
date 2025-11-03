#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 42 m 19 s
 * O(n)
 * O(1)
 */
class Solution {
 public:
  enum class CharType { Dot, Sign, Number, E, Invalid };
  enum class State {
    Invalid,
    Init,
    Number,
    NumberDot,
    Dot,
    DotNumber,
    Sign,
    E,
    ENumber,
    ESign,
  };

  bool isNumber(string s) {
    unordered_map<State, unordered_map<CharType, State>> map = {
        {State::Init,
         {{CharType::Number, State::Number},
          {CharType::Dot, State::Dot},
          {CharType::Sign, State::Sign}}},
        {
            State::Number,
            {
                {CharType::Number, State::Number},
                {CharType::Dot, State::NumberDot},
                {CharType::E, State::E},
            },
        },
        {
            State::NumberDot,
            {
                {CharType::Number, State::DotNumber},
                {CharType::E, State::E},
            },
        },
        {
            State::Dot,
            {{CharType::Number, State::DotNumber}},
        },
        {State::DotNumber,
         {
             {CharType::Number, State::DotNumber},
             {CharType::E, State::E},
         }},
        {State::Sign,
         {
             {CharType::Number, State::Number},
             {CharType::Dot, State::Dot},
         }},
        {State::E,
         {
             {CharType::Number, State::ENumber},
             {CharType::Sign, State::ESign},
         }},
        {State::ENumber,
         {
             {CharType::Number, State::ENumber},
         }},
        {State::ESign,
         {
             {CharType::Number, State::ENumber},
         }}};

    State state = State::Init;
    for (auto&& c : s) {
      CharType charType = getCharType(c);
      state = map[state][charType];
    }

    return state == State::Number || state == State::DotNumber ||
           state == State::NumberDot || state == State::ENumber;
  }

  CharType getCharType(char c) {
    if (c == '.') {
      return CharType::Dot;
    }

    if (c == '-' || c == '+') {
      return CharType::Sign;
    }

    if (isdigit(c)) {
      return CharType::Number;
    }

    if (c == 'e' || c == 'E') {
      return CharType::E;
    }

    return CharType::Invalid;
  }
};

int main() {
  Solution s;
  s.isNumber("e9");
}
