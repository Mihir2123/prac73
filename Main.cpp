#include <iostream>
#include <list>

#include "CompilerParser.h"
#include "Token.h"

using namespace std;


int main(int argc, char *argv[]) {
 list<Token*> tokens;
 

                   tokens.push_back(new Token("integerConstant", "1"));
                     

        try {
        CompilerParser parser(tokens);
        ParseTree* result = parser.compileTerm();
                    cout << result->tostring() << endl;
        }
    
    catch (ParseException e) {
        cout << "Error Parsing!" << endl;
    }
}