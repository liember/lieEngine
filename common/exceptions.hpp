#include <exception>
#include <string>

#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

class Exception : virtual public std::exception
{

protected:
    const std::string error_message;

public:
    explicit Exception(const std::string &msg) : error_message(msg)
    {
    }
    virtual ~Exception() throw() {}

    virtual const char *what() const throw()
    {
        return error_message.c_str();
    }
};
#endif // __EXCEPTIONS_H__