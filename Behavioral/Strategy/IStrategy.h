#ifndef BEHAVIORAL_STRATEGY_ISTRATEGY_H
#define BEHAVIORAL_STRATEGY_ISTRATEGY_H

#include <iostream>

class IStrategy {
public:
  virtual ~IStrategy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }
  virtual uint64_t alloc_request_id() = 0;
  virtual void start_timer() = 0;
};

#endif
