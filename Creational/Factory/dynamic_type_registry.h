#ifndef CREATIONAL_FACTORY_DYNAMIC_TYPE_REGISTRY_H
#define CREATIONAL_FACTORY_DYNAMIC_TYPE_REGISTRY_H

#include <memory>
#include <functional>
#include <vector>
#include <utility>
#include <iostream>

struct Building;
using BuildingFactory = std::function<std::unique_ptr<Building>(void)>;

struct Building {
    static void Register(BuildingFactory factoryFunc) {
        static uint16_t building_type_count{0};
        std::cout << "Registering at index " << building_type_count << "\n";
        building_registry.emplace_back(std::make_pair(building_type_count, factoryFunc));
        std::cout << "Registered at index " << building_type_count << "\n";
        std::cout << "Size : " << building_registry.size() << "\n";
        building_registry.at(building_type_count).second();
        building_type_count++;
    }

    static std::unique_ptr<Building> Make(int building_type) {
        //std::cout << "Size : " << building_registry.size() << "\n";
        BuildingFactory factoryFunc = building_registry.at(building_type).second;
        factoryFunc();
        std::cerr << "start exec...\n";
        auto f = std::unique_ptr<Building>(factoryFunc());
        std::cerr << "end exec...\n";
        return f;
        //return std::unique_ptr<Building>(std::invoke(factoryFunc));
    }

    virtual void whoami() const = 0;

    Building() {
        std::cout <<"Building::Building()\n";
    }

    virtual ~Building() {
        std::cout << "Building::~Building()\n";
    }
    static std::vector<std::pair<uint16_t, BuildingFactory>> building_registry;
};

struct Farm : Building {
    static void RegisterMe() {
        Register(init_farm);
    }
    Farm() {
        std::cout <<"Farm::Farm()\n";
    }

    ~Farm() {
        std::cout << "Farm::~Farm()\n";
    }

    void whoami() const override {
        std::cout << "whoami? -> " << typeid(*this).name() << "\n";
    }

    
    static std::unique_ptr<Building> farm_init() {
        std::cout << "Farm::init_farm()\n";
        return std::unique_ptr<Farm>();
    }

    static BuildingFactory init_farm;
};

struct Forge : Building {
    static void RegisterMe() {
        Register(init_forge);
    }
    
    Forge() {
        std::cout <<"Forge::Forge()\n";
    }

    ~Forge() {
        std::cout << "Forge::~Forge()\n";
    }

    void whoami() const override {
        std::cout << "whoami? -> " << typeid(*this).name() << "\n";
    }

    static std::unique_ptr<Building> forge_init() {
        std::cout << "Forge::init_forge()\n";
        auto f = std::unique_ptr<Forge>();
        std::cout << "END Forge::init_forge()\n";
        return f;
    }

    static BuildingFactory init_forge;
};



#endif