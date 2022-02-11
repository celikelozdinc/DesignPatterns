#include "visitor.h"

int main() {
    std::unique_ptr<Object> objA = std::make_unique<ObjectA>();
    std::unique_ptr<Object> objB = std::make_unique<ObjectB>();

    std::unique_ptr<Operation> opX = std::make_unique<OperationX>(std::move(objA), std::move(objB));
    opX->visit(1);
    //opX->visit(0);
}