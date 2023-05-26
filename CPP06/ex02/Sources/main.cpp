#include "../Includes/Base.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"

Base *generate(void);
void indentify(Base *p);
void indentify(Base &p);

int main(void){
    Base *testPtr = generate();
    Base &rtestPtr = *testPtr;
    indentify(testPtr);
    indentify(rtestPtr);
    delete testPtr;
    return (0);
}
