#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

enum class CallStatus { WAITING, IN_PROGRESS, COMPLETED };

class Employee;

class Call {
 public:
  Call() : m_status(CallStatus::WAITING), m_handler(nullptr) {}
  virtual ~Call() = default;

  Call(const Call&) = delete;
  Call& operator=(const Call&) = delete;

  void setHandler(Employee* employee) { m_handler = employee; }
  void setStatus(CallStatus status) { m_status = status; }
  CallStatus getStatus() const { return m_status; }

 private:
  CallStatus m_status;
  Employee* m_handler;
};

class Employee {
 public:
  virtual ~Employee() = default;

  virtual bool handleCall(Call* call) {
    if (!isFree()) return false;

    m_currentCall = call;
    call->setStatus(CallStatus::IN_PROGRESS);
    call->setHandler(this);

    cout << "Handling call by " << typeid(*this).name() << endl;

    return true;
  };

  virtual bool isFree() { return m_currentCall == nullptr; }
  virtual int getRank() const = 0;

 private:
  Call* m_currentCall = nullptr;
};

class Respondent : public Employee {
  int getRank() const override { return 0; }
};

class Manager : public Employee {
  int getRank() const override { return 1; }
};

class Director : public Employee {
  int getRank() const override { return 2; }
};

class CallCenter {
 public:
  bool dispatchCall(Call* call) {
    for (int level = 0; level <= 2; ++level) {
      for (auto&& employee : m_employees[level]) {
        if (employee->isFree()) {
          employee->handleCall(call);
          return true;
        }
      }
    }
    return false;  // All employees busy
  }

  void addEmployee(Employee* e) { m_employees[e->getRank()].push_back(e); }

 private:
  static constexpr int NUM_LEVELS = 3;
  vector<Employee*> m_employees[NUM_LEVELS];
};

int main() {
  CallCenter center;
  Respondent r1, r2;
  Manager m1;
  Director d1;

  center.addEmployee(&r1);
  center.addEmployee(&r2);
  center.addEmployee(&m1);
  center.addEmployee(&d1);

  Call call1, call2, call3, call4;

  center.dispatchCall(&call1);  // Should go to r1
  center.dispatchCall(&call2);  // Should go to r2
  center.dispatchCall(&call3);  // Should go to m1
  center.dispatchCall(&call4);  // Should go to d1
}
