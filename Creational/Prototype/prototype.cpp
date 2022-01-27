#include "prototype.h"

int main() {
    PrototypeFactory factory{};
    auto record = factory.create(PrototypeVariant::BUS);
    record->method();

    record = factory.create(PrototypeVariant::CAR);
    record->method();
    
    record = factory.create(PrototypeVariant::BUS);
    record->method();

    record = factory.create(PrototypeVariant::CAR);
    record->method();

}