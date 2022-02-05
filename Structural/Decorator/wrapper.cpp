#include "shapes.h"
#include "decorator.h"

void bar(foo& t_foo) {
    t_foo.do_work();
}

int main() {
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(3.9f);
    std::unique_ptr<Shape> square = std::make_unique<Square>(2.6f);

    std::unique_ptr<ColoredShape> cs1 = std::make_unique<ColoredShape>(std::move(circle), "green");
    std::cout << cs1->operator std::string() << "\n";

    std::unique_ptr<ColoredShape> cs2 = std::make_unique<ColoredShape>(std::move(square), "blue");
    std::cout << cs2->operator std::string() << "\n";

    foo_concrete f_concr{};
    foo_decorator wrapper{f_concr};
    bar(wrapper);
}