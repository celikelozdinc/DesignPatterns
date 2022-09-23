#ifndef STRUCTURAL_ADAPTER_LOCKING_QUEUE_H
#define STRUCTURAL_ADAPTER_LOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include <atomic>
#include <utility>

/**
 * @brief Decorator for the std::queue
 * Contains queue and the lock
 * 
 * @tparam Q 
 */
template <typename Q>
class locking_queue {
    // using q = typename std::queue<Q>::
public:
    locking_queue() : thread_safe_count{0} {
        std::cout << "locking_queue::locking_queue()\n";
    }

    ~locking_queue() {
        std::cout << "locking_queue::~locking_queue()\n";
    }

    /**
     * @brief Copies the Q object, does not move
     * 
     * @param val 
     */
    void push(const Q& val) {
        // std::cout << "locking_queue::push()::Prepare\n";
        {
            std::lock_guard<std::mutex> lockG(mtx);
            queue.push(val);
        }
        thread_safe_count++;
        // std::cout << "locking_queue::push()::Clear\n";
    }

    bool pop() {
    // std::cout << "locking_queue::pop()::Prepare\n";
        {
            std::lock_guard<std::mutex> lockG(mtx);
            if (queue.empty()) {
                return false;
            }
            auto val = std::move(queue.front());
            // std::cout << val << "\n";
            queue.pop();
            thread_safe_count--;
            return true;
        }
    // std::cout << "locking_queue::pop()::Clear\n";
    }

    size_t get_size() const {
        return queue.size();
    }

    int get_thread_safe_count() const {
        return thread_safe_count;
    }

private:
    std::queue<Q> queue;
    std::mutex mtx;
    std::atomic<uint32_t> thread_safe_count;
};


#endif