#ifndef STRUCTURAL_DECORATOR_DECORATOR_H
#define STRUCTURAL_DECORATOR_DECORATOR_H

#include <iostream>

struct foo {
    virtual void do_work() = 0;
};

struct foo_concrete final : foo {
    void do_work() override {
        std::cout << "foo_concrete::do_work()\n";
    }
};

struct foo_decorator final : foo {
    foo_decorator(foo& t_foo) : f{t_foo} {}
    void do_work() override {
        std::cout << "foo_decorator::do_work()\n";
        f.do_work();
    }
    foo& f;
};


#endif