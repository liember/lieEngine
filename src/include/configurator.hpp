#pragma once

#include <iostream>
#include <fstream>

#include "pcs.hpp"
#include "property.hpp"

using namespace std;

class configurator
{
private:
    bool checkFile(char *file_name);

public:
    configurator(/* args */);
    ~configurator();
};

configurator::configurator(/* args */)
{
}

configurator::~configurator()
{
}

bool checkFile(char *file_name)
{
    ifstream file;
    file.open(file_name);
    if (!file)
    {
        cout << "\n[!] Cant find file : " << file_name;
        return false;
    }
    cout << "\n[?] File has founded : " << file_name;
    return true;
}