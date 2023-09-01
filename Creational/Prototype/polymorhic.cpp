#include "polymorhic.h"

/**
 * Please have a look at these below:
 * C.67: A polymorphic class should suppress public copy/move
 * C.130: For making deep copies of polymorphic classes prefer a virtual clone function instead of public copy construction/assignment
 * https://www.modernescpp.com/index.php/covariant-return-type/
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
    std::cout << "********************3********************\n";
    std::unique_ptr<Container> c = std::make_unique<Container>();
    std::unique_ptr<Container> l = std::make_unique<List>();
    std::cout << "Main[4]\n";
    {
        std::cout << "Starting inner scope...\n";
        auto cc = c->clone();
        std::cout << "ID: " << cc->id() << "\n";
        auto ll = l->clone();
        std::cout << "ID: " << ll->id() << "\n";
        std::cout << "Ending inner scope...\n";
    }
    std::cout << "Main[5]\n";
    std::cout << "ID: " << c->id() << "\n";
    std::cout << "ID: " << l->id() << "\n";
    std::cout << "********************3********************\n";

}