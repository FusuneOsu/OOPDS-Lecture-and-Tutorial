#include <string>   
#include <map>  // for std::map

enum tokenType { 
    TOKEN_TYPE_INDENTIFIER,
    TOKEN_TYPE_VALUE,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_VALUE_TYPE,
    TOKEN_TYPE_KEYWORD,
};

std::map<std::string, int> mapping = {
    // identifiers
    {"Var", 1},

    // value types
    {"string", 2},
    {"int", 3},
    {"float", 4},
    {"double", 5},
    {"bool", 6},

    // operators
    {"-", 7},
    {"+", 8},
    {"*", 9},
    {"/", 10},
    {"%", 11},
    {"^", 12},

    // keywords
    {"print", 13},
};

class AllocatedVal {
  public:             
    tokenType type;
    std::string name;
    std::string value;

    AllocatedVal(tokenType t, std::string n, std::string v){
        type = t; value = v; name = n;
    };
};

class Tokenizer{

    public:
    tokenType type;
    std::string value;

    Tokenizer(std::string val){
        value = val;
        type = defineType(val);
    };

    tokenType defineType(std::string val){
        switch (mapping[val]) {
        case 1:
            return TOKEN_TYPE_INDENTIFIER;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return TOKEN_TYPE_VALUE_TYPE;

        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            return TOKEN_TYPE_OPERATOR;

        case 13:
            return TOKEN_TYPE_KEYWORD;
        
        default:
            return TOKEN_TYPE_VALUE;
        }
    }
};

