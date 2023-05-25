#include "../Includes/Base.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <execution>

Base *generate(void) {

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int res = std::rand() % 3;

    switch (res) {
        case 0:
            std::cout << "A created" << std::endl;
            return (new A());
        case 1:
            std::cout << "B created" << std::endl;
            return (new B());
        case 2:
            std::cout << "C created" << std::endl;
            return (new C());
    }
    return (nullptr);
}

void indentify(Base *p) {
    A *caseA = dynamic_cast<A *>(p);
    B *caseB = dynamic_cast<B *>(p);
    C *caseC = dynamic_cast<C *>(p);

    if (caseA != nullptr)
        std::cout << "Type of base = A" << std::endl;
    if (caseB != nullptr)
        std::cout << "Type of base = B" << std::endl;
    if (caseC != nullptr)
        std::cout << "Type of base = C" << std::endl;
}

void indentify(Base &p) {
    try {
        A &CaseA = dynamic_cast<A &>(p);
        (void) CaseA;
        std::cout << "Type of base = A" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        B &CaseB = dynamic_cast<B &>(p);
        (void) CaseB;
        std::cout << "Type of base = B" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        C &CaseC = dynamic_cast<C &>(p);
        (void) CaseC;
        std::cout << "Type of base = C" << std::endl;
    }
    catch (std::exception &e) {
    }
}
