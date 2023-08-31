#include "polymorhic.h"

/**
 * Please have a look at these below:
 * C.67: A polymorphic class should suppress public copy/move
 *
 */
int main() {
    std::cout << "********************1********************\n";
    {
        CopyableDerived d{};
        CopyablePolymorhic &base = d;
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
    }
    std::cout << "********************1********************\n";
    std::cout << "********************2********************\n";
    {
        MoveableDerived md{};
        MoveablePolymorphic& base = md;
        std::cout << "Main[2]\n";
        {
            std::cout << "Starting inner scope...\n";
            //auto b2 = base; //=> copy constructor is implicitly deleted
            std::cout << "Ending inner scope...\n";
        }
        std::cout << "Main[3]\n";
        std::cout << "ID: " << base.id() << "\n";
        base.p();
        std::cout << "ID: " << md.id() << "\n";
        md.p();
    }
    std::cout << "********************2********************\n";

}