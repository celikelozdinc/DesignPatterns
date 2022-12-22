#ifndef BEHAVIORAL_STRATEGY_E1APSTRATEGY_H
#define BEHAVIORAL_STRATEGY_E1APSTRATEGY_H

#include "IStrategy.h"

class E1APStrategy : public IStrategy {
public:
  E1APStrategy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  ~E1APStrategy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  uint64_t alloc_request_id() override {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return 34;
  }

  void start_timer() override {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

};


#endif
