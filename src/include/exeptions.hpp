#pragma once

#include <iostream>

class propertySwapping : public std::exception
{
private:
    std::string info;

public:
    virtual const char *what() const throw()
    {
        return "[!] Property already created and linked with other propertyes";
    }
};

class fileNotExist : public std::exception
{
private:
    std::string info;

public:
    virtual const char *what() const throw()
    {
        return "[!] File does not exist or path specified";
    }
};