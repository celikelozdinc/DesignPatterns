#ifndef BEHAVIORAL_STRATEGY_F1APSTRATEGY_H
#define BEHAVIORAL_STRATEGY_F1APSTRATEGY_H

#include "IStrategy.h"

class F1APStrategy : public IStrategy {
public:
  F1APStrategy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  ~F1APStrategy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  uint64_t alloc_request_id() override {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return 17;
  }

  void start_timer() override {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

};


#endif
