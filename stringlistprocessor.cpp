#include "stringlistprocessor.h"


void StringListProcessor::sortStringsAscending(std::vector<std::string> &strings)
{
    std::sort(strings.begin(), strings.end());
}

void StringListProcessor::sortStringsDescending(std::vector<std::string> &strings)
{
    std::sort(strings.rbegin(), strings.rend());
}

// Precondition: this method works only on sorted vectors
// This is not a pb here because sorting option is mandatory
// if this changes, we must change this implementation
void StringListProcessor::removeDuplicates(std::vector<std::string> &strings)
{
    strings.erase(std::unique(strings.begin(), strings.end()), strings.end());
}
