#pragma once

class IFunction{
public:
    float tryEvaluate() const;
    virtual float evaluate() const = 0;
};

class Constant: IFunction{
public:
    float evaluate() const override;
};

class X: IFunction{
public:
    float evaluate() const override;
};

class Y: IFunction{
public:
    float evaluate() const override;
};

class Z: IFunction{
public:
    float evaluate() const override;
};

class Addition: IFunction{
public:
    float evaluate() const override;
};

class Multiplication: IFunction{
public:
    float evaluate() const override;
};

class Subtraction: IFunction{
public:
    float evaluate() const override;
};

class Division: IFunction{
public:
    float evaluate() const override;
};

