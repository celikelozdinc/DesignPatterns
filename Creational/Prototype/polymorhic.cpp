#include "polymorhic.h"

/**
 * Please have a look at
 * C.67: A polymorphic class should suppress public copy/move
 *
 */
int main() {
    Derived d{};
    CopyablePolymorhic& base = d;
    std::cout << "Main[0]\n";
    {
        std::cout << "Starting inner scope...\n";
        auto b2 = base;  //polymorphic behavior will be corrupted.
        std::cout << "ID: " << b2.id() << "\n";
        b2.p();
        std::cout << "Ending inner scope...\n";
    }
    std::cout << "Main[1]\n";
    std::cout << "ID: " << base.id() << "\n";
    base.p();
    std::cout << "ID: " << d.id() << "\n";
    d.p();

};