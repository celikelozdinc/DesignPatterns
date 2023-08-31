#ifndef CREATIONAL_PROTOTYPE_POLYMORPHIC_H
#define CREATIONAL_PROTOTYPE_POLYMORPHIC_H

#include <iostream>
#include <memory>

class Data {
public:
    Data() {
        c = new char{'d'};
        std::cout << "____Constructed Data at : " << this << '\n';
    }
    ~Data() {
        if(nullptr != c) {
            delete c;
        }
        std::cout << "____Destructed Data from : " << this << '\n';
    }

    Data(const Data&) {
        std::cout << "____Copy constructed Data at : " << this << '\n';
    }

    void p() const {
        std::cout << "____" << *c << ", at : "<< this << '\n';
    }

    char& d() {
        return *c;
    }
private:
    char* c;
};

class CopyablePolymorhic {
public:
    CopyablePolymorhic() : data(std::make_unique<Data>()) {
        std::cout << "__Constructed CopyablePolymorhic at : " << this << '\n';
    }
    virtual ~CopyablePolymorhic() {
        data.reset(nullptr);
        std::cout << "__Destructed CopyablePolymorhic from : " << this << '\n';
    }


    /*
    CopyablePolymorhic(const CopyablePolymorhic& other){
        std::cout << "\tCopy constructed CopyablePolymorhic at : " << this << '\n';
    }
    */


    CopyablePolymorhic(const CopyablePolymorhic& other) : data{std::make_unique<Data>()}{
        data->d() = 'X';
        std::cout << "__Copy constructed CopyablePolymorhic at : " << this << '\n';
    }

    virtual void p() const {
        data->p();
    }

    virtual char id() const {
        return 'B';
    }

private:
    std::unique_ptr<Data> data;
};

struct CopyableDerived : CopyablePolymorhic {
    char id() const override {
        return 'D';
    }
};

class MoveablePolymorphic {
public:
    MoveablePolymorphic() : data{new Data{}} {
        std::cout << "__Constructed MoveablePolymorphic at : " << this << '\n';
    }

    ~MoveablePolymorphic() {
        if (nullptr != data) {
            delete data;
        }
        std::cout << "__Destructed MoveablePolymorphic from : " << this << '\n';
    }

    MoveablePolymorphic(MoveablePolymorphic&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    virtual void p() const {
        data->p();
    }

    virtual char id() const {
        return 'b';
    }
private:
    Data* data;
};

struct MoveableDerived : MoveablePolymorphic {
    char id() const override {
        return 'd';
    }
};

#endif
