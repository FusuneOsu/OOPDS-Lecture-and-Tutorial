#include <fstream>  // for std::ifstream
#include <string>   // for std::string
#include <iostream> // for std::cout
#include <sstream>  // for std::istringstream
#include <vector>
#include "rules.h"

std::string load(std::string filename)
{
    // Open the file for reading
    std::ifstream file(filename);

    // Check if the file was successfully opened
    if (!file.is_open()){ 
        std::string error = "failed to open file";
        return error;
    };

    // Read the contents of the file into a string
    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Close the file
    file.close();


    return contents;
}

std::vector<std::string> getStatements(const std::string &str)
{
    // Create an input string stream from the input string
    std::istringstream iss(str);

    // Create a vector to store the split strings
    std::vector<std::string> lines;

    // Split the input string by ';' and store the resulting strings in the vector
    std::string line;
    while (std::getline(iss, line, '\n'))
    {   
        if(Rules(line).checkSyntax()){
            lines.push_back(line);
        }else{
            throw std::runtime_error("invalid syntax");
        }
    }

    // Return the vector of split strings
    return lines;
}

std::vector<std::string> getStatementTokens(const std::string &str)
{
    // Create an input string stream from the input string
    std::istringstream iss(str);

    // Create a vector to store the split strings
    std::vector<std::string> words;

    // Split the input string by whitespace and store the resulting strings in the vector
    std::string word;
    while (iss >> word)
    {
        words.push_back(word);
    }

    // Return the vector of split strings
    return words;
}

std::vector<Tokenizer> mapTokens(std::vector<std::string> tkn){
    std::vector<Tokenizer> tokens;
    for (int i = 0; i < tkn.size(); i++) {
        tokens.push_back(Tokenizer(tkn[i]));
    }
    return tokens;
}
