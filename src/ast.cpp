#include <ast.h>
#include <limits>
#include <cmath>

#ifndef AST_EPSILON
    #define AST_EPSILON 1e-5f
#endif

float ast::get_epsilon() {return AST_EPSILON;};

Constant::Constant(float v) : value(v) {}

float Constant::evaluate(float x, float y, float z) const {
    return this->value;
}

float X::evaluate(float x, float y, float z) const {
    return x;
}

float Y::evaluate(float x, float y, float z) const {
    return y;
}

float Z::evaluate(float x, float y, float z) const {
    return z;
}

Addition::Addition(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r)
    : left(std::move(l)), right(std::move(r)) {};

float Addition::evaluate(float x, float y, float z) const {
    return left->evaluate(x, y, z) + right->evaluate(x, y, z);
}

Multiplication::Multiplication(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r)
    : left(std::move(l)), right(std::move(r)) {};

float Multiplication::evaluate(float x, float y, float z) const {
    return left->evaluate(x, y, z) * right->evaluate(x, y, z);
}

Inversion::Inversion(std::unique_ptr<IFunction> e) : expr(std::move(e)) {}

float Inversion::evaluate(float x, float y, float z) const {
    return -expr->evaluate(x, y, z);
}

Division::Division(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r)
    : left(std::move(l)), right(std::move(r)) {};

float Division::evaluate(float x, float y, float z) const {
    float righteval = right->evaluate(x, y, z);
    if (std::abs(righteval) < ast::get_epsilon()) return std::numeric_limits<float>::quiet_NaN();
    return left->evaluate(x, y, z) / right->evaluate(x, y, z);
}

Logarithm::Logarithm(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Logarithm::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    if (eval < ast::get_epsilon()) return std::numeric_limits<float>::quiet_NaN();
    return std::log(eval);
}

Exponential::Exponential(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Exponential::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::exp(eval);
}

Sine::Sine(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Sine::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::sinf(eval);
}

Cosine::Cosine(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Cosine::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::cosf(eval);
}

Tangent::Tangent(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Tangent::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::tanf(eval);
}


Arcsine::Arcsine(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Arcsine::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    if (std::abs(eval) > 1) return std::numeric_limits<float>::quiet_NaN();
    return std::asinf(eval);
}

Arccosine::Arccosine(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Arccosine::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    if (std::abs(eval) > 1) return std::numeric_limits<float>::quiet_NaN();
    return std::acosf(eval);
}

Arctangent::Arctangent(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float Arctangent::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::atanf(eval);
}

AbsoluteValue::AbsoluteValue(std::unique_ptr<IFunction> e) : expr(std::move(e)) {};

float AbsoluteValue::evaluate(float x, float y, float z) const {
    float eval = expr->evaluate(x, y, z);
    return std::abs(eval);
}