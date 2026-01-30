#include <iostream>
#include <string>
#include <cctype>

class Password {
private:
    std::string value;
    bool view;

    static bool isLetterOrDigitString(const std::string &s) {
        for (char c : s) {
            if (!std::isalnum(static_cast<unsigned char>(c))) return false;
        }
        return true;
    }

    static bool hasUpper(const std::string &s) {
        for (char c : s) if (std::isupper(static_cast<unsigned char>(c))) return true;
        return false;
    }
    static bool hasLower(const std::string &s) {
        for (char c : s) if (std::islower(static_cast<unsigned char>(c))) return true;
        return false;
    }
    static bool hasDigit(const std::string &s) {
        for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) return true;
        return false;
    }

public:
    Password() : value("12345678"), view(false) {}
    Password(const Password &other) : value(other.value), view(other.view) {}
    Password &operator=(const Password &other) {
        if (this != &other) {
            value = other.value;
            view = other.view;
        }
        return *this;
    }
    ~Password() {
        std::cout << value << std::endl;
    }

    void set(const std::string &s) {
        if (s.size() >= 8 && isLetterOrDigitString(s) && hasUpper(s) && hasLower(s) && hasDigit(s)) {
            value = s;
        }
    }

    void show(bool v) { view = v; }

    bool valid(const std::string &s) const { return s == value; }

    std::string toString() const {
        if (view) return value;
        return std::string(value.size(), '*');
    }

    friend std::ostream &operator<<(std::ostream &os, const Password &p) {
        os << p.toString();
        return os;
    }
};

int main() {
    Password pwd;

    std::cout << "Enter password: ";
    std::string input;
    if (std::getline(std::cin, input)) {
        pwd.set(input);
    }

    std::string guess;
    do {
        std::cout << "Guess the password: ";
        if (!std::getline(std::cin, guess)) break;
    } while (!pwd.valid(guess));

    pwd.show(true);
    std::cout << pwd << std::endl;
    pwd.show(false);
    std::cout << pwd << std::endl;

    return 0;
}
