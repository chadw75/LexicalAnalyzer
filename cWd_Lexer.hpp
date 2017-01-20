//  Created by Chad Wanderscheid on 1/18/2016
//  Copyright (c) 2016 Chad Wanderscheid. All rights reserved.

#ifndef cWd_Lexer.hpp
#define cWd_Lexer.hpp


using namespace std;

class cWd_Lexer { //: public PreprosserLexer{

public:
    
    cWd_Lexer();
    ~cWd_Lexer();
    // member functions
    int isExAcceptableChar(char);
    int isDelimiter(char);
    int isMathOperators(char);
    int isBeginingRelationalOperator(char);
    
    void identifyWords();                   // keywords or !
    
    void printToken(Token *);               // func prototype
    void printWords();
    void printKeywords();
    void printNumbers();
    void printIdentifiers();
    void printDelimiters();
    void printMathOperators();
    void printRelationalOperators();
    void printLogSummary();

    
    
private:
    
   
};
#endif


/*
    void anchor() override;
    
    const char * BufferStart;
    const char * BufferEnd;
    Sourcelocation FileLocation;
    LanguageOptions;
    
    bool Is_PragmaLexer;
    
    unsigned char ExtendedTokenMode;
    
    const char * BufferPtr;
    
    bool IsAtStartOfLine;
    bool IsAtPhysicalStartOfLine;
    bool HasLeadingSpace;
    bool HasLeadingEmptyMacro;
    
    ConflictMarkerKind CurrentConflictMarkerState;
    
    //Lexer(const Lexer &) = delete;
    
    //void operator=(const Lexer &) = delete;
    
    //friend class cWd_Preprocessor;
    
    void InitLexer(const char *BufStart, const char *BufPtr, const char *BufEnd);
*/
