#pragma once

#include <string>
#include <vector>

namespace lexer {
    enum class TOKEN{
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        E,
        OPEN,
        CLOSE,
        X,
        Y,
        Z,
        ADD,
        SUB,
        MULT,
        DIV,
        LOG,
        SIN,
        COS,
        TAN,
        ARCSIN,
        ARCCOS,
        ARCTAN,
        POW,
        ABS,
        DECIMAL,
        COUNT
    };
    
    /// @brief returns the next symbol, modifying expression
    /// @return 
    TOKEN try_next_token(std::string_view& expression);

    std::vector<TOKEN> regex(std::string expresssion);
}