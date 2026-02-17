#include <cstring>
#include <iostream>
#include <string>

namespace motivation {
    class String {
    public:
        String() = default;
        String(const char* cString) {

            if (cString != nullptr) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
                data = new char[lengthWithNullTerminator];
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }
        std::string toStdString() const { return data ? data : ""; }

    private:
        char* data = nullptr;
    };

    void example() {
        String hello("Hello");

        String world("world");
        std::cout << hello.toStdString() << " " << world.toStdString() << std::endl;
    }
} // namespace motivation

namespace first_attempt {
    class String {
    public:
        String() = default;
        String(const char* cString) {

            if (cString) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
                data = new char[lengthWithNullTerminator];
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }

        ~String() {
            delete[] data;
        }

        std::string toStdString() const { return data ? data : ""; }

    private:
        char* data = nullptr;
    };

    void example() {
        String a = "Hello";  // a::data -> 0x123
        String b = a;        // b::data -> 0x123
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;
    }
} // namespace first_attempt

namespace second_attempt {
    class String {
    public:
        String() = default;

        String(const char* cString) { initFrom(cString); }

        ~String() { delete[] data; }

        String(const String& other) { initFrom(other.data); }

        std::string toStdString() const { return data ? data : ""; }
        void initFrom(const char* cString);
        char* data = nullptr;
    };

    void String::initFrom(const char* cString) {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example() {
        String a = "Hello";
        String b = a;
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;

        String world = "world";
        // b = world; // oops
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;
    }
} // namespace second_attempt

namespace solution {
    class String {
    public:
        String() = default;
        String(const char* cString) { initFrom(cString); }
        // destructor
        ~String() { delete[] data; }

        // copy constructor
        String(const String& other) {
            initFrom(other.data); 
        }
        
        // copy assignment operator
        String& operator=(const String& other) {
            if (this == &other) {
                return *this; // Gracefully handle self assignment
            }
            // 1.
            delete[] data;
            // 2. 
            initFrom(other.data);
            return *this;
        }

        std::string toStdString() const { return data ? data : ""; }
        void initFrom(const char* cString);
        char* data = nullptr;
    };

    void String::initFrom(const char* cString) {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example() {
        String a = "Hello";

        String b, c;
        b = c = a;
        std::cout << a.toStdString() << " " << b.toStdString() << std::endl;
    }
} // namespace solution

int main() {
//    motivation::example();
//    first_attempt::example();
      second_attempt::example();
//    solution::example();
}
