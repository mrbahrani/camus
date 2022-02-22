//
// Created by abahrani on 2022-02-22.
//

#include "LexicalAnalyzer.h"

LexicalAnalyzer *LexicalAnalyzer::getInstance() {
    if (instance == nullptr)
    {
        instance = new LexicalAnalyzer();
    }
    return instance;
}

void LexicalAnalyzer::initialize(std::string script_file_name) {
    if (! initialized)
    {
        script_file = fopen(script_file_name.c_str(), "r");
        initialized = true;
    }
    else
    {
        //ToDo create the exception class
        throw "Instance has already been initialized";
    }
}

bool LexicalAnalyzer::isInitialized() {
    return initialized;
}

Token *LexicalAnalyzer::getTheNextToken() {
    //ToDo add token size checker
    char *tokenText = new char[MAX_TOKEN_LENGTH];
    char *iter = tokenText;
    do
    {
        *iter++ = (char)fgetc(script_file);

        //ToDo replace while condition with a function
    } while(*iter != EOF);
    *iter = '\0';
    Token::TokenType type = getTokenTypeByText(tokenText);
    return new Token(tokenText, type);
}

LexicalAnalyzer::LexicalAnalyzer() {
    //ToDo: complete constructor

}

LexicalAnalyzer::~LexicalAnalyzer() {
    //ToDo complete destructor
}

Token::TokenType LexicalAnalyzer::getTokenTypeByText(const char* tokenText)
{

}