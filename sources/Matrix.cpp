    #include "Matrix.hpp"
    #include <iostream>
    #include <stdexcept>
    #include <string>
    #include <vector>
    #include <sstream>










    using namespace zich;

    //constructor
    Matrix::Matrix (const vector<double> &v, int r, int c){
        // checking if the values are valid
         if( r<1 || c<1){
            throw std::invalid_argument( "row or col invalid size" ); 
        }
        if(v.empty()){
           throw std::invalid_argument( "vector  is invalid" ); 
        }
        if(r*c!=v.size()){ 
            throw std::invalid_argument( "size of vector doesnt match row*col" ); 
        }

        this->_row=r;
        this->_col=c;
        this->_v=v;
    }

    //constructor
    Matrix::Matrix(const Matrix & other){
        //getting the values from the other matrix and putting them in the new matrix
        int r=other.getRow();
        int c =other.getCol();
        vector<double> old=other.getV();
        this->_col=c;
        this->_row=r;
        this->_v=old;
    }
    
   
    // addition and subtraction

    Matrix Matrix::operator+ ()const{
        // using the copy constructor to make a new Matrix

        // int r= this->getRow();
        // int c= this->getCol();
        // vector<double>new_v=this->getV();
        // Matrix new_mat{new_v, r,c};
        // return new_mat;
        // Matrix new_mat=Matrix(*this);
        // return new_mat;
        return Matrix(*this);
    }

    Matrix Matrix::operator+ (const Matrix & m )const{
        // make sure that im adding 2 same size matrices
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        // get the 2 vectors
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        // create a new vector the same size
        unsigned long s=this_v.size();
        vector<double> new_v;
        new_v.resize(s);
        // put in the new vector the sum of each position
        for (unsigned int j=0;j<s;j++){
            new_v.at(j)=this_v.at(j)+m_v.at(j);
        }
        int c=this->getCol();
        int r=this->getRow();
        Matrix change{new_v,r,c};
        return change;
    }

    Matrix Matrix::operator+= (const Matrix & m){
        // make sure that im adding 2 same size matrices
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        } 
        // get the other vector
        vector<double> m_v=m.getV();
        // add the other vector to this vector foe every position
        for (unsigned long i=0; i<m_v.size();i++){
            this->_v[i]+=m_v[i];
        } 
        return *this;
    }

    Matrix Matrix::operator- ()const {
        // using the copy constructor to make a new Matrix
        // multiplying by -1 to get the negative of the Matrix

        // int r= this->getRow();
        // int c= this->getCol();
        // vector<double>new_v=this->getV();
        // for (unsigned long i=0;i<new_v.size();i++){
        //     if(new_v[i]!=0){
        //         new_v[i]*=-1;
        //     }
        // }
        // Matrix new_mat{new_v, r,c};
        // return new_mat;
        Matrix new_mat=Matrix(*this);
        new_mat*=-1;
        return new_mat;
    }

    Matrix Matrix::operator- (const Matrix & m)const{
        // make sure that im subtracting 2 same size matrices
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        } 
        // get the 2 vectors
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        // create a new vector the same size
        unsigned long s=this_v.size();
        vector<double> new_v;
        new_v.resize(s);
        // put in the new vector the subtraction of this-m for each position
        for (unsigned int j=0;j<s;j++){
            new_v.at(j)=this_v.at(j)-m_v.at(j);
        }
        int c=this->getCol();
        int r=this->getRow();
        Matrix change{new_v,r,c};
        return change;  
    }

    Matrix Matrix::operator-= (const Matrix & m ){
        // make sure that im subtracting 2 same size matrices
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        // get the other vector 
        vector<double> m_v=m.getV();
        // add the other vector to this vector foe every position
        for (unsigned long i=0; i<m_v.size();i++){
            this->_v[i]-=m_v[i];
        } 
        return *this;
    }


    // increment and decrement

    Matrix Matrix:: operator++ (){
        // get the size of the vector
        int max= this->getV().size(); 
        // increnement the vector by 1      
        for (unsigned long i=0;i<max;i++){
            this->_v[i]++;
        }  
        return *this;
    }

    Matrix Matrix:: operator-- (){
        // get the size of the vector
        int max= this->getV().size();
        // decrenement the vector by 1 
        for (unsigned long i=0;i<max;i++){
            this->_v[i]--;
        } 
        return *this; 
    }

    Matrix Matrix::operator++ (int){
        // use the operator+()func to get a copy of the Matrix
        Matrix tmp = +(*this);
        // use the increment function on the matrix
        ++*this;
        // return the Matrix that was not incremented
        return tmp;
    }
    
    Matrix Matrix::operator-- (int){
        // use the operator+()func to get a copy of the Matrix
        Matrix tmp = +(*this);
        // use the decrement function on the matrix
        --*this;
        // return the Matrix that was not decremented
        return tmp;

    }


    //multiplacation

    Matrix Matrix::operator* (double d) const {
        // get the vector
        vector<double> newv=this->getV();
        // multiply the vector by d
        for (unsigned long j=0;j<newv.size();j++){
            newv[j]*=d;
        } 
        int r=this->getRow();
        int c=this->getCol(); 
        Matrix newmat{newv,r,c};
        return newmat;
    }

    Matrix zich::operator*(double d, Matrix &m){
        // get the vector
        vector<double> matv=m.getV();
        // multiply the vector by d
        for (unsigned long i=0; i<matv.size();i++){
            matv[i]*=d;
        }
        int r=m.getRow();
        int c=m.getCol();
        Matrix mat{matv,r,c};
        return mat;
    }

    Matrix Matrix::operator* (const Matrix & m)const{
        // check if th col of this= row of m
         if(this->getCol()!=m.getRow()){
            throw std::invalid_argument( "these matrices can not be multiplyed" );
        }
        
        unsigned long col_this= (unsigned long) this->getCol();
        unsigned long row_this=(unsigned long) this->getRow();
        unsigned long col_m=(unsigned long) m.getCol();

        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;

        //get the vectors
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        // create a new vector with the new size
        vector<double> new_v;
        new_v.resize(row_this*col_m);

        // looping through the "rows" of the this, the "columns" of m
        // multypling the value for each element in each "row" and "col" adding it together and putting in the spot in the new vector
        for (unsigned long i=0;i<row_this;i++){
            spot_this=i;
            spot_this*=col_this;
            for (unsigned long j=0; j<col_m;j++){
                spot_m=j;
                d=0;
                for (unsigned long n=0; n<col_this;n++){
                    d+=(this_v[spot_this+n]*m_v[spot_m]);
                    spot_m+=col_m;                    
                }
                new_v[k]=d;
                k++;
            }             
        }
        // creating a new matrix with the row size = this row size and the col size = m col size
        Matrix new_m{new_v,this->getRow(),m.getCol()};
        return new_m;
    }

    Matrix Matrix::operator*= (const Matrix & m){
        if(this->getCol()!=m.getRow()){
            throw std::invalid_argument( "these matrices can not be multiplyed" );
        }
        
        unsigned long col_this= (unsigned long) this->getCol();
        unsigned long row_this=(unsigned long) this->getRow();
        unsigned long col_m=(unsigned long) m.getCol();

        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;
        
        //get the vectors
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        // create a new vector with the new size
        vector<double> new_v;
        new_v.resize(row_this*col_m);

        // looping through the "rows" of the this, the "columns" of m
        // multypling the value for each element in each "row" and "col" adding it together and putting in the spot in the new vector
        for (unsigned long i=0;i<row_this;i++){
            spot_this=i;
            spot_this*=col_this;
            for (unsigned long j=0; j<col_m;j++){
                spot_m=j;
                d=0;
                for (unsigned long n=0; n<col_this;n++){
                    d+=(this_v[spot_this+n]*m_v[spot_m]);
                    spot_m+=col_m;                    
                }
                new_v[k]=d;
                k++;
            }             
        }
        // updating the col size of the matrix and the the vector of the matrix
        int c= m.getCol();
        this->setCol(c);
        this->setV(new_v);
        return *this;
    }
    
    Matrix Matrix::operator*= (double d){
        // multiply the vector by d
        for (unsigned long i=0; i<this->_v.size();i++){
            this->_v[i]*=d;
        } 
        return *this;
    }



    // comparing

    bool Matrix::operator== (const Matrix & m )const{
        // check if the matrices are the same size
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        // get the size of the vectors
        int max1 = this->getV().size();
        // compare each element if they are different return false
        for (unsigned long i=0; i<max1;i++){
            if(this->_v[i]!=m._v[i]){
                return false;
            }
        }
        // if we got here all elements are the same return true
        return true;
    }

    bool Matrix::operator< (const Matrix & m)const{
        // check if the matrices are the same size
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        //get the size of the vectors
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        // calculate the sum of each vector
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1<sum2);
    }

    bool Matrix::operator<= (const Matrix & m)const{
        // check if the matrices are the same size
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        //get the size of the vectors
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        // calculate the sum of each vector
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1<=sum2);
    }

    bool Matrix::operator> (const Matrix & m)const{
        // check if the matrices are the same size
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        //get the size of the vectors
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        // calculate the sum of each vector
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1>sum2);

    }

    bool Matrix::operator>= (const Matrix & m)const{
        // check if the matrices are the same size
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        //get the size of the vectors
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        // calculate the sum of each vector
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return (sum1>=sum2);
       
    }

    bool Matrix::operator!= (const Matrix & m)const{
        // get the answer for the fnction equals
        bool ans = *this==m;
        // the opposite
        return(!ans);
    }



    // input output

    ostream& zich::operator<< (ostream& output,const Matrix & m){
        int r=m.getRow();
        int c=m.getCol();
        unsigned long rl=( unsigned long)r;
        unsigned long cl=( unsigned long)c;
        unsigned long k=0;
        // loop through the "rows" of the vector
        // at the beginig of eavjh row put a [ add in the numbers after each number that isnt at the end of the row and a ' ' end with ]
        // after each rowthat isnt the last add '\n'
        for (unsigned long i=0;i<rl;i++){
            output<< '[';
            for (unsigned long j=0;j<cl;j++){
                output<< m._v[k];
                if(j<cl-1){
                    output<< ' ';
                }
                k++;
            }
            output << ']';
            if(i<rl-1){
                output << '\n';
            } 
        }
        return output;

    }

    istream& zich::operator>>(istream& input,  Matrix& m){
        
        // we will get the input and chack that at the beging and end are '[' ']'. if not we will throw an exception.
        // we will create an istream to parse the string by ',' this should give us a string vector of each row. 
        // we will check that each string in the vecter starts with '[' or ' ['(all rows but first) and end with ']'.
        // if not we will throw an exception. if we didnt throw an exception we will get rid of the '[' ot' [' at the begining and the ']' at the end of the string.
        // the size of the vector will be the row size
        // we will create an istream to parse the first row with ' '. and the size of the string vector will be the col size
        // we will create another istream to parse the rest of the rows into the same vector 
        // we will check that the size of the vector with all the parsed numbers is the size of col*row. if not we will throw an exception
        // we will create a double vector the same size as the string vector 
        // we will use a try and catch to change all the strings to doubles, 
        //if no exceptions are thrown the vector is good and we will set the values of the matrix

        string str;
        string mat_input;
        while(getline(input,str)){
            mat_input+=str;
        }

        if (mat_input[0]!='[' || mat_input[mat_input.length()-1]!=']' ){
            throw std::invalid_argument("illegal input"); 
        }

        vector<string> seglist;
        stringstream s_stream(mat_input); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            seglist.push_back(substr);
        }
 
        for(unsigned long i=0;i<seglist.size();i++){
            if(i>0){
                string str=seglist[i];
                if (str[0]!=' '){
                    throw std::invalid_argument("illegal input");     
                }
                if(str[1]!='[' || str[str.length()-1]!=']'){
                    throw std::invalid_argument("illegal input"); 
                }
                string newstr;
                for (unsigned long j=2;j<str.length()-1;j++){
                    newstr.push_back(str[j]);
                }
                seglist[i]=newstr;
            }
            else{
                string str=seglist[i];
                if(str[0]!='[' || str[str.length()-1]!=']'){
                    throw std::invalid_argument("illegal input"); 
                } 
                string newstr;
                for (unsigned long j=1;j<str.length()-1;j++){
                    newstr.push_back(str[j]);
                }
                seglist[i]=newstr;
            }
        }
        
        int row=(int)seglist.size();
        
        vector<string> numlist;
        stringstream s_stream1(seglist[0]); //create string stream from the string
        while(s_stream1.good()) {
            string substr;
            getline(s_stream1, substr, ' '); //get first string delimited by a space
            numlist.push_back(substr);
        }

        int col=(int)numlist.size();
        
        for(unsigned long i=1;i<seglist.size();i++){
            stringstream s_stream2(seglist[i]); //create string stream from the string
            while(s_stream2.good()) {
                string substr;
                getline(s_stream2, substr, ' '); //get the string delimited by a space
                numlist.push_back(substr);                
            }
        }

        // numlist should be a vector of strings -each string is a number
        int sum=(int)numlist.size();

        if(col*row!=sum){
            throw std::invalid_argument("illegal input"); 
        }

        vector<double> v;
        unsigned long summ=(unsigned long)sum;
        v.resize(summ);
        try{
            for (unsigned long i=0;i<numlist.size();i++){
                double d=stod(numlist[i]);
                v[i]=d;
            }  
        }
        catch(exception e){
            throw std::invalid_argument("illegal input"); 
        }

        m.setCol(col);
        m.setRow(row);
        m.setV(v); 
        return input;
    }