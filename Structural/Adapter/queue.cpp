#include "locking_queue.h"

#include <thread>
#include <chrono>

constexpr auto tenMill = 10000000;
constexpr auto twoMill = 2000000;

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
        std::cout << "For pushing, in thread : " << std::this_thread::get_id() << ", duration : " << fp_ms.count() << " ms\n";
    };

    auto remove = [&]() {
        auto begin = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < twoMill ; ++i) {
            queue.pop();
        }
        auto end = std::chrono::high_resolution_clock::now();

        // floating-point duration: no duration_cast needed
        std::chrono::duration<double, std::milli> fp_ms = end - begin;
        std::cout << "For popping, in thread : " << std::this_thread::get_id() << ", duration : " << fp_ms.count() << " ms\n";
    };

    std::thread t1(populate);
    std::thread t2(populate);
    t2.join();
    t1.join();

    std::cout << "Size of the locking_queue : " << queue.get_size() << "\n";
    std::cout << "Count of the locking_queue : " << queue.get_thread_safe_count() << "\n";

    std::thread rm1(remove);
    std::thread rm2(remove);
    std::thread rm3(remove);
    std::thread rm4(remove);
    rm4.join();
    rm3.join();
    rm2.join();
    rm1.join();

    std::cout << "Size of the locking_queue : " << queue.get_size() << "\n";
    std::cout << "Count of the locking_queue : " << queue.get_thread_safe_count() << "\n";

    return EXIT_SUCCESS;
}