#ifndef cWd_Token.hpp
#define cWd_Token.hpp

#define MAX 8 // max length of each word string
#define LIMIT 200 // max number of word strings in an input file

typedef enum {
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    REL_OP, 	// such as ==  <  >  =!=    =>  =<
    OP,			// such as = :  +  -  *  / %
    DELIM,		// such as . (  ) , { } ; [ ]
    
    UNDEF,		// undefined
    EOT 		// end of token
    /*
     REL_OP_EQUAL, // ==
     REL_OP_GREATER, // >
     REL_OP_LESS_THAN, // <
     REL_OP_NOT_EQUAL, // =!=
     REL_OP_NOT_GREATER, // =<
     REL_OP_NOT_LESS_THAN, // =>
     
     OP_ASSIGN, // =
     OP_COLON, // :
     OP_DIV, // /
     OP_MUL, // *
     OP_ADD, // +
     OP_SUBTRACT, // -
     OP_REMAINDER, // %
     
     DELIM_DOT, // .
     DELIM_LEFT_PARRENTHESE, // (
     DELIM_RIGHT_PARRENTHESE, // )
     DELIM_COMMA, // ,
     DELIM_LEFT_BRACE, // {
     DELIM_RIHGT_BRACE, // }
     DELIM_LEFT_BRACKET, // [
     DELIM_RIGHT_BRACKET, // ]
     DELIM_SEMICOLON, // ;
     */
    
} cWd_TokenType;

typedef struct {
    cWd_TokenType aTokenType;
    char *instance;
    int lineNum;
    
} cWd_Token;
#endif
