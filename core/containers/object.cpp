#include "object.hpp"

using namespace lieEngine;

object::object(object *f) : updateable(true), father(f) {
    if (father == nullptr) {
        throw exceptions::Except("father is nullptr", exceptions::level::low, 1);
    }
}

object::object(object *f, std::initializer_list<object *> _childs) {
    childs = _childs;
}

object *object::getFather() const {
    return father;
}

void object::setFather(object *father) {
    object::father = father;
}

bool object::isUpdateable() const {
    return updateable;
}

void object::setUpdateable(bool updateable) {
    object::updateable = updateable;
}

bool object::isOnDelete() const {
    return on_delete;
}
