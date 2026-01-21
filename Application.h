#pragma once

#include "Dictionary.h"
#include <string>

class Application {
private:
    Dictionary myDict;
    const string DATA_FILE; 

    void showMenu();

public:
    Application();
    void run();
};