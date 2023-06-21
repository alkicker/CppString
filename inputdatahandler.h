#ifndef INPUTDATAHANDLER_H
#define INPUTDATAHANDLER_H

#include <iostream>
#include <optional>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

class InputDataHandler
{
public:
    InputDataHandler() {}
    std::vector<std::string> readStringsFromInput(const std::optional<std::filesystem::path> inputFile) const;

private:
    std::vector<std::string> readStringsFromStdin() const;
    std::vector<std::string> readStringsFromFile(const std::filesystem::path& filename) const;
};


#endif // INPUTDATAHANDLER_H
