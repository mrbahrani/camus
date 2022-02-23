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
        erroneous_character_seen,
        comment_mode,
        variable_potential,
        object_or_keyword,
        final_state
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

    bool isUpper(char ch);

    bool isLower(char ch);
};


#endif //CAMUS_LEXICALANALYZER_H
