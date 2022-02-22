//
// Created by abahrani on 2022-02-22.
//

#ifndef CAMUS_LEXICALANALYZER_H
#define CAMUS_LEXICALANALYZER_H


#include <iosfwd>
#include <fstream>
#include "Token.h"

class LexicalAnalyzer {
public:
    static LexicalAnalyzer* getInstance();
    void initialize(std::string script_file_name);
    bool isInitialized();
    Token* getTheNextToken();

private:
    static LexicalAnalyzer* instance;
    bool initialized;
    FILE* script_file;
    LexicalAnalyzer();
    ~LexicalAnalyzer();
    Token::TokenType getTokenTypeByText(const char* tokenText);

};


#endif //CAMUS_LEXICALANALYZER_H
