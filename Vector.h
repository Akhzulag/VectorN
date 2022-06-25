//
// Created by Ростислав Буржимський on 24/6/2022.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


class Vector
{
private:
    int *vector;
    int dimension;
public:
    int getDimention() const;
    int operator [] (const int& ) const;
    bool operator == (const Vector& ) const;


    Vector(int );
    Vector(int* ,int* );
    ~Vector();


    Vector addition(const Vector&  ) const;
    Vector subtraction(const Vector&  ) const;
    int dotProduct(const Vector&  ) const;

    int* allocate(int );
};

#endif //VECTOR_VECTOR_H
