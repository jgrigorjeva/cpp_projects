#include <iostream>
// #include <istream>
#include <fstream>
#include <string>

void replace_word(std::string& str, const std::string& to_replace, const std::string& replace_with);

int main(int argc, char *argv[])
{
	if (argc < 4)
    {
        std::cerr << "Incorrect number of arguments." << std::endl;
        return (1);
    }
    std::string inFileName = argv[1];
    std::string outFileName = inFileName + ".replace";
   
    std::ifstream inFile(inFileName.c_str());   // Open file for reading
    if (!inFile)
    {
        std::cerr << "Error: Could not open " << inFileName << std::endl;
        return 1;
    }
	std::ofstream outFile(outFileName.c_str()); // Open file for writing
    if (!outFile) {
        std::cerr << "Error: Could not open " << outFileName << std::endl;
        return 1;
    }
	std::string line;
	while (std::getline(inFile, line))
	{
		replace_word(line, argv[2], argv[3]);
		std::cout << line << std::endl;
        outFile << line << "\n"; // Write modified line to output
    }
	inFile.close();
	outFile.close();
	return 0;
}

void replace_word(std::string& str, const std::string& to_replace, const std::string& replace_with)
{
	if (to_replace == replace_with)
		return ;
	if (to_replace.length() < 1)
		return;
	std::size_t pos = 0;
	while (pos != std::string::npos)
	{
		pos = str.find(to_replace, pos);
		if (pos == std::string::npos)
			break;
		str.erase(pos, to_replace.length());
		str.insert(pos, replace_with);
		pos +=replace_with.length();
	}
	return ;
}