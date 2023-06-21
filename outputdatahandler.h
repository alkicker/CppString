#ifndef OUTPUTDATAHANDLER_H
#define OUTPUTDATAHANDLER_H

#include <iostream>
#include <optional>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

class OutputDataHandler
{
public:
    OutputDataHandler() {}
    void outputStrings(const std::vector<std::string>& strings, const std::optional<std::filesystem::path> outputFile) const;

private:
    void outputStringsToStdout(const std::vector<std::string>& strings) const;
    void outputStringsToFile(const std::vector<std::string>& strings, const std::filesystem::path& filename) const;
};




#endif // OUTPUTDATAHANDLER_H
