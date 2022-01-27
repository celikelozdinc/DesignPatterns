#ifndef STRUCTURAL_ADAPTER_INCLUDE_CALLBACK_H
#define STRUCTURAL_ADAPTER_INCLUDE_CALLBACK_H

#include <iostream>
#include <vector>

/**
 * @brief Base class for the callback mechanism
 * 
 */
struct CallbackInterface {
    virtual void on_begin() const = 0;
    virtual void process(int) const = 0;
    virtual void print() const = 0;
    virtual void on_end() const = 0;
};

/**
 * @brief Processor is agnostic with respect to 
 * how process_data() function wants to call it back,
 * all the logic is delegated to HalfAdapter and ThirdAdapter
 * 
 */
struct Processor {
    /**
     * @brief HalfAdapter is agnostic with respect to how processor wants to call it back
     * 
     */
    struct HalfAdapter : CallbackInterface {
        explicit HalfAdapter(Processor* owner) : owner_h{owner} {}
        void on_begin() const override {
            std::cout << "HalfAdapter::on_begin()\n";
        }
        void on_end() const override {
            std::cout << "HalfAdapter::on_end()\n";
        }
        /**
         * @brief Adapting
         * 
         * @param h 
         */
        void process(int h) const override {
            std::cout << "HalfAdapter::process()\n";
            h /= 2;
            owner_h->half.push_back(h);
        }
        void print() const override {
            std::cout << "HalfAdapter::print()\n";
            for (const auto elem : owner_h->half) {
                std::cout << elem << " ";
            }
            std::cout <<"\n";
        }

        Processor* owner_h;
    };

    /**
     * @brief ThirdAdapter is agnostic with respect to how processor wants to call it back
     * 
     */
    struct ThirdAdapter : CallbackInterface {
        explicit ThirdAdapter(Processor* owner) : owner_t{owner} {}
        void on_begin() const override {
            std::cout << "ThirdAdapter::on_begin()\n";
        }
        void on_end() const override {
            std::cout << "ThirdAdapter::on_end()\n";
        }
        /**
         * @brief Adapting
         * 
         * @param h 
         */
        void process(int h) const override {
            std::cout << "ThirdAdapter::process()\n";
            h *= 3;
            owner_t->third.push_back(h);
        }
        void print() const override {
            std::cout << "HalfAdapter::print()\n";
            for (const auto elem : owner_t->third) {
                std::cout << elem << " ";
            }
            std::cout <<"\n";
        }
        Processor* owner_t;
    };

    std::vector<int> half;
    std::vector<int> third;

    Processor() {
        std::cout << "Processor::Processor()\n";
    }
    ~Processor() {
        std::cout << "Processor::~Processor()\n";
    }
};

#endif