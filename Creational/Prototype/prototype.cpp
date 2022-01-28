#include "prototype.h"

int main() {
    PrototypeFactory factory{};
    std::cout << "*******************************************\n";
    auto record = factory.clone(PrototypeVariant::BUS);
    record->method();
    // record->increase_passenger_count();  => ‘class Prototype’ has no member named ‘increase_passenger_count’
    std::cout << "*******************************************\n";

    std::cout << "*******************************************\n";
    record = factory.clone(PrototypeVariant::CAR);
    record->get_state();
    record->method();
    record->get_state();
    std::cout << "*******************************************\n";

    std::cout << "*******************************************\n";
    record = factory.clone(PrototypeVariant::BUS);
    auto copy = record->clone();
    record->get_state();
    record->method();
    record->get_state();
    copy->get_state();
    copy->method();
    copy->get_state();
    std::cout << "*******************************************\n";

    std::cout << "*******************************************\n";
    record = factory.clone(PrototypeVariant::CAR);
    record->method();
    std::cout << "*******************************************\n";

}