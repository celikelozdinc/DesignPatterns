#ifndef CREATIONAL_FACTORY_DYNAMIC_TYPE_REGISTRY_H
#define CREATIONAL_FACTORY_DYNAMIC_TYPE_REGISTRY_H

#include <memory>
#include <functional>
#include <vector>
#include <utility>
#include <iostream>

struct Building;
using BuildingFactory = std::function<std::shared_ptr<Building>(void)>;

struct Building {
    static void Register(BuildingFactory factoryFunc) {
        static uint16_t building_type_count{0};
        building_registry.emplace_back(std::make_pair(building_type_count, factoryFunc));
        //building_registry.at(building_type_count).second();
        building_type_count++;
    }

    static std::shared_ptr<Building> Make(int building_type) {
        BuildingFactory factoryFunc = building_registry.at(building_type).second;
        //factoryFunc();
        //return std::shared_ptr<Building>(factoryFunc());
        return factoryFunc();
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
    static std::shared_ptr<Farm> get_instance() {
        if (!instance) {
            //std::cout << "Creating a new Farm\n";
            instance.reset(new Farm());
        }
        //std::cout << "Returning an existing Farm\n";
        return instance;
    }

    static void RegisterMe() {
        Register(init_farm);
    }

    ~Farm() {
        std::cout << "Farm::~Farm()\n";
    }

    void whoami() const override {
        std::cout << "whoami? -> " << typeid(*this).name() << "\n";
    }

    static std::shared_ptr<Building> farm_init() {
        //std::cout << "Farm::init_farm()\n";
        //return std::shared_ptr<Farm>();
        return instance;
    }

    static BuildingFactory init_farm;

private:
    Farm() {
        std::cout <<"Farm::Farm()\n";
    }
    static std::shared_ptr<Farm> instance;
};

struct Forge : Building {
    static std::shared_ptr<Forge> get_instance() {
        if (!instance) {
            //std::cout << "Creating a new Forge\n";
            instance.reset(new Forge());
        }
        //std::cout << "Returning an existing Forge\n";
        return instance;
    }

    static void RegisterMe() {
        Register(init_forge);
    }

    ~Forge() {
        std::cout << "Forge::~Forge()\n";
    }

    void whoami() const override {
        std::cout << "whoami? -> " << typeid(*this).name() << "\n";
    }

    static std::shared_ptr<Building> forge_init() {
        // std::cout << "Forge::init_forge()\n";
        //auto f = std::shared_ptr<Forge>();
        // std::cout << "END Forge::init_forge()\n";
        //return f;
        return instance;
    }

    static BuildingFactory init_forge;

private:
    Forge() {
        std::cout <<"Forge::Forge()\n";
    }
    static std::shared_ptr<Forge> instance;
};



#endif