#include "outputdatahandler.h"

void OutputDataHandler::outputStrings(const std::vector<std::string> &strings, const std::optional<std::filesystem::path> outputFile) const
{
    if (outputFile.has_value())
    {
        outputStringsToFile(strings, outputFile.value());
    }
    else
    {
        outputStringsToStdout(strings);
    }
}

void OutputDataHandler::outputStringsToStdout(const std::vector<std::string> &strings) const
{
    for (const auto& str : strings)
    {
        std::cout << str << std::endl;
    }
}

void OutputDataHandler::outputStringsToFile(const std::vector<std::string> &strings, const std::filesystem::path &filename) const
{
    try
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open output file " + filename.string());
        }

        for (const auto& str : strings)
        {
            file << str << '\n';
        }
    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
