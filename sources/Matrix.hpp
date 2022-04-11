#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace zich{
    class Matrix{

        private:
            int _row;
            int _col;
            std::vector<double> _v;
            void setRow(int r){this->_row=r;}
            void setCol(int c){this->_col=c;}
            void setV(vector<double>& v){this->_v=v;}
        
        public:

            //constructor
            Matrix(const vector<double> &v,int r, int c);
            Matrix(const Matrix& other);
            ~Matrix(){
              
            }

            int getRow() const {return this->_row;}
            int getCol() const {return this->_col;}
            vector<double> getV() const {return this->_v;}

            // void setRow(int r){this->_row=r;}
            // void setCol(int c){this->_col=c;}
            // void setV(vector<double>& v){this->_v=v;}
            
            // void setMatrix(vector<double> & v,int r, int c); 
            
           
            // addition
            
            Matrix operator+(const Matrix & m )const;
            Matrix operator+() const;
            Matrix operator+=(const Matrix & m);
           


            // subtraction
            Matrix operator-(const Matrix & m)const;
            Matrix operator-()const;
            Matrix operator-=(const Matrix & m );
            // Matrix Matrix::operator-=(int n);
        


            // increment decrement
            //prefix
            Matrix operator++(); 
            Matrix operator--(); 
            //postfix
            Matrix operator++(int i);
            Matrix operator--(int i);

        
            // multiplacation
            Matrix operator*(double d) const;
            friend Matrix operator*(double d, Matrix & m); 
            //friend &Matrix operator*(double d, Matrix & m); 
            Matrix operator*(const Matrix & m) const;
            Matrix operator*=(const Matrix & m) ;
            Matrix operator*=(double d);
            

            // comparing
            bool operator==(const Matrix & m ) const;
            bool operator<(const Matrix & m)const;
            bool operator<=(const Matrix & m)const;
            bool operator>(const Matrix & m)const;
            bool operator>=(const Matrix & m)const;
            bool operator!=(const Matrix & m)const;


            //print
            friend ostream& operator<<(ostream& output, const Matrix& m); // not in cpp
            friend istream& operator>>(istream& input,  Matrix& m); // not in cpp

    };
}
