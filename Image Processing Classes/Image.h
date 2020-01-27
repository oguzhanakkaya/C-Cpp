#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include "matrix.h"

using namespace std ;

template<typename T>
class Image: public Matrix<T>{

    public:
    Image();





    protected:
    int rows,columns,val,nrow,ncolumn;
    int **matrix,**trans;



};










#endif // IMAGE_H_INCLUDED
