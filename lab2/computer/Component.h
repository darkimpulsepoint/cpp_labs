#pragma once

class Component {

private:
    int id = 0;

public:
    Component(int id);

    int getId() const;
    void setId(int id);
};