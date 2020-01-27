#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <math.h>


using namespace std;

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
    void emul(Matrix<T> &object);
    T det(const Matrix<T>& matrixx,int n);
    T inv();



    protected:
      int rows,columns,val,nrow,ncolumn;
      T **matrix,**trans,vav;
      char va;

      string output;

};
template<typename T>
class Table: public Matrix<T>{

    public:
    Table();
    Table(int r,int c,int d);
    Table(int r,int c,char ch);

    int itemAt(int r,int c);
    int itemAt(string s);
    int itemAt(string rs,string cs);
    void printfl();
    void setRowNames(string s[],int n);
    void setColNames(string s[],int n);

    protected:
    int rows,columns,val,nrow,ncolumn;
    int **matrix,**trans;
    string satir_ismi[30]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"};
    string sutun_ismi[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
};
template<typename T>
Matrix<T>::Matrix(int rowSize,int columnSize,char value){
    if(value=='e')// create a unit matrix
    {
    rows = rowSize;
    columns = columnSize;
    va=value;
        if(rows==columns)
        {
            matrix = new T *[rows];
            for(int i = 0; i < rows; i++)
            matrix[i]=new T[columns];

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
        va=value;
        srand(time(0));
        val = rand() % 255 + 0;
        rows = rowSize;
        columns = columnSize;
        matrix = new T *[rows];
        for(int i = 0; i < rows; i++)
            matrix[i]=new T[columns];

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
    vav=value;

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

    matrix = new T *[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new T[columns];
         for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]=0;
        }}

}
template<typename T>
void Matrix<T>::resizee(T n_rows,T n_columns){
    nrow=n_rows;
    ncolumn=n_columns;

    Matrix<T> temp;
    temp.columns=this->columns;
    temp.rows=this->rows;


        for(int i=0;i<this->rows;i++){
            for(int j=0;j<this->columns;j++)
            {
                   temp.matrix[i][j]=this->matrix[i][j];
            }
        }

    int a=this->rows;
    int b=this->columns;

    this->rows = nrow;
    this->columns=ncolumn;

     matrix = new T *[this->rows];
    for(int i = 0; i < this->rows; i++)
        matrix[i] = new T[this->columns];

    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            if(i>=a || j>=b )
            {
              if(this->va=='e')
              {
                   if(i==j){
                        matrix[i][j]=1;
                    }
                    else{
                        matrix[i][j]=0;
                    }
              }
              else if(this->va=='r')
              {
                  matrix[i][j]=val = rand() % 255 + 0;

              }
              else
                matrix[i][j]=vav;
            }

            else
            {
                matrix[i][j]=temp.matrix[i][j];
            }

        }
    }
}
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
       cout<<"Dosyaya basariyla yazdirildi"<< endl;


}
template<typename T>
Matrix<T> Matrix<T>::operator+ ( const Matrix &object){
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
    {
         cout << "Iki Matrisin satir ve sutun sayisi esit degil,iki matrisi toplarken satir ve sutun sayisi esit olmali."<<endl;
        exit(0);
    }

    }
template<typename T>
Matrix<T> Matrix<T>::operator- ( const Matrix &object){
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
    {
        cout << "Iki Matrisin satir ve sutun sayisi esit degil,iki matrisi toplarken satir ve sutun sayisi esit olmali."<<endl;
         exit(0);
    }

    }
template<typename T>
Matrix<T> Matrix<T>::operator* ( const Matrix &object){
    if(this->columns == object.columns || this->rows ==object.rows)
   {
    Matrix<T> temp(this->rows,this->columns,0.);

        for (int i = 0; i < this->rows; i++){
          for (int j = 0; j < this->columns; j++){
                temp.matrix[i][j] = this->matrix[i][j] * object.matrix[i][j];
            }
        }
        return temp;
   }
   else
   {
        cout<<"Eleman duzeyinde carpim icin iki matrisin satir ve sutun sayilari esit olmalidir"<< endl;
         exit(0);
   }



   }
template<typename T>
Matrix<T> Matrix<T>::operator+(int eklenecek_sayi){
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
Matrix<T> Matrix<T>::operator-(int cikarilacak_sayi){
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
Matrix<T> Matrix<T>::operator*(int carpilacak_sayi){
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
Matrix<T> Matrix<T>::operator%(int mod_sayi){
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
Matrix<T> Matrix<T>::operator^(int us_sayi){
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
    }
return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator/(int bolum_sayi){
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
void Matrix<T>::Transpoze(){


        Matrix <T> temp;
        temp.rows=this->columns;
        temp.columns=this->rows;

        for (int i = 0; i < this->columns; i++){
            for (int j = 0; j < this->rows; j++){
           temp.matrix[i][j] = this->matrix[j][i];
            }
        }

        resizee(temp.rows,temp.columns);


        for (int i = 0; i < temp.rows; i++){
            for (int j = 0; j < temp.columns; j++){
            this->matrix[i][j]=temp.matrix[i][j];
            }
        }
}
template<typename T>
T Matrix<T>::inv(){
    Matrix<T> temp(this->rows,this->columns,'e');
    float d,k;
    for(int i=0;i<this->rows;i++){
        d=this->matrix[i][i];
        for(int j=0;j<this->columns;j++){
            this->matrix[i][j]=this->matrix[i][j]/d;
            temp.matrix[i][j]=temp.matrix[i][j]/d;
        }
        for(int x=0;x<this->rows;x++){
            if(x!=i){
                k=this->matrix[x][i];
                for(int j=0;j<this->columns;j++){
                    this->matrix[x][j]=this->matrix[x][j]-(this->matrix[i][j]*k);
                    temp.matrix[x][j]=temp.matrix[x][j]-(temp.matrix[i][j]*k);
                }
            }
        }

    }
       for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->columns; j++){
           this->matrix[i][j] = temp.matrix[i][j];

        }
    }
}
template<typename T>
void Matrix<T>::emul(Matrix <T> &object){

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
        this->columns=object.columns;
        matrix = new  T *[this->rows];
            for(int i = 0; i < this->rows; i++)
            matrix[i]=new T[this->columns];

         for (int i = 0; i < this->rows; i++){
          for (int j = 0; j < this->columns; j++){
                this->matrix[i][j]=temp.matrix[i][j];

    }
         }
}
    else
        cout << "Iki Matris carparken ilk matrisin sutunu ve ikinci matrisin satiri esit olmali "<<endl;
}
template<typename T>
T Matrix<T>::det(const Matrix<T>& matrixx,int n){


     if(matrixx.rows==matrixx.columns){
        T determinant=0;
        Matrix<T> temp;
        if(n==1)
        {
            return matrix [0][0];
        }

        else if (n == 2){
          return (matrixx.matrix[0][0] * matrixx.matrix[1][1]) - (matrixx.matrix[1][0] * matrixx.matrix[0][1]);
        }
        else{
              for (int x = 0; x < n; x++) {
                int subi = 0;
                for (int i = 1; i < n; i++) {
                   int subj = 0;
                   for (int j = 0; j < n; j++) {
                      if (j == x)
                      continue;
                      temp.matrix[subi][subj] = matrixx.matrix[i][j];
                      subj++;
                   }
                   subi++;
                }
                determinant = determinant + (pow(-1, x) * matrixx.matrix[0][x] * det( temp, n - 1 ));
          }
            return determinant;
        }
    }
    else{
        cout<<"Bir matrisinin determinantinin hesaplanmasi icin kare matris olmasi gerekir"<<endl;
        return 0;
    }
}
template<typename T>
Table<T>::Table():Matrix<T>(){

    rows = 10;
    columns = 10;

    matrix = new int *[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[columns];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
            matrix[i][j]=0;
            }
        }

}
template<typename T>
Table<T>::Table(int r,int c,int d){

    rows=r;
    columns=c;
      matrix = new int *[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[columns];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
            matrix[i][j]=d;
            }
        }

}
template<typename T>
Table<T>::Table(int r,int c,char ch){

    rows=r;
    columns=c;
    if(ch=='r')
    {
        srand(time(0));
        matrix = new int *[rows];
        for(int i = 0; i < rows; i++)
            matrix[i]=new int[columns];

        for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]= rand() % 255 + 0;
        }
        }
    }
    else
        cout<<"Hatali giris yaptiniz"<<endl;
}
template<typename T>
int Table<T>::itemAt(string s){

string a=string(1,s[0]);
string b=string(1,s[1]);

int satirr,sutunn;
    for(int  i=0;i<this->rows;i++)
    {
            if(b==satir_ismi[i])
            {
               // sutunn=i;
               satirr=i;
            }

    }
    for(int j=0;j<this->columns;j++)
    {
            if(a==sutun_ismi[j])
            {
               // satirr=j;
               sutunn=j;
            }
    }


    return matrix[satirr][sutunn];
}
template<typename T>
int Table<T>::itemAt(string rs,string cs){

int satirr,sutunn;

    for(int  i=0;i<this->columns;i++)
    {

            if(cs==sutun_ismi[i])
            {
                sutunn=i;
            }
    }
    for(int j=0;j<this->rows;j++) {
            if(rs==satir_ismi[j])
            {
                satirr=j;
            }

    }

    return this->matrix[satirr][sutunn];
}
template<typename T>
int Table<T>::itemAt(int r,int c){

    return this->matrix[r][c];
}
template<typename T>
void Table<T>::printfl(){


    cout<< "  ";
    for(int i=0;i<this->columns;i++)
        cout << sutun_ismi[i]<<" ";

    cout << endl;

     for(int x=0;x<this->rows;x++)
    {
       cout << satir_ismi[x]<< " ";
        for(int y=0;y<this->columns;y++)
        {

            cout<<matrix[x][y]<<" ";
            }
            cout<< endl;

    }


}
template<typename T>
void Table<T>::setRowNames(string s[],int n){

    for(int i=0;i<n;i++)
    {
        if(s[i].size()<8)
        {
           satir_ismi[i]=s[i];
        }
        else{
            cout<<"Satir sayisi boyutu 8 den fazla olamaz"<<endl;
            exit(0);

        }

    }


}
template<typename T>
void Table<T>::setColNames(string s[],int n){

    for(int i=0;i<n;i++)
    {
        if(s[i].size()<4)
        {
            sutun_ismi[i]=s[i];
        }
        else{
            cout<<"Sutun sayisi boyutu 4 den fazla olamaz"<<endl;
            exit(0);

        }
       ;
    }


}


int main()
{
   int sec=1;
  switch(sec){
    case 1 :
   // STL vector kullanan buradan puan alamaz
      Matrix<double> m3(5,4,1.);
      m3.printf();
      // aÅŸaÄŸÄ±daki durumlarÄ± ayrÄ± ayrÄ± dene
      //m3.resize(2,6);
      //m3.resize(10,6);
      m3.resizee(10,3);

      m3.printf();

      break;





  }
    return 0;
}
