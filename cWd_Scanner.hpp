//  Created by Chad Wanderscheid on 1/18/2016
//  Copyright (c) 2016 Chad Wanderscheid. All rights reserved.

#ifndef cWd_Scanner.hpp
#define cWd_Scanner.hpp


class cWd_Scanner {
    // <#instance variables#>
    
    
public:
    
    cwd_Scanner();
    ~cWd_Scanner();
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

};

#endif
