#ifndef cWd_SymbolDefinitions.hpp
#define cWd_SymbolDefinitions.hpp

char *keywords[15] = {"start", "finish", "then", "if", "repeat", "var",
    "int", "float", "do",
    "read", "print", "void", "return", "dummy", "program"};

char *relationalOperators[] = {"==", "<", ">", "=!=", "=>", "=<"};

// char *otherOperators[] = {":", "+", "-", "*", "/", "%"};
char mathOperators[6] = {':', '+', '-', '*', '/', '%'};

// char *delimiters[9] = {".", "(", ")", ",", "{", "}", ";", "[", "]"};
char delimiters[9] = {'.', '(', ')', ',', '{', '}', ';', '[', ']'};

char words[LIMIT][MAX]; // include identifiers, and keywords
int wordi = 0, wordj = 0;
int wordLineNums[LIMIT];

char keys[LIMIT][MAX]; // to store keywords
int keyi = 0;
int keyLineNums[LIMIT];

char idens[LIMIT][MAX]; // to store identifiers
int ideni = 0;
int idenLineNums[LIMIT];

char nums[LIMIT][MAX];  // to store numbers
int numi = 0, numj = 0;
int numLineNums[LIMIT];

/*--------------------*/
char delims[LIMIT]; // to store delimiters
int delimi = 0;
int delimLineNums[LIMIT];

char otherOps[LIMIT]; // to store other operators
int otherOpi = 0;
int otherOpLineNums[LIMIT];

char relOps[LIMIT][MAX]; // to store keywords
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];











#endif
