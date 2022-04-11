    #include "Matrix.hpp"
    #include <iostream>
    #include <stdexcept>
    #include <string>
    #include <vector>
    #include <sstream>










    using namespace zich;


    Matrix::Matrix (const vector<double> &v, int r, int c){
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

    Matrix::Matrix(const Matrix & other){
        int r=other.getRow();
        int c =other.getCol();
        vector<double> old=other.getV();
        this->_col=c;
        this->_row=r;
        this->_v=old;
    }
    
   

    Matrix Matrix::operator+ ()const{
      int r= this->getRow();
      int c= this->getCol();
      vector<double>new_v=this->getV();
      Matrix new_mat{new_v, r,c};
      return new_mat;
    }

    Matrix Matrix::operator+ (const Matrix & m )const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        unsigned long s=this_v.size();
        vector<double> new_v;
        new_v.resize(s);
        for (unsigned int j=0;j<s;j++){
            new_v.at(j)=this_v.at(j)+m_v.at(j);
        }
        int c=this->getCol();
        int r=this->getRow();
        Matrix change{new_v,r,c};
        return change;
    }

    Matrix Matrix::operator+= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        } 
        vector<double> m_v=m.getV();
        for (unsigned long i=0; i<m_v.size();i++){
            this->_v[i]+=m_v[i];
        } 
        return *this;
    }

    Matrix Matrix::operator- ()const {
        int r= this->getRow();
        int c= this->getCol();
        vector<double>new_v=this->getV();
        for (unsigned long i=0;i<new_v.size();i++){
            if(new_v[i]!=0){
                new_v[i]*=-1;
            }
        }
        Matrix new_mat{new_v, r,c};
        return new_mat;
    }

    Matrix Matrix::operator- (const Matrix & m)const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        } 
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        unsigned long s=this_v.size();
        vector<double> new_v;
        new_v.resize(s);
        for (unsigned int j=0;j<s;j++){
            new_v.at(j)=this_v.at(j)-m_v.at(j);
        }
        int c=this->getCol();
        int r=this->getRow();
        Matrix change{new_v,r,c};
        return change;  
    }

    Matrix Matrix::operator-= (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        } 
        vector<double> m_v=m.getV();
        for (unsigned long i=0; i<m_v.size();i++){
            this->_v[i]-=m_v[i];
        } 
        return *this;
    }



    Matrix Matrix:: operator++ (){
        int max= this->getV().size();       
        for (unsigned long i=0;i<max;i++){
            this->_v[i]++;
        }  
        return *this;
    }

    Matrix Matrix:: operator-- (){
        int max= this->getV().size();
        for (unsigned long i=0;i<max;i++){
            this->_v[i]--;
        } 
        return *this; 
    }

    Matrix Matrix::operator++ (int){
        Matrix tmp = +(*this);
        ++*this;
        return tmp;
    }
    
    Matrix Matrix::operator-- (int){
        Matrix tmp = +(*this);
        --*this;
        return tmp;

    }

    Matrix Matrix::operator* (double d) const {
        int max= this->getV().size();
        int r=this->getRow();
        int c=this->getCol();
        vector<double> newv=this->getV();
        for (unsigned long j=0;j<max;j++){
            newv[j]*=d;
        } 
       Matrix newmat{newv,r,c};
       return newmat;
    }

    Matrix zich::operator*(double d, Matrix &m){
        vector<double> matv=m.getV();
        for (unsigned long i=0; i<matv.size();i++){
            matv[i]*=d;
        }
        int r=m.getRow();
        int c=m.getCol();
        Matrix mat{matv,r,c};
        return mat;
    }

    Matrix Matrix::operator* (const Matrix & m)const{
         if(this->getCol()!=m.getRow()){
            throw std::invalid_argument( "these matrices can not be multiplyed" );
        }
        
        unsigned long col_this= (unsigned long) this->getCol();
        unsigned long row_this=(unsigned long) this->getRow();
        unsigned long col_m=(unsigned long) m.getCol();

        vector<double> new_v;
        new_v.resize(row_this*col_m);
        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();

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

        vector<double> new_v;
        new_v.resize(row_this*col_m);
        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();

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
        int r=this->getRow();
        int c= m.getCol();
        this->setRow(r);
        this->setCol(c);
        this->setV(new_v);
        return *this;
    }
    
    Matrix Matrix::operator*= (double d){
        for (unsigned long i=0; i<this->_v.size();i++){
            this->_v[i]*=d;
        } 
        return *this;
    }

    bool Matrix::operator== (const Matrix & m )const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        for (unsigned long i=0; i<max1;i++){
            if(this->_v[i]!=m._v[i]){
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator< (const Matrix & m)const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1<sum2);
    }

    bool Matrix::operator<= (const Matrix & m)const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1<=sum2);
    }

    bool Matrix::operator> (const Matrix & m)const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return(sum1>sum2);

    }

    bool Matrix::operator>= (const Matrix & m)const{
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        return (sum1>=sum2);
       
    }

    bool Matrix::operator!= (const Matrix & m)const{
        bool ans = *this==m;
        return(!ans);
    }

    ostream& zich::operator<< (ostream& output,const Matrix & m){
        int r=m.getRow();
        int c=m.getCol();
        unsigned long rl=( unsigned long)r;
        unsigned long cl=( unsigned long)c;
        unsigned long k=0;
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
        
        string str;
        string mat_input;
        while(getline(input,str)){
            mat_input+=str;
        }
        cout<<"mat_input "<<mat_input<<endl;

        if (mat_input[0]!='[' || mat_input[mat_input.length()-1]!=']' ){
            cout<<"threw an eeror because start isnt [ or end isnt ] of the input"<<endl;
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
                    cout<<"threw an eeror because start isnt ' ' "<<endl;
                    throw std::invalid_argument("illegal input");     
                }
                if(str[1]!='[' || str[str.length()-1]!=']'){
                    cout<<"threw an eeror because start isnt [ or end isnt ] of the row"<<endl;
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
                    cout<<"threw an eeror because start isnt [ or end isnt ] of the row"<<endl;
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
                getline(s_stream2, substr, ' '); //get first string delimited by a space
                numlist.push_back(substr);                
            }
        }
        // numlist should be a vector of strings -each string is a number
        int sum=(int)numlist.size();
        cout<< col<< " "<< row<<" " <<sum<<endl;
        if(col*row!=sum){
            cout<<"threw an eeror because col*row!=sum"<<endl;
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
            cout<<"threw an eeror because isnt number"<<endl;
            throw std::invalid_argument("illegal input"); 
        }
       // m.setMatrix(v,row,col);
       m.setCol(col);
       m.setRow(row);
       m.setV(v); 
        return input;
    }