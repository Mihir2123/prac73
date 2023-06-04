#include <iostream>
#include <list>

#include "CompilerParser.h"
#include "Token.h"

using namespace std;


int main(int argc, char *argv[]) {
 list<Token*> tokens;
 

                      tokens.push_back(new Token("identifier", "b"));
                tokens.push_back(new Token("symbol", ","));
                             tokens.push_back(new Token("identifier", "a"));
                   

        try {
        CompilerParser parser(tokens);
        ParseTree* result = parser.compileParameterList();
                    cout << result->tostring() << endl;
        }
    
    catch (ParseException e) {
        cout << "Error Parsing!" << endl;
    }
}