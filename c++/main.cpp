#include <iostream>
#include "utils/tokenizer.h"
#include "utils/parser.h"
#include <map>
#include <vector>

using namespace std;

int main() {
  cout << "------------------------------------------------------------" << endl;
  cout << "                       ANMO Interpeter                      " << endl;
  cout << "------------------------------------------------------------" << endl;
  string fileName = "test.anmo";
  cout << "Loading file: " << fileName << endl;
  cout << "------------------------------------------------------------" << endl;

  std::vector<string> statements = getStatements(
    load(fileName)
  );

  std::map<std::string, AllocatedVal> allocatedVars;

  for (int i = 0; i < statements.size(); i++) {
    std::vector<string> tokenString = getStatementTokens(statements[i]);
    std::vector<Tokenizer> tokens = mapTokens(tokenString); // Var <var type> <var name> = <value>

    // execution engine
    if (tokens[0].type == TOKEN_TYPE_VALUE || tokens[0].type == TOKEN_TYPE_OPERATOR) {
      throw std::runtime_error("can not start with value or operator");
    }

    if (tokens[0].type == TOKEN_TYPE_INDENTIFIER) {
      if (tokens[1].type != TOKEN_TYPE_VALUE_TYPE) throw std::runtime_error("data type should not defined");
      if (tokens[2].type != TOKEN_TYPE_VALUE) throw std::runtime_error("value should not defined");
      if (tokens.size() != 5 && tokens.size() != 3) throw std::runtime_error("value should not defined");
      if (tokens.size() == 3){

        allocatedVars.insert({ 
          tokens[2].value,
          AllocatedVal(tokens[1].type, tokens[2].value, "")
        });

      } else {
        if (tokens[3].type != TOKEN_TYPE_OPERATOR ) throw std::runtime_error("invalid token"); // =
        if (tokens[4].type != TOKEN_TYPE_VALUE ) throw std::runtime_error("invalid token"); // value
        
        allocatedVars.insert({ 
          tokens[2].value,
          AllocatedVal(tokens[1].type, tokens[2].value, tokens[4].value)
        });

      }
    }
  }
  cout << "------------------------------------------------------------" << endl;
  system("pause");
  return 0;
}