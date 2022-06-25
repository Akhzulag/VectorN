//
// Created by Ростислав Буржимський on 24/6/2022.
//

#include "Vector.h"
#include <iostream>

Vector::Vector(int dimension)
{
    this->dimension = dimension;

    this->vector = allocate(dimension);

}



Vector::Vector(int* begin, int* end)
{
    this->dimension = (end-begin);
    this->vector = allocate(this->dimension);

    for(int i = 0; (begin+i) != end ; ++i)
        this->vector[i] = begin[i];

}

bool Vector::operator == (const Vector & right) const
{
    if (this == &right)
        return true;

    if(this->dimension != right.dimension)
        return false;

    for(int i = 0; i < dimension; ++i)
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
    if(this->dimension != Vector.dimension)
        throw "dimension for dot product must be equal";

    int result = 0;

    for(int i = 0; i < this->dimension; ++i)
        result += this->vector[i] * Vector[i];

    return result;
}

Vector Vector::addition(const Vector&  vector) const
{
    if(this->dimension != vector.dimension)
        throw "dimension for dot product must be equal";

    Vector *tmp = new Vector(this->dimension);

    for(int i = 0; i < this->dimension; ++i)
        tmp->vector[i] = this->vector[i] + vector.vector[i];


    return *tmp;
}

Vector Vector::subtraction(const Vector&  vector) const
{
    if(this->dimension != vector.dimension)
        throw "dimension for dot product must be equal";

    Vector *tmp = new Vector(this->dimension);

    for(int i = 0; i < this->dimension; ++i)
        tmp->vector[i] = this->vector[i] - vector.vector[i];

    return *tmp;
}

int Vector::getDimention() const
{
    return this->dimension;
}

int* Vector::allocate(int dim)
{
    int *tmp = new int[dim];
    for(int i=0; i < dim; ++i)
        tmp[i]=0;

    return tmp;
}