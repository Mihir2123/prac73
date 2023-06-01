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
         ParseTree * classvardec=new ParseTree("classVarDec","");
             if(!have("keyword","static")||!have("keyword","field")){
         ParseException ParseError;
    throw (ParseError);
    }
    else{
        if(have("keyword","static")){
             ParseTree *m=new ParseTree("keyword","static");
    classvardec->addChild(m);
        }
        if(have("keyword","field")){
               ParseTree *m=new ParseTree("keyword","field");
    classvardec->addChild(m);
        }
    }
    return classvardec;

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
     if(mustBe("indentifier","do"))
    return NULL;
}

/**
 * Generates a parse tree for an if statement
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileIf() {
     ParseTree *ifstatement=new ParseTree("ifStatement","");
     if(mustBe("keyword","if")){
            ParseTree *m=new ParseTree("keyword","if");
    ifstatement->addChild(m);
     }
       if(mustBe("symbol","(")){
            ParseTree *m=new ParseTree("symbol","(");
    ifstatement->addChild(m);
     }
       ifstatement->addChild(compileExpression());
        if(mustBe("symbol",")")){
            ParseTree *m=new ParseTree("symbol",")");
    ifstatement->addChild(m);
     }
             if(mustBe("symbol","{")){
            ParseTree *m=new ParseTree("symbol","(");
    ifstatement->addChild(m);
     }
      ifstatement->addChild(compileStatements());
  if(mustBe("symbol","}")){
            ParseTree *m=new ParseTree("symbol","}");
    ifstatement->addChild(m);
     }


     
      if(have("keyword","else")){
            ParseTree *m=new ParseTree("keyword","else");
    ifstatement->addChild(m);
     if(mustBe("symbol","{")){
            ParseTree *m=new ParseTree("symbol","(");
    ifstatement->addChild(m);
     }
      ifstatement->addChild(compileStatements());
  if(mustBe("symbol","}")){
            ParseTree *m=new ParseTree("symbol","}");
    ifstatement->addChild(m);
     }
     }
     return ifstatement;
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
