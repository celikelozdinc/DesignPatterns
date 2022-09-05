#ifndef CREATIONAL_FACTORY_VIRTUAL_CONSTRUCTOR_H
#define CREATIONAL_FACTORY_VIRTUAL_CONSTRUCTOR_H

#include <iostream>

struct A {
    A() {
        std::cout << "A::A() : " << typeid(*this).name() << " => " << this << "\n";
    }

    virtual void whoami() const {
        std::cout << "A::whoami()\n";
    }

    /*
    void whoami() const {
        std::cout << "A::whoami()\n";
    }
    */

    virtual ~A() {
        std::cout << "A::~A() : " << typeid(*this).name() << " => " << this << "\n";
    }

    /*
    ~A() {
        std::cout << "A::~A() : " << typeid(*this).name() << "\n";
    }
    */
};


struct B : A {
    B() {
        std::cout << "B::B() : " << typeid(*this).name() << " => " << this << "\n";
    }

    void whoami() const override {
        std::cout << "B::whoami()\n";
    }

    ~B() {
        std::cout << "B::~B() : " << typeid(*this).name() << " => " << this << "\n";
    }
};


struct C : B {
    C() {
        std::cout << "C::C() : " << typeid(*this).name() << " => " << this << "\n";
    }

    void whoami() const override {
        std::cout << "C::whoami()\n";
    }

    ~C() {
        std::cout << "C::~C() : " << typeid(*this).name() << " => " << this << "\n";
    }
};

#endif