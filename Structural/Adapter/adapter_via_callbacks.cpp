#include "callback.h"

#include <memory>

void process_data(const std::vector<int>& data, const CallbackInterface& cb1, const CallbackInterface& cb2) {
    cb1.on_begin();
    cb2.on_begin();

    for (const auto& elem : data) {
        elem % 2 == 0 ? cb1.process(elem) : cb2.process(elem);
    }

    cb1.print();
    cb2.print();

    cb1.on_end();
    cb2.on_end();
}


int main() {
    std::vector<int> test{0, 2, 6, 9, 7, 11, 8, 7};
    std::unique_ptr<Processor> processorInstance = std::make_unique<Processor>();
    process_data(test, Processor::HalfAdapter(processorInstance.get()), Processor::ThirdAdapter(processorInstance.get()));
    return EXIT_SUCCESS;
}