#include <iostream>
#include <string>

namespace two_args_constructor {
class Point {
public:
    int x_{0};
    int y_{0};

    Point() = default;

    Point(int x, int y) {
        x_ = x;
        y_ = y;
    }

    std::string toString() const { return "{" + std::to_string(x_) + ", " + std::to_string(y_) + "}"; }
};

    void example() {
        Point point(3, 3);
        std::cout << point.toString() << std::endl;

        Point p; // what?
    }
} // namespace two_args_constructor

namespace default_constructor {
    class Point {
    public:
        int x_;
        int y_;

        Point() = default;
        Point(int x, int y)
        : x_(x), y_()
        {
            std::cout << "Ctor\n";
        }

        std::string toString() const { return "{" + std::to_string(x_) + ", " + std::to_string(y_) + "}"; }
    };

    void example() {
        Point p;
        std::cout << p.toString() << "\t" << Point(3, 5).toString() << std::endl;
    }
} // namespace default_constructor

int main() {
    two_args_constructor::example();
    default_constructor::example();
}