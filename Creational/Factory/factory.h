#ifndef CREATIONAL_FACTORY_FACTORY_H
#define CREATIONAL_FACTORY_FACTORY_H

#include <iostream>
#include <functional>
#include <unordered_map>
#include <memory>

enum class PointType {
    Point1D, Point2D, Point3D
};

struct Point {
    explicit Point(float t_x) : x_coordinate{t_x} {std::cout << "Point::Point(), x coordinate : " << x_coordinate << "\n";}
    float x_coordinate;
};

struct Point1D : Point {
    explicit Point1D(float t_x) : Point(t_x) {std::cout << "Point1D::Point1D(), x coordinate : " << x_coordinate << "\n";}
};

struct Point2D : Point {
    explicit Point2D(float t_x) :  Point(t_x), y_coordinate{8.0} {std::cout << "Point2D::Point2D(), x coordinate : " << x_coordinate << ", y coordinate : " << y_coordinate << "\n";}
    float y_coordinate;
};

struct Point3D : Point2D {
    explicit Point3D(float t_x) : Point2D(t_x), z_coordinate{12.0} {std::cout << "Point3D::Point3D(), x coordinate : " << x_coordinate << ", y coordinate : " << y_coordinate << ", z coordinate : " << z_coordinate << "\n";}
    float z_coordinate;
};

using bucket = std::unordered_map<PointType, std::function<std::unique_ptr<Point>(float)>>;

struct PointFunctionalFactory {
    bucket m_bucket;
    PointFunctionalFactory() {
        m_bucket[PointType::Point1D] = [] (float initial_x){return std::make_unique<Point1D>(initial_x);};
        m_bucket[PointType::Point2D] = [] (float initial_x){return std::make_unique<Point2D>(initial_x);};
        m_bucket[PointType::Point3D] = [] (float initial_x){return std::make_unique<Point3D>(initial_x);};
    }

    std::unique_ptr<Point> create(PointType type, float initial_x_coordinate) {
        return m_bucket[type](initial_x_coordinate);
    }
};

#endif