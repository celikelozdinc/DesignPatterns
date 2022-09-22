#ifndef STRUCTURAL_ADAPTER_LOCKING_QUEUE_H
#define STRUCTURAL_ADAPTER_LOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>

template <typename Q>
class locking_queue {
    //using q = typename std::queue<Q>::
public:
    locking_queue() {
        std::cout << "locking_queue::locking_queue()\n";
    }

    ~locking_queue() {
        std::cout << "locking_queue::~locking_queue()\n";
    }

    void push(const Q& val) {
        //std::cout << "locking_queue::push()::Prepare\n";
        {
            std::lock_guard<std::mutex> lockG(mtx);
            queue.push(val);
        }
        //std::cout << "locking_queue::push()::Clear\n";
    }

    size_t get_size() const {
        return queue.size();
    }

private:
    std::queue<Q> queue;
    std::mutex mtx;
};


#endif