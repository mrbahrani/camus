//
// Created by abahrani on 2022-02-22.
//

#ifndef CAMUS_TOKEN_H
#define CAMUS_TOKEN_H

#define MAX_TOKEN_LENGTH 64

class Token {
public:
    enum TokenType
    {
        object,
        predicate,
        period,
        question_mark,
        parenthesis_open,
        parenthesis_close,
        if_token,
        else_token,
        and_token,
        not_token,
        or_token,
        comment,
        unknown
    };
private:

    char* text;
    TokenType type;
public:
    Token(char* text, TokenType type);
    ~Token();
};


#endif //CAMUS_TOKEN_H
