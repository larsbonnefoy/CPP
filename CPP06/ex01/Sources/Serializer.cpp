#include "../Includes/Serializer.hpp"

Serializer::Serializer(void){
}

Serializer::Serializer(const Serializer &other){
    (void) other;
}

Serializer::~Serializer(){
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void) other;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
    uintptr_t resptr;

    resptr = reinterpret_cast<uintptr_t>(ptr);
    return resptr;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data *resData;

    resData = reinterpret_cast<Data *>(raw);
    return (resData);
}
