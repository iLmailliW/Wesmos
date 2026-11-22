#pragma once
#include <memory>

namespace ast {
    float get_epsilon();
}

class IFunction {
public:
    virtual float evaluate(float x, float y, float z) const = 0;
    virtual ~IFunction() = default;
};

class Constant: IFunction {
    float value;
public:
    Constant(float v);
    float evaluate(float x, float y, float z) const override;
};

class X: IFunction {
public:
    float evaluate(float x, float y, float z) const override;
};

class Y: IFunction {
public:
    float evaluate(float x, float y, float z) const override;
};

class Z: IFunction {
public:
    float evaluate(float x, float y, float z) const override;
};

class Addition: IFunction {
    std::unique_ptr<IFunction> left;
    std::unique_ptr<IFunction> right;
public:
    Addition(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r);
    float evaluate(float x, float y, float z) const override;
};

class Multiplication: IFunction {
    std::unique_ptr<IFunction> left;
    std::unique_ptr<IFunction> right;
public:
    Multiplication(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r);
    float evaluate(float x, float y, float z) const override;
};

class Inversion: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Inversion(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Division: IFunction {
    std::unique_ptr<IFunction> left;
    std::unique_ptr<IFunction> right;
public:
    Division(std::unique_ptr<IFunction> l, std::unique_ptr<IFunction> r);
    float evaluate(float x, float y, float z) const override;
};

class Logarithm: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Logarithm(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Exponential: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Exponential(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Sine: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Sine(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Cosine: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Cosine(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Tangent: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Tangent(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Arcsine: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Arcsine(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Arccosine: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Arccosine(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class Arctangent: IFunction {
    std::unique_ptr<IFunction> expr;
public:
    Arctangent(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};

class AbsoluteValue : IFunction {
    std::unique_ptr<IFunction> expr;
public:
    AbsoluteValue(std::unique_ptr<IFunction> e);
    float evaluate(float x, float y, float z) const override;
};