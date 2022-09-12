#include "dynamic_type_registry.h"


/*
std::unique_ptr<Building> farm_init() {
    std::cout << "Farm::init_farm()\n";
    return std::unique_ptr<Farm>();
}

std::unique_ptr<Building> forge_init() {
    std::cout << "Forge::init_forge()\n";
    return std::unique_ptr<Forge>();
}
*/


BuildingFactory Farm::init_farm = [] () {
    std::cout << "Farm::init_farm()\n";
    return Farm::farm_init();
    //return std::unique_ptr<Farm>();
};

BuildingFactory Forge::init_forge = [] () {
    std::cout << "Forge::init_forge()\n";
    return Forge::forge_init();
    //return std::unique_ptr<Forge>();
};


std::vector<std::pair<uint16_t, BuildingFactory>> Building::building_registry{};


int main() {
    //Farm::init_farm = std::bind(&Farm::farm_init);
    //Forge::init_forge = std::bind(Forge::forge_init);
    Farm::RegisterMe();
    Forge::RegisterMe();
    std::unique_ptr<Building> b0 = Building::Make(0);
    std::unique_ptr<Building> b1 = Building::Make(1);
    //b0->whoami();
    //b1->whoami();
    return EXIT_SUCCESS;
}