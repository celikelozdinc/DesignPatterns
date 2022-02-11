#ifndef BEHAVIORAL_VISITOR_VISITOR_H
#define BEHAVIORAL_VISITOR_VISITOR_H

#include <iostream>
#include <utility>
#include <memory>

struct Object;

/**
 * @brief VISITOR class
 * 
 */
struct Operation {
    virtual void visit(int mode) = 0;
    virtual void doA(const Object& obj) const = 0;
    virtual void doB(const Object& obj) const = 0;
    Operation() {
        std::cout << "Operation::Operation()\n";
    }
    ~Operation() {
        std::cout << "Operation::~Operation()\n";
    }
};

struct Object {
    virtual void accept(const Operation& operation) = 0;
    Object() {
        std::cout << "Object::Object()\n";
    }
    ~Object() {
        std::cout << "Object::~Object()\n";
    }
};


struct OperationX : Operation {
    OperationX(std::unique_ptr<Object> t_a, std::unique_ptr<Object> t_b) : objectA{std::move(t_a)}, objectB{std::move(t_b)} {
        std::cout << "OperationX::OperationX(std::unique_ptr<Operation> t_a, std::unique_ptr<Operation> t_b)\n";
    }

    /**
     * @brief PING
     * 
     * @param mode 
     */
    void visit(int mode) override {
        std::cout << "OperationX::visit()\n";
        if (0 == mode) {
            objectA->accept(*this);
            objectB->accept(*this);
        } else if (1 == mode) {
            objectB->accept(*this);
        } else {
            std::cout << "Invalid mode for OperationX::visit()\n";
        }
    }

    void doA(const Object& obj) const override {
        std::cout << "OperationX::doA()\n";
    }

    void doB(const Object& obj) const override {
        std::cout << "OperationX::doB()\n";
    }

    ~OperationX() {
        std::cout << "OperationX::~OperationX()\n";
        objectA.release();
        objectB.release();
    }


    std::unique_ptr<Object> objectA;
    std::unique_ptr<Object> objectB;
};




struct ObjectA : Object {
    /**
     * @brief PONG
     * 
     * @param operation 
     */
    void accept(const Operation& operation) override {
        std::cout << "ObjectA::accept(const Operation& operation)\n";
        operation.doA(*this);
    }

    ObjectA() {
        std::cout << "ObjectA::ObjectA()\n";
    }
    ~ObjectA() {
        std::cout << "ObjectA::~ObjectA()\n";
    }
};


struct ObjectB : Object {
    /**
     * @brief PONG
     * 
     * @param operation 
     */
    void accept(const Operation& operation) override {
        std::cout << "ObjectB::accept(const Operation& operation)\n";
        operation.doB(*this);
    }

    ObjectB() {
        std::cout << "ObjectB::ObjectB()\n";
    }
    ~ObjectB() {
        std::cout << "ObjectA::~ObjectB()\n";
    }
};


#endif