#include <iostream>

namespace problematic {
    class Rectangle {
    public:
        Rectangle(int w, int h) 
        : area_(width_ * height_), width_(w), height_(h) {}
        
        void print() const {
            std::cout << "Width: " << width_ << ", Height: " << height_ 
                      << ", Area: " << area_ << std::endl;
        }
        
    private:
        int area_;
        int width_;
        int height_;
    };
    
    void example() {
        std::cout << "=== Problematic initialization ===" << std::endl;
        Rectangle rect(5, 10);
        rect.print();
    }
} // problematic

namespace fixed {
    class Rectangle {
    public:
        Rectangle(int w, int h) 
        : width_(w), height_(h), area_(width_ * height_) {}
        
        void print() const {
            std::cout << "Width: " << width_ << ", Height: " << height_
                      << ", Area: " << area_ << std::endl;
        }
        
    private:
        int width_;
        int height_;
        int area_;
    };
    
    void example() {
        std::cout << "\n=== Fixed initialization ===" << std::endl;
        Rectangle rect(5, 10);
        rect.print();  // Area will be correct!
    }
}

int main() {
    problematic::example();
    fixed::example();
}
