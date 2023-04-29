#include "../Includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        this->_source[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; i++) {
        if (this->_source[i]) {
            this->_source[i] = other._source[i]->clone();
        }
        else {
            this->_source[i] = nullptr;
        }
    }
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        delete this->_source[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    for (int i = 0; i < 4; i++) {
        delete this->_source[i]; 
        if (this->_source[i]) {
            this->_source[i] = other._source[i]->clone();
        }
        else {
            this->_source[i] = nullptr;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_source[i] == nullptr) {
            this->_source[i] = m;
            return;
        }
    }
    std::cout << "Materia Source full" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++) {
        if (_source[i] && this->_source[i]->getType().compare(type) == 0) {
            return (_source[i]->clone());
        }
    }
    std::cout << "Unknown or Unvalid Type of Materia" << std::endl;
    return (nullptr);
}
