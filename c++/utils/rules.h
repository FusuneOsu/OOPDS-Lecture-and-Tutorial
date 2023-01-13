#include <string>   // for std::string
#include <regex>


class Rules {
  public:
    std::string line;             

    Rules(std::string ln){
        line = ln;
    };

    bool initalizitionRule(){
        std::regex pattern("^\\s*(int|double|float|char)\\s+\\w+\\s*=\\s*\\d+(\\.\\d+)?\\s*;\\s*$");

        return std::regex_match(line, pattern);
    }

    bool assignmentRule(){
        std::regex pattern("^\\s*\\w+\\s*=\\s*\\d+(\\.\\d+)?\\s*;\\s*$");

        return std::regex_match(line, pattern);
    }

    bool expressionRule(){
        std::regex pattern("^\\s*\\d+(\\.\\d+)?\\s*([+\\-*/])\\s*\\d+(\\.\\d+)?\\s*$");

        return std::regex_match(line, pattern);
    }

    bool keywordRule(){
        std::regex pattern("^\\s*(print)\\s+\\w+\\s*;\\s*$");

        return std::regex_match(line, pattern);
    }

    bool checkSyntax() {
        bool result = false;
        // initializitionRule
        result = initalizitionRule();

        // assignmentRule
        result = assignmentRule();

        // keywordRule
        result = keywordRule();

        // Try to match the string against the pattern.
        return result;
    }
};
