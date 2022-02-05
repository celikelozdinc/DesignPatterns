#ifndef STRUCTURAL_DECORATOR_SHAPES_H
#define STRUCTURAL_DECORATOR_SHAPES_H

#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <utility>

struct Shape {
    virtual operator std::string() = 0;
};

struct Circle final : Shape{
    float m_radius;
    Circle(const float r) : m_radius{r} {
        std::cout << "Circle::Circle(const float r)\n";
    }
    operator std::string() override {
        std::ostringstream oss;
        oss << "Circle::string() <- having radius " << m_radius << "\n";
        return oss.str();
    }

    uint8_t do_decrease() {
        return static_cast<uint8_t>(m_radius - 1);
    }

    uint8_t do_increase() {
        return static_cast<uint8_t>(m_radius + 1);
    }
};

struct Square final : Shape {
    float m_side;
    Square(const float s) : m_side{s} {
        std::cout << "Square::Square(const float s)\n";
    }
    operator std::string() override {
        std::ostringstream oss;
        oss << "Square::string() <- having side " << m_side << "\n";
        return oss.str();
    }

    uint8_t do_decrease() {
        return static_cast<uint8_t>(m_side - 1);
    }

    uint8_t do_increase() {
        return static_cast<uint8_t>(m_side + 1);
    }
};

struct ColoredShape : Shape {
    std::unique_ptr<Shape> m_shape;
    std::string m_color;

    ColoredShape(std::unique_ptr<Shape> t_shape, const std::string& t_color) : m_shape{std::move(t_shape)}, m_color{t_color} {
        std::cout << "ColoredShape::ColoredShape(std::unique_ptr<Shape> t_shape, const std::string& t_color)\n";
    }

    operator std::string() override {
        return m_shape->operator std::string();
    }

};



#endif