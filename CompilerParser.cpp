#include "CompilerParser.h"
using namespace std;
#include <iostream>
/**
 * Constructor for the CompilerParser
 * @param tokens A linked list of tokens to be parsed
 */
CompilerParser::CompilerParser(std::list<Token*> tokens) {
    token=tokens;
}

/**
 * Generates a parse tree for a single program
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileProgram() {
    if(have("keyword","class")){

     ParseTree *m=compileClass();

     return m;

}

else{

    ParseException ParseError;

    throw (ParseError);

}

}

/**
 * Generates a parse tree for a single class
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClass() {
   ParseTree *classt=new ParseTree("class","");

if(mustBe("keyword","class")){

    ParseTree *m=new ParseTree("keyword","class");

    classt->addChild(m);

}

if(have("indenitifer","")){

    ParseTree *m=new ParseTree("identifier",classt->getValue());

    classt->addChild(m);

}

if(mustBe("symbol","{")){

    ParseTree *m=new ParseTree("symbol","{");

    classt->addChild(m);

}

if(mustBe("keyword","static")||mustBe("keyword","field")){

    classt->addChild(compileClassVarDec());

}

if((have("keyword","constructor")||have("keyword","function")||have("keyword","method"))){

    classt->addChild(compileSubroutine());

}

if(mustBe("symbol","}")){

    ParseTree *m=new ParseTree("symbol","}");

    classt->addChild(m);

}

return classt;

}

/**
 * Generates a parse tree for a static variable declaration or field declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClassVarDec() {
    return NULL;
}

/**
 * Generates a parse tree for a method, function, or constructor
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutine() {
    return NULL;
}

/**
 * Generates a parse tree for a subroutine's parameters
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileParameterList() {
   ParseTree *pl=new ParseTree("parameterList","");
       if(have("keyword","")||have("identifier","")){
        if(have("keyword","")){
     ParseTree *k=mustBe("keyword","");
            pl->addChild(k);
        }
        else{
             ParseTree *k=mustBe("identifier","");
            pl->addChild(k);
        }
}
while(i<=token.size()){
    if(have("symbol",",")){
     ParseTree *k=mustBe("symbol",",");
            pl->addChild(k);
        }
       
        if(have("keyword","")||have("identifier","")){
        if(have("keyword","")){
     ParseTree *k=mustBe("keyword","");
            pl->addChild(k);
        }
        else{
                 ParseTree *k=mustBe("identifier","");
            pl->addChild(k);
        }
        i++;   
}
}
    ParseTree *k=mustBe("identifier","");
            pl->addChild(k);
return pl;
}
/**s
 * Generates a parse tree for a subroutine's body
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutineBody() {
    return NULL;
}

/**
 * Generates a parse tree for a subroutine variable declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileVarDec() {
    return NULL;
}

/**
 * Generates a parse tree for a series of statements
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileStatements() {
    return NULL;
}

/**
 * Generates a parse tree for a let statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileLet() {
    return NULL;
}

/**
 * Generates a parse tree for an if statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileIf() {
    return NULL;
}

/**
 * Generates a parse tree for a while statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileWhile() {
    return NULL;
}

/**
 * Generates a parse tree for a do statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileDo() {
    return NULL;
}

/**
 * Generates a parse tree for a return statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileReturn() {
    return NULL;
}

/**
 * Generates a parse tree for an expression
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpression() {
    return NULL;
}

/**
 * Generates a parse tree for an expression term
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileTerm() {
    return NULL;
}

/**
 * Generates a parse tree for an expression list
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileExpressionList() {
    return NULL;
}

/**
 * Advance to the next token
 */
void CompilerParser::next(){
  if(!token.empty()){
    token.pop_front();
  }
}

/**
 * Return the current token
 * @return the Token
 */
Token* CompilerParser::current(){
     if(!token.empty()){
    return token.front();
  }
 return NULL;
}

/**
 * Check if the current token matches the expected type and value.
 * @return true if a match, false otherwise
 */
bool CompilerParser::have(std::string expectedType, std::string expectedValue){
   r=current();
   if(r==NULL){
    return false;
   }
   if(r->getType()==expectedType||expectedType.empty()){
 if(r->getValue()==expectedValue||expectedValue.empty()){
    return true;
 }
   }
   return false;
}

/**
 * Check if the current token matches the expected type and value.
 * If so, advance to the next token, returning the current token, otherwise throw a ParseException.
 * @return the current token before advancing
 */
Token* CompilerParser::mustBe(std::string expectedType, std::string expectedValue){
    if(have(expectedType,expectedValue)){
        r=current();
        next();
        return r;
    }
    else{
       throw new ParseException();
    }
}

/**
 * Definition of a ParseException
 * You can use this ParseException with `throw ParseException();`
 */
const char* ParseException::what() {
    return "An Exception occurred while parsing!";
}
