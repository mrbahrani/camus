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
    LexicalFiniteMachineStates state = start_state;
    Token::TokenType type = Token::unknown;
    while (state != final_state)
    {
        *iter = (char)fgetc(script_file);
        switch (state)
        {
            case start_state:
                if (*iter == '(')
                {
                    type = Token::parenthesis_open;
                    ++iter;
                    *iter='\0';
                    state = final_state;
                }
                else if (*iter == ')')
                {
                    type = Token::parenthesis_close;
                    ++iter;
                    *iter='\0';
                    state = final_state;
                }
                else if (*iter == '#')
                {
                    state = comment_mode;
                }
                else if (isUpper(*iter))
                {
                    state = variable_potential;
                }
                else if (isLower(*iter))
                {
                    state = object_or_keyword;
                }
                else
                {
                    state = erroneous_character_seen;
                }
                break;
            case erroneous_character_seen:
                break;
            case variable_potential:
                break;
            case object_or_keyword:
                break;
            case comment_mode:
                break;
            default:
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

bool LexicalAnalyzer::isUpper(char ch) {
    return ch > 64 && ch < 91;
}

bool LexicalAnalyzer::isLower(char ch) {
    return ch > 96 && ch < 123;
}
