#include "commandlineprocessor.h"

CommandLineOptions CommandLineProcessor::parseCommandLine(int argc, char *argv[])
{

    CommandLineOptions cmdOptions;

    cxxopts::Options options("CppStrings", "Sorts a list of strings and remove duplicates on request.");

    options.add_options()
        ("i,input", "Input file name (defaults to cin if option not specified)", cxxopts::value<std::string>())
        ("s,sort", "Sort order (asc or desc)", cxxopts::value<std::string>())
        ("u,unique", "Remove duplicates")
        ("o,output", "Output file name (defaults to cout if option not specified)", cxxopts::value<std::string>())
        ("h,help", "Show help")
        ("example", "Example usage:\nCppString -s asc -u -o output.txt");

    try
    {
        auto result = options.parse(argc, argv);

        if (result.count("help") > 0)
        {
            std::cout << options.help() << std::endl;
            std::exit(0);
        }

        //input/output options
        if (result.count("input") > 1)
        {
            throw std::runtime_error("Too many input files specified. Only one input file is accepted.");
        }
        if (result.count("output") > 1)
        {
            throw std::runtime_error("Too many output files specified. Only one output file is accepted.");
        }
        if (result.count("input") > 0)
        {
            cmdOptions.inputFile = result["input"].as<std::string>();
        }

        if (result.count("output") > 0)
        {
            cmdOptions.outputFile = result["output"].as<std::string>();
        }

        //sort option
        if (result.count("sort") == 0)
        {
            throw std::runtime_error("Sort option must be specified.");
        }
        else if (result.count("sort") > 1)
        {
            throw std::runtime_error("Sort option must be specified one time only.");
        }
        std::string sortOption = result["sort"].as<std::string>();
        if (sortOption == "asc")
        {
            cmdOptions.sortOption = SortOptions::SO_ASC;
        }
        else if (sortOption == "desc")
        {
            cmdOptions.sortOption = SortOptions::SO_DESC;
        }
        else
        {
            throw std::runtime_error("Invalid sort option. Must be 'asc' or 'desc'.");
        }

        // Uniqueness (remove duplicates) option
        cmdOptions.uniqueOption = result.count("unique") > 0;

    } catch (const cxxopts::exceptions::parsing& e) {
        std::cerr << "Error parsing command line options: " << e.what() << std::endl;
        std::exit(1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::exit(1);
    }

    return cmdOptions;
}
