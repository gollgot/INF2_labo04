//
// Created by loic on 4/9/19.
//

#ifndef EXCEPTION_BAD_ALLOC_H
#define EXCEPTION_BAD_ALLOC_H

#include <stdexcept>

class Exception_bad_alloc : public std::bad_alloc{

public:
    /**
     * @brief Constructor with string parameter
     * @param what The error message
     */
    explicit Exception_bad_alloc(const std::string& what): bad_alloc(), whatMsg(what){};
    /**
     * @brief Constructor with char* parameter
     * @param what The error message
     */
    explicit Exception_bad_alloc(const char* what): bad_alloc(), whatMsg(what){};

    /**
     * @brief Return the error message
     * @return Error message
     */
    std::string _what() const {
        return whatMsg;
    }

private:
    std::string whatMsg;
};

#endif //EXCEPTION_BAD_ALLOC_H
