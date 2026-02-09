#include <iostream>
#include <string>
#include <stdexcept>
#include "Array.h"

template <typename T>
T Minimum(const dsn::Array<T>& a) {
    if (a.size() == 0) throw std::logic_error("empty array");
    T m = a[0];
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] < m) m = a[i];
    }
    return m;
}

int main() {
    dsn::Array<int> ai(5);
    for (size_t i = 0; i < ai.size(); ++i) ai[i] = static_cast<int>(5 - i);
    std::cout << "ai: " << ai << "\nMinimum(ai) = " << Minimum(ai) << '\n';

    dsn::Array<std::string> as(4);
    as[0] = "pear";
    as[1] = "apple";
    as[2] = "banana";
    as[3] = "kiwi";
    std::cout << "as: " << as << "\nMinimum(as) = " << Minimum(as) << '\n';

    return 0;
}