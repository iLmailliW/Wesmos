#pragma once

#include <string>
#include <unordered_map>

namespace lexer {
    enum class TOKEN{
        OPEN,
        CLOSE,
        X,
        Y,
        Z,
        ADD,
        SUB,
        MULT,
        DIV,
        EXP,
        LOG,
        SIN,
        COS,
        TAN,
        ARCSIN,
        ARCCOS,
        ARCTAN,
        POW,
        ABS,
        COUNT,
        NONE
    };

    std::unordered_map<std::string, TOKEN> symbol_table = []() -> auto {
        using enum TOKEN;
        return std::unordered_map<std::string, TOKEN>();
    }();

    /// @brief returns the next symbol
    /// @return 
    TOKEN regex(std::string expression);

    
}