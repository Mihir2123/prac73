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
 ParseTree *classm=new ParseTree("class","");
  if(!have("keyword","class")){
      ParseException ParseError;
    throw (ParseError);
 } 
 else{
    while(token.size()){
            classm->addChild(mustBe("keyword","class"));
  

            classm->addChild(mustBe("identifier",""));
 
            classm->addChild(mustBe("symbol","{"));
 
   if(have("keyword","static")||have("keyword","field")){
 classm->addChild(compileClassVarDec());
 } 
   if(have("keyword","constructor")||have("keyword","method")||have("keyword","function")){
 classm->addChild(compileSubroutine());
 } 
            classm->addChild(mustBe("symbol","}"));
 
    }
 
 }

 return classm;
}

/**
 * Generates a parse tree for a static variable declaration or field declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileClassVarDec() {
    ParseTree *classvardec=new ParseTree("classVarDec","");
   if(!have("keyword","static")&&!have("keyword","field")){
            ParseException ParseError;
    throw (ParseError);
    }
    else{
      if(have("keyword","static")||have("keyword","field")){

            classvardec->addChild(mustBe("keyword",""));
          
            if(have("keyword","")){
            ParseTree *k=mustBe("keyword","");
            classvardec->addChild(k);
          }
          if(have("identifier","")){
             ParseTree *k=mustBe("identifier","");
            classvardec->addChild(k);
          }
           if(have("identifier","")){
             ParseTree *k=mustBe("identifier","");
            classvardec->addChild(k);
          }
          while(!have("symbol",";")){
            classvardec->addChild(mustBe("symbol",","));
          if(have("identifier","")){
             ParseTree *k=mustBe("identifier","");
            classvardec->addChild(k);
          }
          }
        }
    }
  
            classvardec->addChild(mustBe("symbol",";"));
    
return classvardec;
}

/**
 * Generates a parse tree for a method, function, or constructor
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutine() {
     ParseTree *subroutine=new ParseTree("subroutine","");
   if(!have("keyword","constructor")&&!have("keyword","method")&&!have("keyword","function")){
            ParseException ParseError;
    throw (ParseError);
    }
    else{

           subroutine->addChild(mustBe("keyword",""));
         
            if(have("keyword","")||have("identifier","")){
if(have("keyword","")){
            ParseTree *k=mustBe("keyword","");
             subroutine->addChild(k);
          }
         else{
             ParseTree *k=mustBe("identifier","");
           subroutine->addChild(k);
          }
        }
        subroutine->addChild(mustBe("identifier",""));
       
  
         subroutine->addChild(mustBe("symbol","("));
    
    subroutine->addChild(compileParameterList());
         subroutine->addChild(mustBe("symbol",")"));
    
       subroutine->addChild(compileSubroutineBody());
    }
return subroutine;

}

/**
 * Generates a parse tree for a subroutine's parameters
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileParameterList() {
     ParseTree *parameterlist=new ParseTree("parameterList","");
   
        if(have("keyword","")||have("keyword","")){
if(have("keyword","")){
            ParseTree *k=mustBe("keyword","");
           parameterlist->addChild(k);
          }
         else{
             ParseTree *k=mustBe("identifier","");
          parameterlist->addChild(k);
          }
        }
     
      
          parameterlist->addChild(mustBe("identifier",""));
          while(token.size()){
          parameterlist->addChild(mustBe("symbol",","));
           
           if(have("keyword","")||have("identifier","")){
if(have("keyword","")){
            ParseTree *k=mustBe("keyword","");
           parameterlist->addChild(k);
          }
         else{
             ParseTree *k=mustBe("identifier","");
          parameterlist->addChild(k);
          }
        }
          
          parameterlist->addChild(mustBe("identifier",""));
        
          }
            return parameterlist;
    }
   
       
        

/**s
 * Generates a parse tree for a subroutine's body
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileSubroutineBody() {
       ParseTree *subroutinebody=new ParseTree("subroutineBody","");
          subroutinebody->addChild(mustBe("symbol","{"));
        while(have("keyword","var")){
            subroutinebody->addChild(compileClassVarDec());
        }
  subroutinebody->addChild(compileStatements());
         
        subroutinebody->addChild(mustBe("symbol","}"));
           
    return subroutinebody;
}

/**
 * Generates a parse tree for a subroutine variable declaration
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileVarDec() {
      ParseTree *VarDec=new ParseTree("varDec","");
      VarDec->addChild(mustBe("keyword","var"));
         if(have("keyword","")||have("identifier","")){
if(have("keyword","")){
            ParseTree *k=mustBe("keyword","");
           VarDec->addChild(k);
          }
         else{
             ParseTree *k=mustBe("identifier","");
          VarDec->addChild(k);
          }
        }
         VarDec->addChild(mustBe("identifier",""));
         while(have("symbol",",")){
          VarDec->addChild(mustBe("symbol",","));
            VarDec->addChild(mustBe("identifier",""));
         }
   VarDec->addChild(mustBe("symbol",";"));
    return VarDec;
}

/**
 * Generates a parse tree for a series of statements
 * @return a ParseTree
 */
ParseTree* CompilerParser::compileStatements() {
     ParseTree *Statement=new ParseTree("statements","");
     while(token.size()){
       if(have("keyword","if")){
        Statement->addChild(compileIf());
      }
     }
     return Statement;
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
     ParseTree *Statementif=new ParseTree("ifStatements","");
     Statementif->addChild(mustBe("keyword","if"));
      Statementif->addChild(mustBe("symbol","("));
          Statementif->addChild(compileExpression());
            Statementif->addChild(mustBe("symbol",")"));
             Statementif->addChild(mustBe("symbol","{"));
                  Statementif->addChild(compileStatements());
             Statementif->addChild(mustBe("symbol","}"));
            while(token.size()){
              if(have("keyword","else")){
     Statementif->addChild(mustBe("keyword","else"));
        Statementif->addChild(mustBe("symbol","{"));
                  Statementif->addChild(compileStatements());
             Statementif->addChild(mustBe("symbol","}"));
              }
            }
            return Statementif;
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
       ParseException a;
        throw (a);
    }
}

/**
 * Definition of a ParseException
 * You can use this ParseException with `throw ParseException();`
 */
const char* ParseException::what() {
    return "An Exception occurred while parsing!";
}
