//
// Created by mfbut on 11/24/2019.
//

#include "DoublyLinkedListEmptyError.h"
#include <sstream>
#include <string>

DoublyLinkedListEmptyError::DoublyLinkedListEmptyError() : DoublyLinkedListError("Attempted to access a list with no elements\n") {}
