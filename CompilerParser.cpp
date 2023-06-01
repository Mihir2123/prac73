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
return NULL;
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

    else{

        if(have("keyword","constructor")){

                     ParseTree *m=new ParseTree("keyword","constructor");

    w->addChild(m);

        }

        if(have("keyword","function")){

              ParseTree *m=new ParseTree("keyword","function");

    w->addChild(m);

        }

          if(have("keyword","method")){

              ParseTree *m=new ParseTree("keyword","method");

    w->addChild(m);

        }

    }

        if(have("keyword","int")||have("keyword","char")||have("keyword","boolean")||have("identifier","")||have("keyword","void")){

          if(have("keyword","int")){

               ParseTree *m=new ParseTree("keyword","int");

    w->addChild(m);

        }

         if(have("keyword","char")){

               ParseTree *m=new ParseTree("keyword","char");

    w->addChild(m);

        }

          if(have("keyword","boolean")){

               ParseTree *m=new ParseTree("keyword","boolean");

    w->addChild(m);

        }

          if(have("identifier","")){

               ParseTree *m=new ParseTree("identifier",m->getValue());

    w->addChild(m);

        }

         if(have("keyword","void")){

               ParseTree *m=new ParseTree("keyword","void");

    w->addChild(m);

        }

        

     }

     if("idetifier",""){

         ParseTree *m=new ParseTree("identifier",m->getValue());

    w->addChild(m);

     }

     if(mustBe("symbol","(")){

         ParseTree *m=new ParseTree("symbol","(");

    w->addChild(m);

     }

     w->addChild(compileParameterList());

     if(mustBe("symbol",")")){

           ParseTree *m=new ParseTree("symbol",")");

    w->addChild(m);

     }

     w->addChild(compileSubroutineBody());


    


return w;



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
        ParseTree *vardec=new ParseTree("varDec","");
    if(mustBe("keyword","var")){
                   ParseTree *m=new ParseTree("keyword","var");
    vardec->addChild(m);
        }
    if(have("keyword","")||have("identifier","")){
     while(!have("symbol",";")){
          if(have("keyword","")){
               ParseTree *m=mustBe("keyword","");
    vardec->addChild(m);
        }
      else {
               ParseTree *m=mustBe("identifier","");
    vardec->addChild(m);
        }

     }

    }
    if(mustBe("symbol",";")){
            ParseTree *m=new ParseTree("symbol",";");
    vardec->addChild(m);
    }
    return vardec;
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
