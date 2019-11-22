#include "../includes/animal.h"

Animal::Animal() {}

Animal::~Animal() {}

std::ostream& operator<< (std::ostream &o, Animal &f) {
    f.print(o);
    return o;
}

int Animal::getId() {
    return id;
}