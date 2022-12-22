#include "RequestContext.h"

#include "F1APStrategy.h"
#include "E1APStrategy.h"

int main() {
  RequestContext requestContext{std::make_unique<E1APStrategy>()};
  requestContext.insert_cell_configuration_request();
  requestContext.set_strategy(std::make_unique<F1APStrategy>());
  requestContext.insert_cell_configuration_request();
}