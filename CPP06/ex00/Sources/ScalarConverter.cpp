#include "../Includes/ScalarConversion.hpp"

#include<iostream>
#include<sstream>

int getScalarType(std::string input) {

    if (input == "-inff" || input == "+inff" || input == "nanf")
        return (FLOATLITTERAL);
    if (input == "-inf" || input == "+inf" || input == "nan")
        return (DOUBLELITTERAL);

    int inputLen = input.length();
    if (inputLen == 1) {
        if (isdigit(input[0]) == 1) {
            return (INT);
        }
        return (CHAR);
    }

    if (input[0] != '+' && input[0] != '.' && input[0] != '-' && isdigit(input[0]) == false) 
        return (UNVALID);

    int hasPoint = 0; 
    int hasF = 0;
    if (input[0] == '.')
        hasPoint = 1;
    for (int i = 1; i < inputLen; i++){
        if (input[i] == '.') {
                if (++hasPoint > 1 || input[i + 1] == 'f' || input[i + 1] == '\0')
                    return (UNVALID);
        }
        else if (input[i] == 'f' && i == inputLen - 1 && hasPoint == 1)
            hasF = 1;
        else if (isdigit(input[i]))
            ;
        else
            return(UNVALID);
    }
    if (hasF == 1)
        return (FLOAT);
    else if (hasPoint)
        return (DOUBLE);
    else
        return (INT);
}

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void) other;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}

void ScalarConverter::convert(std::string str) {
    int baseCase =  getScalarType(str);
    
    switch (baseCase) {
        case 1:
            _fromInt(str);
            break;
        case 2:
            _fromChar(str);
            break;
        case 3:
            _fromFloat(str);
            break;
        case 4:
            _fromDouble(str);
            break;
        case 5:
            _fromLitteral(str);
            break;
        case 6:
             _fromDoubleLitteral(str);
            break;
        default:
            std::cout << "Impossible convertion\nSupported types are <char>, <int>, "
		    << "<float> and <double>\n";
            break;
    }
}

void ScalarConverter::_fromInt(std::string str) {
    std::stringstream intStream(str);
    int val;

    intStream >> val;

    if (intStream.fail()) {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
    }
    if (!isprint(val)) {
        std::cout << "char: " << "Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    }
    std::cout << "int: " << val << std::endl;
    std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void ScalarConverter::_fromChar(std::string str) {
    char c = str[0];

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::_fromFloat(std::string str) {
    std::stringstream floatStream(str.substr(0, str.length() - 1));
    int     intVal;
    float   floatVal;
    float   doubleVal;

    floatStream >> floatVal;

    if (floatStream.fail()) {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
    }
    if (!isprint(floatVal)) {
        std::cout << "char: " << "Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(floatVal) << std::endl;
    }
    intVal = static_cast<int>(floatVal);
    doubleVal = static_cast<double>(floatVal);
    if (doubleVal > static_cast<double>(INT_MAX) || doubleVal < static_cast<double>(INT_MIN))
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << intVal << std::endl;
    std::cout << "float: " << floatVal;
    if (intVal == floatVal)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << doubleVal;
    if (intVal == doubleVal)
        std::cout << ".0";
    std::cout << std::endl;  
}

void ScalarConverter::_fromDouble(std::string str) {
    std::stringstream doubleStream(str.substr(0, str.length() - 1));
    int     intVal;
    float   floatVal;
    double  doubleVal;

    doubleStream >> doubleVal;

    if (doubleStream.fail()) {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
    }
    if (!isprint(doubleVal)) {
        std::cout << "char: " << "Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(doubleVal) << std::endl;
    }
    intVal = static_cast<int>(doubleVal);
    floatVal = static_cast<double>(doubleVal);
    if (doubleVal > static_cast<double>(INT_MAX) || doubleVal < static_cast<double>(INT_MIN))
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << intVal << std::endl;
    std::cout << "float: " << floatVal;
    if (intVal == floatVal)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << doubleVal;
    if (intVal == doubleVal)
        std::cout << ".0";
    std::cout << std::endl;  
}

void ScalarConverter::_fromLitteral(std::string str) {
    	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.size() - 1)
			<< std::endl;
		return ;
}

void ScalarConverter::_fromDoubleLitteral(std::string str) {
    	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return ;
}
