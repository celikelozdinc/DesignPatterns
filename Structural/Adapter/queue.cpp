#include "locking_queue.h"

#include <thread>
#include <chrono>

constexpr auto tenMill = 10000000;

int main() {
    locking_queue<uint32_t> queue{};

    auto populate = [&]() {
        auto begin = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < tenMill ; ++i) {
            queue.push(i);
        }
        auto end = std::chrono::high_resolution_clock::now();

        // floating-point duration: no duration_cast needed
        std::chrono::duration<double, std::milli> fp_ms = end - begin;
        std::cout << "In thread : " << std::this_thread::get_id() << ", duration : " << fp_ms.count() << " ms\n";
    };

    std::thread t1(populate);
    std::thread t2(populate);
    t2.join();
    t1.join();

    std::cout << "Size of the locking_queue : " << queue.get_size() << "\n";
    return EXIT_SUCCESS;
}