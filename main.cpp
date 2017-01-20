int main(int argc, char *argv[]) {
    FILE *filePtr;

    switch (argc) {
        case 1: // No parameters, use stdin
                // printf("NO argument provided\n");
                filePtr = stdin;
                break;

        case 2: // One parameter, use .lan file supplied	
                if ( (filePtr = fopen(strcat(argv[1], ".lan"), "r")) == NULL ) {
                        printf("Cannot open input file.\n");
                        exit(1);
                }
                break;

        default:
                printf("Syntax: scanner [file] (.lan is implicit)\n");
                exit(0);
    }
}
/*---------Begin check if file empty-----------*/

	fseek(filePtr, 0, SEEK_END);
	if (ftell(filePtr) == 0) {
		printf("File is empty.\n");
		exit(1);
	} else {
		rewind(filePtr);
	}

	/*---------/End check if file empty-------------*/

	/*---------Begin check for invalid characters and max length-------------*/
	
	char c;
	int numLine = 1;

	int charCount = 0;
	char tempStr[MAX]; // ! Remember: C doesn't do array out-of-bound checking! 
	int i;

	int isValid = 1; // true 
	while ((c = fgetc(filePtr)) != EOF) {
		if (c == '\n')
			numLine++;

		// Exclude comment line starting with '//' and ending with new line
		if (c == '/') {
			if (fgetc(filePtr) == '/') {
				while ((c = fgetc(filePtr)) != '\n') {}
				numLine++;
			}			
		}

		if (isalnum(c)) {
			tempStr[charCount] = c; // array out-of-bound checking not happen here
			charCount++;
			if (charCount > MAX) {
				printf("Word '%s' on line number %d is too long. \n", tempStr, numLine);
				exit(1);	
			}
		} else if (isspace(c) || isAcceptableChar(c)) { 
			charCount = 0;
		} else {
			printf("Invalid character '%c' at line %d. \n", c, numLine);
			isValid = 0; // false
		}

	}

	if (isValid == 0) { 
		printf("Something wrong with the input file. \n");
		exit(1);
	}

	rewind(filePtr);
	
	/*---------/End check for invalid characters and max length-------------*/

	/*---------Begin Job-------------*/
	// At this time, the file is good. Now let scanner.c do the work
	cWd_TokenType aTokenType = UNDEF;
	
	// Token token; 
	// token.tokenType = tokenType;
	// token.instance = NULL;
	// token.lineNum = -1;
	// while ((token.tokenType = getTokenType(filePtr, &token)) != EOT) {}
	
	while ((aTokenType = getTokenType(filePtr)) != EOT) {}
	
	/*---------/End Job-------------*/

	fclose(filePtr);
    return 0;
}
