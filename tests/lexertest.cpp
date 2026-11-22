#include <lexer.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

using namespace lexer;
using enum TOKEN;

TEST(LexerTest, TokenMatch){
    std::vector<std::pair<std::string, TOKEN>> answer_key = {
        {"0",ZERO},
        {"1.39",ONE},
        {"283",TWO},
        {"3.14159",THREE},
        {"402983",FOUR},
        {"5x",FIVE},
        {"6y",SIX},
        {"7^2",SEVEN},
        {"88",EIGHT},
        {"900",NINE},
        {"e^23",E},
        {"(-x)",OPEN},
        {")",CLOSE},
        {"x",X},
        {"yz",Y},
        {"z^3",Z},
        {"+19",ADD},
        {"-239",SUB},
        {"*8",MULT},
        {"/7",DIV},
        {"log(1)",LOG},
        {"sin(203)",SIN},
        {"cos(x^2)",COS},
        {"tan(2)",TAN},
        {"arcsin(0)",ARCSIN},
        {"arccos(cos(x))",ARCCOS},
        {"arctan(x^2)",ARCTAN},
        {"^29",POW},
        {"|x|",ABS},
        {".293",DECIMAL},
    };
    ASSERT_EQ(answer_key.size(), std::to_underlying(TOKEN::COUNT));
    for (int i = 0; i < std::to_underlying(TOKEN::COUNT); i++){
        ASSERT_EQ(std::to_underlying(answer_key[i].second), i);
    }
    for (int i = 0; i < answer_key.size(); i++){
        std::string_view cur_input = answer_key[i].first;
        EXPECT_EQ(std::to_underlying(try_next_token(cur_input)), std::to_underlying(answer_key[i].second));
    }
}

TEST(LexerTest, SyntaxError){
    std::string input = "i";
    std::string_view view = std::string_view(input);
    EXPECT_ANY_THROW(try_next_token(view));
}

TEST(LexerTest, FullLexer){
    std::string input = "100x + 39 * y + e^(z^2) - 293";
    std::vector<TOKEN> expected = {ONE, ZERO, ZERO, X, ADD, THREE, NINE, MULT, Y, ADD, E, POW, OPEN, Z, POW, TWO, CLOSE, SUB, TWO, NINE, THREE};
    EXPECT_EQ(expected, regex(input));
}