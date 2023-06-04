#include <iostream>
#include <list>

#include "CompilerParser.h"
#include "Token.h"

using namespace std;

int main(){
 list<Token*> tokens;
 
      tokens.push_back(new Token("keyword", "field"));
         tokens.push_back(new Token("identifier", "int"));
         tokens.push_back(new Token("identifier", "a"));
                tokens.push_back(new Token("symbol", ";"));


        try {
        CompilerParser parser(tokens);
        ParseTree* result = parser.compileClassVarDec();
        if (result != NULL){
            cout << result->tostring() << endl;
        }
    }catch (ParseException e) {
        cout << "Error Parsing!" << endl;
    }
}