

#include <stdio.h>

#include "cWd_Token.hpp"
#include "cWd_Scanner.hpp"
#include "cWd_Lexer.hpp"
#include "cWd_SymbolDefinitions.hpp"

/*--------------------Begin getTokenType()--------------------*/

cWd_TokenType getTokenType(FILE *filePtr) {
    int lineNum = 1;
    char ch;
    
    while ((ch = fgetc(filePtr)) != EOF) {
        if (ch == '\n') {
            lineNum++;
        }
        
        // Ignore comment starting with // to the end of line
        if (ch == '/') {
            if (fgetc(filePtr) == '/') {
                while ((ch = fgetc(filePtr)) != '\n') {}
                lineNum++;
            } else
                fseek(filePtr, -1, SEEK_CUR);
        }
        
        if (isalpha(ch)) {
            words[wordi][wordj++] = ch;
            while (isalpha(ch = fgetc(filePtr))) {
                words[wordi][wordj++] = ch;
            }
            words[wordi][wordj] = '\0';
            wordLineNums[wordi] = lineNum;
            wordi++; wordj = 0;
            fseek(filePtr, -1, SEEK_CUR);
        }
        
        else if (isdigit(ch)) {
            nums[numi][numj++] = ch;
            while (isdigit(ch = fgetc(filePtr))) {
                nums[numi][numj++] = ch;
            }
            nums[numi][numj] = '\0';
            numLineNums[numi] = lineNum;
            numi++; numj = 0;
            fseek(filePtr, -1, SEEK_CUR);
        }
        
        else if (ispunct(ch)) {
            if (isDelimiter(ch)) {
                delims[delimi] = ch;
                delimLineNums[delimi] = lineNum;
                delimi++;
            }
            else if (isMathOperators(ch)) {
                otherOps[otherOpi] = ch;
                otherOpLineNums[otherOpi] = lineNum;
                otherOpi++;
            }
            else if (isRelationalOperator(ch)) {
                if (ch == '<' || ch == '>') {
                    relOps[relOpi][relOpj++] = ch;
                    relOps[relOpi][relOpj] = '\0';
                    relOpLineNums[relOpi] = lineNum;
                    relOpi++; relOpj = 0;
                }
                else if (ch == '=') {
                    if ((ch = fgetc(filePtr)) == '=' || ch == '>' || ch == '<') {
                        relOps[relOpi][relOpj++] = '=';
                        relOps[relOpi][relOpj++] = ch;
                        relOps[relOpi][relOpj] = '\0';
                        relOpLineNums[relOpi] = lineNum;
                        relOpi++; relOpj = 0;
                    } else if (ch == '!') {
                        if ((ch = fgetc(filePtr)) == '=') {
                            relOps[relOpi][relOpj++] = '=';
                            relOps[relOpi][relOpj++] = '!';
                            relOps[relOpi][relOpj++] = ch;
                            relOps[relOpi][relOpj] = '\0';
                            relOpLineNums[relOpi] = lineNum;
                            relOpi++; relOpj = 0;
                        } else {
                            fseek(filePtr, -1, SEEK_CUR);
                        }
                    } else {
                        fseek(filePtr, -1, SEEK_CUR);
                    }
                    
                }
            }
        }
    } // end while
    
    identifyWords();
    
    printSummary();
    
    return EOT; // end of token
}

/*--------------------/End getTokenType()--------------------*/

void printSummary() {
    printf("----------BEGIN SUMMARY---------- \n");
    
    printf("***Note format: token (line #) \n\n");
    
    printf("Total %d KEYWORDS found are: \n", keyi);
    printKeywords();
    printf("***/END KEYWORD SUMMARY*** \n");
    
    printf("\nTotal %d IDENTIFIERS found are: \n", ideni);
    printIdentifiers();
    printf("***/END IDENTIFIER SUMMARY*** \n");
    
    printf("\nTotal %d NUMBERS found are: \n", numi);
    printNumbers();
    printf("***/END NUMBER SUMMARY*** \n");
    
    printf("\nTotal %d DELIMITERS found are: \n", delimi);
    printDelimiters();
    printf("***/END DELIMITER SUMMARY*** \n");
    
    printf("\nTotal %d RELATIONAL OPERATORS found are: \n", relOpi);
    printRelationalOperators();
    printf("***/END RELATIONAL OPERATOR SUMMARY*** \n");
    
    printf("\nTotal %d OTHER OPERATORS found are: \n", relOpi);
    printOtherOperators();
    printf("***/END OTHER OPERATOR SUMMARY*** \n");
    
    printf("\n----------/END SUMMARY----------- \n");
}

int isRelationalOperator(char c) {
    int i;
    int result = 0; // false
    if (c == '=' || c == '<' || c == '>') {
        result = 1;
    }
    return result;
}

int isMathOperators(char c) {
    int i;
    int result = 0; // false
    for (i = 0; i < 6; i++) {
        if (otherOperators[i] == c)
            result = 1;
    }
    return result;
}

int isDelimiter(char c) {
    int i;
    int result = 0; // false
    for (i = 0; i < 9; i++) {
        if (delimiters[i] == c)
            result = 1;
    }
    return result;
}

int isKeyword(char *str) {
    int i;
    int result = 0; // false
    for (i = 0; i < 15; i++) {
        if (!strcasecmp(keywords[i], str))
            result = 1;
    }
    return result;
}

void printMathOperators() {
    int i;
    for (i = 0; i < otherOpi; i++) {
        printf("%c \t (line #%d) \n", otherOps[i], otherOpLineNums[i]);
    }
}

void printDelimiters() {
    int i;
    for (i = 0; i < delimi; i++) {
        printf("%c \t (line #%d) \n", delims[i], delimLineNums[i]);
    }
}

void printRelationalOperators() {
    int i;
    for (i = 0; i < relOpi; i++) {
        printf("%s \t (line #%d) \n", relOps[i], relOpLineNums[i]);
    }
}

void printWords() {
    // printf("Num of words = %d \n", wordi);
    int i;
    for (i = 0; i < wordi; i++) {
        printf("%s \t (line #%d) \n", words[i], wordLineNums[i]);
    }
}

void printKeywords() {
    int i;
    for (i = 0; i < keyi; i++) {
        printf("%s \t (line #%d) \n", keys[i], keyLineNums[i]);
    }
}

void printNumbers() {
    int i;
    for (i = 0; i < numi; i++) {
        printf("%s \t (line #%d) \n", nums[i], numLineNums[i]);
    }
}

void printIdentifiers() {
    int i;
    for (i = 0; i < ideni; i++) {
        printf("%s \t (line #%d) \n", idens[i], idenLineNums[i]);
    }
}

void identifyWords() {
    int i;
    for (i = 0; i < wordi; i++) {
        if (isKeyword(words[i])) {
            strcpy(keys[keyi], words[i]);
            keyLineNums[keyi] =  wordLineNums[i];
            keyi++;
        } else {
            strcpy(idens[ideni], words[i]);
            idenLineNums[ideni] = wordLineNums[i];
            ideni++;
            
        }
    }
}

void printToken(cWd_Token *aToken) {
    char *aTokenTypeStrings[] = {"Identifier", "Keyword", "Number", "Relation Operator", 
        "Other Operator", "Delimiter"};
    
    int index = aToken->aTokenType;
    if (index < 0 || index > 5)
        return;
    //char *aTokenTypeStr = (char *) 
    //malloc(1 + sizeof(char) * strlen(aTokenTypeStrings[index]));
    
    //printf("index = %d \n", index);
    //printf("size: %d \n", strlen(aTokenTypeStrings[index]));	
    
    printf("cWd_Token type: %s |  Instance: %s | Line: %d \n", 
           aTokenTypeStrings[index], aToken->instance, aToken->lineNum);
    
}

// Besides English letters, and digits, these are extra acceptable characters
int isAcceptableChar(char c) {
    if (c == '.' || c == '(' || c == ')' || c == ',' || c =='{' || c == '}' ||
        c == ';' || c == '[' || c == ']' || 
        c == ':' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || 
        c == '=' || c == '<' || c == '>' || c == '!' 
        /* || c == '#' */ ) {
        
        return 1;
    } else 
        return 0;
}
