//
// Created by Ростислав Буржимський on 24/6/2022.
//

#include "Vector.h"
#include <iostream>

Vector::Vector(int dimention)
{
    this->dimention = dimention;

    this->vector = allocate(dimention);

}



Vector::Vector(int* begin, int* end)
{
    this->dimention = (end-begin);
    this->vector = allocate(this->dimention);

    for(int i = 0; (begin+i) != end ; ++i)
        this->vector[i] = begin[i];

}

bool Vector::operator == (const Vector & right) const
{
    if (this == &right)
        return true;

    if(this->dimention != right.dimention)
        return false;

    for(int i = 0; i < dimention; ++i)
        if(this->vector[i] != right.vector[i])
            return false;

    return true;
}


Vector::~Vector()
{
    delete[] vector;
}


int Vector::operator [] (const int& index) const
{
    return this->vector[index];
}


int Vector::dotProduct(const Vector& Vector) const
{
    if(this->dimention != Vector.dimention)
        throw "Dimention for dot product must be equal";

    int result = 0;

    for(int i = 0; i < this->dimention; ++i)
        result += this->vector[i] * Vector[i];

    return result;
}

Vector Vector::addition(const Vector&  vector) const
{
    if(this->dimention != vector.dimention)
        throw "Dimention for dot product must be equal";

    Vector *tmp = new Vector(this->dimention);

    for(int i = 0; i < this->dimention; ++i)
        tmp->vector[i] = this->vector[i] + vector.vector[i];


    return *tmp;
}

Vector Vector::subtraction(const Vector&  vector) const
{
    if(this->dimention != vector.dimention)
        throw "Dimention for dot product must be equal";

    Vector *tmp = new Vector(this->dimention);

    for(int i = 0; i < this->dimention; ++i)
        tmp->vector[i] = this->vector[i] - vector.vector[i];

    return *tmp;
}

int Vector::getDimention() const
{
    return this->dimention;
}

int* Vector::allocate(int dim)
{
    int *tmp = new int[dim];
    for(int i=0; i < dim; ++i)
        tmp[i]=0;

    return tmp;
}