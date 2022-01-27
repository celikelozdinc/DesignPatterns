#ifndef CREATIONAL_PROTOTYPE_PROTOTYPE_H
#define CREATIONAL_PROTOTYPE_PROTOTYPE_H

#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

enum class PrototypeVariant : uint8_t {
    CAR = 0,
    BUS = 1,
};


/**
 * @brief Base Prototype
 * 
 */
class Prototype {
public:
    Prototype(const std::string& t_name, float t_field) : m_prototype_name{t_name}, m_prototype_field{t_field} {
        std::cout << "Prototype(const std::string&, float)\n";
    }
    virtual std::unique_ptr<Prototype> clone() = 0;  // raw pointers can be used as well
    virtual void method() = 0;
    virtual ~Prototype() {
        std::cout << "~Prototype()\n";
    }
protected:
    std::string m_prototype_name;
    float m_prototype_field;
};

/**
 * @brief Concrete prototype
 * subclass of Protoype base class
 * 
 */
class CarPrototype : public Prototype {
public:
    CarPrototype(const std::string& t_name, float t_field) : Prototype(t_name, t_field) {
        std::cout << "CarPrototype(const std::string&, float)\n";
    }
    
    std::unique_ptr<Prototype> clone() override {
        return std::make_unique<CarPrototype>(*this);
        // return new CarPrototype(*this);
    }

    void method() override {
        std::cout << "CarPrototype:: name -> " << m_prototype_name << ", field -> " << m_prototype_field << "\n";
    }
    ~CarPrototype() {
        std::cout << "~CarPrototype()\n";
    }
};

/**
 * @brief Concrete prototype
 * subclass of Protoype base class
 */
class BusPrototype : public Prototype {
public:
    BusPrototype() = default;

    BusPrototype(const std::string& t_name, float t_field, uint16_t t_pass) : Prototype(t_name, t_field), m_passengers{t_pass} {
        std::cout << "BusPrototype(const std::string&, float, uint16_t)\n";
    }

    std::unique_ptr<Prototype> clone() override {
        return std::make_unique<BusPrototype>(*this);
        // return new BusPrototype(*this);
    }

    void method() override {
        std::cout << "BusPrototype:: name -> " << m_prototype_name << ", field -> " << m_prototype_field << ", passengers ->"  << m_passengers << "\n";
    }

    ~BusPrototype() {
        std::cout << "~BusPrototype()\n";
    }
private:
    uint16_t m_passengers;
};

class PrototypeFactory {
private:
    std::unordered_map<PrototypeVariant, std::unique_ptr<Prototype>> m_protoypes;
public:
    PrototypeFactory() {
        m_protoypes[PrototypeVariant::CAR] = std::make_unique<CarPrototype>("FIAT", 1.4f);
        m_protoypes[PrototypeVariant::BUS] = std::make_unique<BusPrototype>("ISUZU", 1.8f, 44);
    }

    std::unique_ptr<Prototype> create(PrototypeVariant variant) {
        return m_protoypes[variant]->clone();
    }

    ~PrototypeFactory() {
        std::cout << "~PrototypeFactory()\n";
        m_protoypes[PrototypeVariant::CAR].reset();
        m_protoypes[PrototypeVariant::BUS].reset();
    }
};


#endif