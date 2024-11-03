#include "ObjectInfo.h"

ObjectInfo::ObjectInfo() : name(""), code(0) {}

ObjectInfo::ObjectInfo(const std::string& name, int code) : name(name), code(code) {}

std::string ObjectInfo::getName() const {
    return name;
}

int ObjectInfo::getCode() const {
    return code;
}

void ObjectInfo::setName(const std::string& name) {
    this->name = name;
}

void ObjectInfo::setCode(int code) {
    this->code = code;
}