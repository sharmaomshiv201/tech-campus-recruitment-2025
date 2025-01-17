#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system()

void extractLogs(const std::string &date, const std::string &logFile, const std::string &outputDir)
{
    try
    {
        // Create the output directory using system command
        std::string command = "mkdir " + outputDir;
        system(command.c_str());

        std::string outputFile = outputDir + "/output_" + date + ".txt";
        std::ifstream infile(logFile);
        std::ofstream outfile(outputFile);

        if (!infile.is_open())
        {
            throw std::ios_base::failure("Error: Could not open log file.");
        }
        if (!outfile.is_open())
        {
            throw std::ios_base::failure("Error: Could not create output file.");
        }

        std::string line;
        while (std::getline(infile, line))
        {
            if (line.rfind(date, 0) == 0)
            { // Check if line starts with the date
                outfile << line << '\n';
            }
        }

        infile.close();
        outfile.close();

        std::cout << "Logs for " << date << " have been saved to " << outputFile << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./extract_logs YYYY-MM-DD" << std::endl;
        return 1;
    }

    std::string date = argv[1];
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: Date must be in the format YYYY-MM-DD" << std::endl;
        return 1;
    }

    const std::string logFile = "test_logs.log"; // Replace with actual log file path
    const std::string outputDir = "output";

    extractLogs(date, logFile, outputDir);

    return 0;
}
