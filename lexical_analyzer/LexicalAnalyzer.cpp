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

bool LexicalAnalyzer::isInitialized() const {
    return initialized;
}

Token *LexicalAnalyzer::getTheNextToken() {
    //ToDo add token size checker
    char *tokenText = new char[MAX_TOKEN_LENGTH];
    char *iter = tokenText;
    bool tokenFound = false;
    Token::TokenType type = Token::unknown;
    while (!tokenFound)
    {
        *iter = (char)fgetc(script_file);
        switch (*iter) {
            case '(':
                tokenFound = true;
                return new Token(tokenText, Token::parenthesis_open);
            case ')':
                tokenFound = true;
                return new Token(tokenText, Token::parenthesis_close);
                break;
            case EOF:
                *iter = '\0';
                type = getTokenTypeByText(tokenText);
                return new Token(tokenText, type);
            case ' ':
            case '\t':
            case '\n':
                while (isWhitespace(*iter)) {
                    fgetc(script_file);
                }
                if (*iter != EOF)
                {
                    fseek(script_file, -1, SEEK_CUR);
                }
                *iter = '\0';
                type = getTokenTypeByText(tokenText);
                return new Token(tokenText, type);
            default:
                tokenFound = true;
                break;
        }
        iter++;
    }
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
    return Token::unknown;
}

bool LexicalAnalyzer::isWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n';
}
