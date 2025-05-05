#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 看解答
 * O(n)
 * State machine
 */
class Solution {
 public:
  bool isNumber(string s) {
    State state = State::INITIAL;

    for (auto &&c : s) {
      CharType charType = getCharType(c);
      state = transfer(charType, state);

      if (state == State::INVALID) {
        return false;
      }
    }

    return state == State::INT || state == State::DECIMAL ||
           state == State::EXPONENT_INT;
  }

 private:
  enum class CharType { INT, SIGN, POINT, EXPONENT, INVALID };

  enum class State {
    INITIAL,
    INT,
    SIGN,
    EXPONENT,
    INVALID,
    DECIMAL,
    EXPONENT_INT,
    EXPONENT_SIGN,
    POINT_WITHOUT_INT,
  };

  State transfer(CharType charType, State previousState) {
    switch (previousState) {
      case State::INITIAL:
        if (charType == CharType::INT) {
          return State::INT;
        } else if (charType == CharType::SIGN) {
          return State::SIGN;
        } else if (charType == CharType::POINT) {
          return State::POINT_WITHOUT_INT;
        }
        break;

      case State::INT:
        if (charType == CharType::INT) {
          return State::INT;
        } else if (charType == CharType::POINT) {
          return State::DECIMAL;
        } else if (charType == CharType::EXPONENT) {
          return State::EXPONENT;
        }
        break;

      case State::SIGN:
        if (charType == CharType::INT) {
          return State::INT;
        } else if (charType == CharType::POINT) {
          return State::POINT_WITHOUT_INT;
        }
        break;

      case State::EXPONENT:
        if (charType == CharType::INT) {
          return State::EXPONENT_INT;
        } else if (charType == CharType::SIGN) {
          return State::EXPONENT_SIGN;
        }
        break;

      case State::DECIMAL:
        if (charType == CharType::INT) {
          return State::DECIMAL;
        } else if (charType == CharType::EXPONENT) {
          return State::EXPONENT;
        }
        break;

      case State::EXPONENT_INT:
      case State::EXPONENT_SIGN:
        if (charType == CharType::INT) {
          return State::EXPONENT_INT;
        }
        break;

      case State::POINT_WITHOUT_INT:
        if (charType == CharType::INT) {
          return State::DECIMAL;
        }
        break;

      default:
        break;
    }

    return State::INVALID;
  }

  CharType getCharType(char c) {
    if (isdigit(c)) {
      return CharType::INT;
    } else if (c == '-' || c == '+') {
      return CharType::SIGN;
    } else if (c == '.') {
      return CharType::POINT;
    } else if (c == 'E' || c == 'e') {
      return CharType::EXPONENT;
    } else {
      return CharType::INVALID;
    }
  }
};
