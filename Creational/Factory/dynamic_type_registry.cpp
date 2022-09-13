#include "dynamic_type_registry.h"


BuildingFactory Farm::init_farm = [] () {
    //std::cout << "Farm::init_farm()\n";
    return Farm::farm_init();
};

BuildingFactory Forge::init_forge = [] () {
    //std::cout << "Forge::init_forge()\n";
    return Forge::forge_init();
};


std::vector<std::pair<uint16_t, BuildingFactory>> Building::building_registry{};
std::shared_ptr<Farm> Farm::instance;
std::shared_ptr<Forge> Forge::instance;

int main() {
    Farm::get_instance()->whoami();
    Forge::get_instance()->whoami();
    std::cout << "Current use count of Farm singleton : " << Farm::get_instance().use_count() << "\n";
    std::cout << "Current use count of Forge singleton : " << Forge::get_instance().use_count() << "\n";
    Farm::get_instance()->whoami();
    Forge::get_instance()->whoami();
    Forge::get_instance()->RegisterMe();
    Farm::get_instance()->RegisterMe();
    std::shared_ptr<Building> b0 = Building::Make(0);
    std::shared_ptr<Building> b1 = Building::Make(1);
    std::shared_ptr<Building> b2 = Building::Make(2);
    b0->whoami();
    b1->whoami();
    std::cout << "Current use count of Farm singleton : " << Farm::get_instance().use_count() << "\n";
    std::cout << "Current use count of Forge singleton : " << Forge::get_instance().use_count() << "\n";
    return EXIT_SUCCESS;
}