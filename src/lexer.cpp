#include <lexer.h>
#include <utility>
#include <stdexcept>
#include <ranges>

namespace lexer{
    const std::vector<std::pair<std::string, TOKEN>> SYMBOL_TABLE = []() -> auto {
        using enum TOKEN;
        return std::vector<std::pair<std::string, TOKEN>>{
            {"0", ZERO},
            {"1", ONE},
            {"2", TWO},
            {"3", THREE},
            {"4", FOUR},
            {"5", FIVE},
            {"6", SIX},
            {"7", SEVEN},
            {"8", EIGHT},
            {"9", NINE},
            {"e", E},
            {"(", OPEN},
            {")", CLOSE},
            {"x", X},
            {"y", Y},
            {"z", Z},
            {"+", ADD},
            {"-", SUB},
            {"*", MULT},
            {"/", DIV},
            {"log", LOG},
            {"sin", SIN},
            {"cos", COS},
            {"tan", TAN},
            {"arcsin", ARCSIN},
            {"arccos", ARCCOS},
            {"arctan", ARCTAN},
            {"^", POW},
            {"|", ABS}, 
            {".", DECIMAL}
        };
    }();

    auto keylen = [](std::pair<std::string, TOKEN> pair) -> size_t {
        return pair.first.length();
    };

    const size_t REGEX_MAX_LENGTH = [](const std::vector<std::pair<std::string, TOKEN>>& SYMBOL_TABLE) -> int {
        auto lens = SYMBOL_TABLE | std::views::transform(keylen);
        return std::ranges::max(lens);
    }(SYMBOL_TABLE);

    TOKEN try_next_token(std::string_view& expression){
        std::string_view prefix = expression.substr(0, std::max(REGEX_MAX_LENGTH, expression.length()));
        for (const auto& p : SYMBOL_TABLE){
            std::string_view len_matched_prefix = prefix.substr(0, p.first.length());
            if (len_matched_prefix.compare(p.first) == 0) {
                expression.remove_prefix(p.first.length());
                return p.second;
            }
        }
        throw std::runtime_error("Invalid Symbol");
    }

    std::vector<TOKEN> regex(std::string expression){
        std::string_view view = std::string_view(expression);
        std::vector<TOKEN> output = std::vector<TOKEN>();
        while (view.length() > 0){
            while (view.at(0) == ' ') view.remove_prefix(1);
            try{
                output.push_back(try_next_token(view));
            }
            catch (std::runtime_error e){
                return std::vector<TOKEN>();
            }
        }
        return output;
    }
}