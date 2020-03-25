#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface {
public:
    std::string read_name(int i);
    std::pair<int, int> ask_shot();
    void show_error(std::string & s);
};

#endif // INTERFACE_H