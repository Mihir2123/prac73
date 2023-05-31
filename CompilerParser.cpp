#include "CompilerParser.h"


/**
 * Constructor for the CompilerParser
 * @param tokens A linked list of tokens to be parsed
 */
CompilerParser::CompilerParser(std::list<Token*> tokens) {
    m=tokens;
}

/**
 * Generates a parse tree for a single program
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileProgram() {
     ParseTree *classm=new ParseTree("class","");
if(mustBe("keyword","class")){
    ParseTree *k=new ParseTree("keyword","class");
    classm->addChild(k);
    if(mustBe("identifier","Main")){
    ParseTree *k=new ParseTree("identifier","Main");
    classm->addChild(k);
}
if(mustBe("symbol","{")){
    ParseTree *k=new ParseTree("symbol","{");
    classm->addChild(k);
}
if(mustBe("symbol","}")){
    ParseTree *k=new ParseTree("symbol","}");
    classm->addChild(k);
}
}
else{
    ParseException ParseError;
    throw (ParseError);
}
return classm;

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
if(mustBe("identifier","Main")){
    ParseTree *m=new ParseTree("identifier","Main");
    classt->addChild(m);
}
if(mustBe("symbol","{")){
    ParseTree *m=new ParseTree("symbol","{");
    classt->addChild(m);
}
if(mustBe("keyword","static")||mustBe("keyword","field")){
    classt->addChild(compileClassVarDec());
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
    ParseTree *w=new ParseTree("subroutine","");
    if(!have("keyword","constructor")||!have("keyword","function")||!have("keyword","method")){
         ParseException ParseError;
    throw (ParseError);
    }


 

return w;

}

/**
 * Generates a parse tree for a subroutine's parameters
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileParameterList() {
    return NULL;
}

/**
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
     ParseTree *statement=new ParseTree("statements","");
    while(have("keyword","let")||have("keyword","while")||have("keyword","if")||have("keyword","do")||have("keyword","return")){
        if(mustBe("keyword","let")){
             statement->addChild(compileLet());
        }
           if(mustBe("keyword","while")){
            statement->addChild(compileWhile());
        }
         if(mustBe("keyword","if")){
            statement->addChild(compileIf());
        }
         if(mustBe("keyword","do")){
            statement->addChild(compileDo());
        }
          if(mustBe("keyword","return")){
            statement->addChild(compileReturn());
        }
    
    }
    return statement;
}

/**
 * Generates a parse tree for a let statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileLet() {
     ParseTree *letstatement=new ParseTree("letStatement","");
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
  if(!m.empty()){
    m.pop_front();
  }
}

/**
 * Return the current token
 * @return the Token
 */
Token* CompilerParser::current(){
     if(!m.empty()){
    return m.front();
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
 if(r->getValue()==expectedValue||expectedType.empty()){
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
