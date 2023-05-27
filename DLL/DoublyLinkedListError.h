//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#include <string>

class DoublyLinkedListError : public std::exception {

public:
    DoublyLinkedListError(const std::string& message);
    virtual const char* what() const noexcept {
        return message.c_str();
    }
protected:
    std::string message;
};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
