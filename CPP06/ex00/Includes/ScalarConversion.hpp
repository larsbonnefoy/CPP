#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include<string>

#define UNVALID 0
#define INT 1
#define CHAR 2
#define FLOAT 3
#define DOUBLE 4
#define FLOATLITTERAL 5
#define DOUBLELITTERAL 6

class ScalarConverter {
    private:
        static void _fromChar(std::string str);
        static void _fromInt(std::string str);
        static void _fromFloat(std::string str);
        static void _fromDouble(std::string str);
        static void _fromLitteral(std::string str);
        static void _fromDoubleLitteral(std::string str);

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter &other);

    public:
        static void convert(std::string str);
};

#endif
