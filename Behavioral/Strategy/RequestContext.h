#ifndef BEHAVIORAL_STRATEGY_REQUESTCONTEXT_H
#define BEHAVIORAL_STRATEGY_REQUESTCONTEXT_H

#include "IStrategy.h"

#include <memory>

class RequestContext {
public:
  explicit RequestContext(std::unique_ptr<IStrategy> str) : _strategy(std::move(str)) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  void insert_cell_configuration_request() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    const auto& reqId = _strategy->alloc_request_id();
    std::cout << "Do Some Business Logic with Request Id : "<< reqId << "\n";
    _strategy->start_timer();

  }

  void set_strategy(std::unique_ptr<IStrategy> istr) {
    _strategy = std::move(istr);
  }

private:
  std::unique_ptr<IStrategy> _strategy;
};

#endif
