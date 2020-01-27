#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <math.h>



using namespace std ;

template<typename T>
class Matrix
{
    public:

    Matrix(int rowSize,int columnSize,char value);
    Matrix();
    Matrix(int rowSize,int columnSize,T value);
    void resizee(T n_rows,T n_columns);
    void printf()const;
    void printf(const char* output_file)const;

    Matrix<T> operator+(const Matrix& object);
    Matrix<T> operator-(const Matrix& object);
    Matrix<T> operator*(const Matrix& object);


    Matrix<T> operator+( int eklenecek_sayi);
    Matrix<T> operator-( int cikarilacak_sayi);
    Matrix<T> operator*( int carpilacak_sayi);
    Matrix<T> operator%( int mod_sayi);
    Matrix<T> operator^( int us_sayi);
    Matrix<T>operator/(int bolum_sayi);

    void Transpoze();
    Matrix<T> emul(Matrix<T> &object);
    int det();
  //  void inv();



    protected:
      int rows,columns,val,nrow,ncolumn;
      T **matrix,**trans;
      string output;

};


template<typename T>
Matrix<T>::Matrix(int rowSize,int columnSize,char value){
    if(value=='e')// create a unit matrix
    {
    rows = rowSize;
    columns = columnSize;

        if(rows==columns)
        {
            matrix = new int *[rows];
            for(int i = 0; i < rows; i++)
            matrix[i]=new int[columns];

            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    if(i==j){
                        matrix[i][j]=1;
                    }
                    else{
                matrix[i][j]=0;
                    }
                }
            }
        }
        else
        {
            cout<<"Bir matrisin birim matris olmasý için satir ve sutun sayisi esit olmalidir"<< endl;
        }

    }
    else if(value=='r')
    {
        srand(time(0));
        val = rand() % 255 + 0;
        rows = rowSize;
        columns = columnSize;
        matrix = new int *[rows];
        for(int i = 0; i < rows; i++)
            matrix[i]=new int[columns];

        for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]=val = rand() % 255 + 0;
        }}}


    else
    cout<< "Hatali deger girdiniz"<<endl;


    }

template<typename T>
Matrix<T>::Matrix(int rowSize,int columnSize,T value){
      rows = rowSize;
    columns = columnSize;

    matrix = new T *[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new T [columns];
         for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]=value;
        }}

}
template<typename T>
Matrix<T>::Matrix(){
    rows = 10;
    columns = 10;

    matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[columns];
         for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]=0;
        }}

}
/*template<typename T>
void Matrix<T>::resizee(T n_rows,T n_columns){
    nrow=n_rows;
    ncolumn=n_columns;

    Matrix<T> temp;


    this->rows = nrow;
    this->columns=ncolumn;

    temp = new int *[rows];
    for(int i = 0; i < nrow; i++)
        temp[i]=new int[nrow];

    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncolumn;j++){
            temp[i][j]=0;
        }
    }

    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncolumn;j++){
            temp[i][j]=val;
        }
    }
    return temp;

}*/

template<typename T>
void Matrix<T>::printf()const{
     for(int x=0;x<rows;x++)
    {
        for(int y=0;y<columns;y++)
        {

            cout<<matrix[x][y]<<" ";
            }
            cout<< endl;

    }



}
template<typename T>
void Matrix<T>::printf(const char* output_file)const{


   ofstream file;
   file.open(output_file,ios::out);

   for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
           file<<matrix[i][j];
        }
        file<< endl;
       }


}
template<typename T>
Matrix<T> Matrix<T>::operator+ ( const Matrix &object)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;
    temp.val=1;

    if(this->rows == object.rows && this->columns == object.columns )
    {
          for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]+object.matrix[i][j];
        }
    }
        return temp;
    }

    else
        cout << "Iki Matrisin satir ve sutun sayisi esit degil,iki matrisi toplarken satir ve sutun sayisi esit olmali."<<endl;
    }
template<typename T>
Matrix<T> Matrix<T>::operator- ( const Matrix &object)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;
    temp.val=1;

    if(this->rows == object.rows && this->columns == object.columns )
    {
          for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]-object.matrix[i][j];
        }
    }
        return temp;
    }

    else
        cout << "Iki Matrisin satir ve sutun sayisi esit degil,iki matrisi toplarken satir ve sutun sayisi esit olmali."<<endl;
    }

template<typename T>
Matrix<T> Matrix<T>::operator* ( const Matrix &object)
{
    if(this->columns == object.columns || this->rows ==object.rows)
   {
    Matrix<T> temp;
     temp.rows=this->rows;
        temp.columns=this->columns;

        for (int i = 0; i < this->rows; i++){
          for (int j = 0; j < object.columns; j++){
                temp.matrix[i][j] = this->matrix[i][j] * object.matrix[i][j];
            }
        }
        return temp;
   }
   else
        cout<<"Eleman duzeyinde carpim icin iki matrisin satir ve sutun sayilari esit olmalidir"<< endl;


   }
template<typename T>
Matrix<T> Matrix<T>::operator+(int eklenecek_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]+ eklenecek_sayi;

        }
    }
 return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(int cikarilacak_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]- cikarilacak_sayi;

        }
    }
 return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(int carpilacak_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]*carpilacak_sayi;

        }
    }
 return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator%(int mod_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[i][j] = this->matrix[i][j]%mod_sayi;

        }
    }
 return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator^(int us_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
                for(int k=0;k<(us_sayi-1);k++)
                {
                     temp.matrix[i][j] = this->matrix[i][j]*this->matrix[i][j];

        }
    }
 return temp;
}
}
template<typename T>
Matrix<T> Matrix<T>::operator/(int bolum_sayi)
{
    Matrix<T> temp;
    temp.rows = this->rows;
    temp.columns = this->columns;

     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
                     temp.matrix[i][j] = this->matrix[i][j]/bolum_sayi;

        }
    }
 return temp;
}

template<typename T>
void Matrix<T>::Transpoze()
{
    Matrix<T> temp;
    temp.columns=this->rows;
    temp.rows=this->columns;

        for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
           temp.matrix[j][i] = this->matrix[i][j];

        }
    }
    return temp;

}

template<typename T>
Matrix<T> Matrix<T>::emul(Matrix <T> &object)
{


if(this->columns == object.rows)
    {
        Matrix <T> temp;
        temp.rows=this->rows;
        temp.columns=object.columns;

        for (int i = 0; i < this->rows; i++){
          for (int j = 0; j < object.columns; j++){
            for(int k = 0; k < this->columns; k++)
            {
                temp.matrix[i][j] += this->matrix[i][k] * object.matrix[k][j];;
            }
          }
        }
        return temp;
    }

    else
        cout << "Iki Matris carparken ilk matrisin sutunu ve ikinci matrisin satiri esit olmali "<<endl;



}
template<typename T>
int Matrix<T>::det()
{

}






#endif // CLASSES_H_INCLUDED
