#pragma once

#include "Component.h"

void Component::setId(int id) {
    this->id = id;
}

int Component::getId() const {
    return id;
}

Component::Component(int id) {
    this->setId(id);
}