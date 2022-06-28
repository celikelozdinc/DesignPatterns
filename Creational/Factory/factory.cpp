#include "factory.h"

int main() {
    PointFunctionalFactory pff{};
    std::cout << "============================================================================\n";
    auto p2D = pff.create(PointType::Point2D, 2.0);
    std::cout << "============================================================================\n";
    auto p1D = pff.create(PointType::Point1D, 1.0);
    std::cout << "============================================================================\n";
    auto p3D = pff.create(PointType::Point3D, 3.0);
    std::cout << "============================================================================\n";
    return EXIT_SUCCESS;
}