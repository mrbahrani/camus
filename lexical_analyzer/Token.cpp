//
// Created by abahrani on 2022-02-22.
//

#include "Token.h"

Token::Token(char *text, Token::TokenType type) {
    this->text = text;
    this->type = type;
}

Token::~Token() {
    delete this->text;
}
