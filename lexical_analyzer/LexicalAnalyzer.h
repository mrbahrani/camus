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
    enum LexicalFiniteMachineStates
    {
        start_state,
        parenthesis_open_seen,
        parenthesis_close_seen,
        erroneous_character_seen,
        comment_mode,
        variable_potential,
        object_or_keyword
    };

    static LexicalAnalyzer* getInstance();
    void initialize(std::string script_file_name);
    bool isInitialized() const;
    Token* getTheNextToken();

private:
    static LexicalAnalyzer* instance;
    bool initialized;
    FILE* script_file;
    LexicalAnalyzer();
    ~LexicalAnalyzer();
    Token::TokenType getTokenTypeByText(const char* tokenText);

    bool isWhitespace(char i);
};


#endif //CAMUS_LEXICALANALYZER_H
