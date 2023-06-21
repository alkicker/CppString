#ifndef STRINGLISTPROCESSOR_H
#define STRINGLISTPROCESSOR_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Class for processing the list of strings
class StringListProcessor
{
public:
    StringListProcessor() {}

    void sortStringsAscending(std::vector<std::string>& strings);

    void sortStringsDescending(std::vector<std::string>& strings);

    // Precondition: this method works only on sorted vectors
    // This is not a pb here because sorting option is mandatory
    // if this changes, we must change this implementation
    void removeDuplicates(std::vector<std::string>& strings);
};


#endif // STRINGLISTPROCESSOR_H
