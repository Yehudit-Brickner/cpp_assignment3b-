    #include "Matrix.hpp"
    #include <iostream>
    #include <stdexcept>
    #include <string>
    #include <vector>
    #include <sstream>










    using namespace zich;

    void Matrix::setMatrix (vector<double> & v,int r, int c){
        if( r<1 || c<1){
            //cout <<"r*c "<< r*c << "s " << v.size()<< endl;
            throw std::invalid_argument( "row or col invalid size" ); 
        }
        if(v.empty()){
            //cout <<"r*c "<< r*c << "s " << v.size()<< endl;
           throw std::invalid_argument( "vector  is invalid" ); 
        }
        if(r*c!=v.size()){
            //cout <<"r*c "<< r*c << "s " << v.size()<< endl; 
            throw std::invalid_argument( "size of vector doesnt match row*col" ); 
        }

        this->setRow(r);
        this->setCol(c);
        this->setV(v);
    }

    Matrix::Matrix (vector<double> v, int r, int c){
        this->setMatrix(v,r,c);
    }

    Matrix::Matrix(const Matrix & other){
        int r=other.getRow();
        int c =other.getCol();
        vector<double> old=other.getV();
        unsigned long s=old.size();
        vector<double> new_v;
        new_v.reserve(s);
        for (unsigned long i=0;i<s;i++){
            new_v[i]=old[i];
        }
        this->setCol(c);
        this->setRow(r);
        this->setV(new_v);
    }
    
   

    Matrix Matrix::operator+ (){
      int r= this->getRow();
      int c= this->getCol();
      vector<double>new_v=this->getV();
    //   cout<< "creating a new mat that is exactly the same" << endl;
      Matrix new_mat{new_v, r,c};
      return new_mat;
    }

    Matrix Matrix::operator+ (const Matrix & m ){
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

    Matrix Matrix::operator- (){
        int r= this->getRow();
        int c= this->getCol();
        vector<double>new_v=this->getV();
        for (unsigned long i=0;i<new_v.size();i++){
            if(new_v[i]!=0){
                new_v[i]*=-1;
            }
        }
        //   cout<< "creating a new mat that is exactly the same" << endl;
        Matrix new_mat{new_v, r,c};
        return new_mat;
    }

    Matrix Matrix::operator- (const Matrix & m){
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

    Matrix Matrix::operator++ (int i){
        Matrix *pmat= this;
        int max= this->getV().size();
        for (unsigned long i=0;i<max;i++){
            this->_v[i]++;
        }
        return *pmat;
    }
    
    Matrix Matrix::operator-- (int i){
         Matrix *pmat= this;
        int max= this->getV().size();
        for (unsigned long i=0;i<max;i++){
            this->_v[i]--;
        }
        return *pmat;

    }

    Matrix Matrix::operator* (double d){
        int max= this->getV().size();
        for (unsigned long j=0;j<max;j++){
            this->_v[j]=this->_v[j]*d;
        } 
         return *this;
    }

    Matrix zich::operator*(double d, Matrix &m){
        vector<double> matv=m.getV();
        for (unsigned long i=0; i<matv.size();i++){
            matv[i]*=d;
        }
        int r=m.getRow();
        int c=m.getCol();
        Matrix mat{matv,r,c};
        //Matrix ans1{m.getV(), m.getRow(),m.getCol()};
        //Matrix * ptrmat= new Matrix(matv,r,c);
        // ptrmat->setCol(c);
        // ptrmat->setRow(r);
        // ptrmat->setV(matv);
        return mat;
    }

    Matrix Matrix::operator* (const Matrix & m){
         if(this->getCol()!=m.getRow()){
            throw std::invalid_argument( "these matrices can not be multiplyed" );
        }
        
        unsigned long col_this= (unsigned long) this->getCol();
        //unsigned long row_m =(unsigned long) m.getRow();
        unsigned long row_this=(unsigned long) this->getRow();
        unsigned long col_m=(unsigned long) m.getCol();

        vector<double> new_v;
        new_v.resize(row_this*col_m);
        //cout<< new_v.size()<< endl;
        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();

        //cout << this_v.size() <<" "<< m_v.size() << " "<<m._v.size()<<  " "<< new_v.size()<< endl; 
        for (unsigned long i=0;i<row_this;i++){
            spot_this=i;
            spot_this*=col_this;
            for (unsigned long j=0; j<col_m;j++){
                spot_m=j;
                d=0;
                for (unsigned long n=0; n<col_this;n++){
                   // cout<<  "k="<< k<< " "<< this_v[spot_this+n]<<" "<<m_v[spot_m]  <<" d=" << d<< endl;
                    d+=(this_v[spot_this+n]*m_v[spot_m]);
                    spot_m+=col_m;                    
                }
                //cout<<  "d= "<< d<<endl;
                new_v[k]=d;
                k++;
            }             
        }
        Matrix new_m{new_v,this->getRow(),m.getCol()};
        // this->setRow(this->getRow());
        // this->setCol(m.getCol());
        // this->setV(new_v);
        return new_m;
    }

    Matrix Matrix::operator*= (const Matrix & m){
        if(this->getCol()!=m.getRow()){
            throw std::invalid_argument( "these matrices can not be multiplyed" );
        }
        
        unsigned long col_this= (unsigned long) this->getCol();
        //unsigned long row_m =(unsigned long) m.getRow();
        unsigned long row_this=(unsigned long) this->getRow();
        unsigned long col_m=(unsigned long) m.getCol();

        vector<double> new_v;
        new_v.resize(row_this*col_m);
        //cout<< new_v.size()<< endl;
        unsigned long spot_m=0;
        unsigned long spot_this=0;
        unsigned long k=0;
        double d=0;
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();

        //cout << this_v.size() <<" "<< m_v.size() << " "<<m._v.size()<<  " "<< new_v.size()<< endl; 
        for (unsigned long i=0;i<row_this;i++){
            spot_this=i;
            spot_this*=col_this;
            for (unsigned long j=0; j<col_m;j++){
                spot_m=j;
                d=0;
                for (unsigned long n=0; n<col_this;n++){
                   // cout<<  "k="<< k<< " "<< this_v[spot_this+n]<<" "<<m_v[spot_m]  <<" d=" << d<< endl;
                    d+=(this_v[spot_this+n]*m_v[spot_m]);
                    spot_m+=col_m;                    
                }
                //cout<<  "d= "<< d<<endl;
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

    bool Matrix::operator== (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        // int max1 = this->getV().size();
        // double sum1 = 0;
        // double sum2 = 0;
        // for (unsigned long i=0; i<max1;i++){
        //     sum1+=this->_v[i];
        //     sum2+=m._v[i];
        // }
        // if(sum1==sum2){
        //     return true;
        // }
        // return false;
        int max1 = this->getV().size();
        for (unsigned long i=0; i<max1;i++){
            if(this->_v[i]!=m._v[i]){
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator< (const Matrix & m){
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
        // if(sum1<sum2){
        //     return true;
        // }
        // return false;
        return(sum1<sum2);
    }

    bool Matrix::operator<= (const Matrix & m){
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
        // if(sum1<=sum2){
        //     return true;
        // }
        
        // return false;
        return(sum1<=sum2);
    }

    bool Matrix::operator> (const Matrix & m){
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
        // if(sum1>sum2){
        //     return true;
        // }
        // return false;
        return(sum1>sum2);

    }

    bool Matrix::operator>= (const Matrix & m){
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
        // if(sum1>=sum2){
        //     return true;
        // }
        // return false;
        return (sum1>=sum2);
       
    }

    bool Matrix::operator!= (const Matrix & m){
        // if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
        //     throw std::invalid_argument( "row or column dont match" );
        // }
        // int max1 = this->getV().size();
        // double sum1 = 0;
        // double sum2 = 0;
        // for (unsigned long i=0; i<max1;i++){
        //     sum1+=this->_v[i];
        //     sum2+=m._v[i];
        // }
        // if(sum1!=sum2){
        //     return true;
        // }
        // return false;
        bool ans = *this==m;
        return(!ans);
    }

    ostream& zich::operator<< (ostream& output,const Matrix & m){
        int r=m.getRow();
        int c=m.getCol();
        //string ans="";
        unsigned long rl=( unsigned long)r;
        unsigned long cl=( unsigned long)c;
        unsigned long k=0;
        for (unsigned long i=0;i<rl;i++){
            //ans.push_back('[');
            output<< '[';
            for (unsigned long j=0;j<cl;j++){
                //ans.push_back(m._v[k]);
                //cout<< m._v[k];
                output<< m._v[k];
                if(j<cl-1){
                    //ans.push_back(' ');
                    output<< ' ';
                }
                k++;
            }
            //ans.push_back(']');
            output << ']';
            output << '\n';
            // if(i<rl){
            //     //ans.push_back('\n');
            //     output << '\n';
            // } 
        }
        //return ans;
        //output << ans<< endl;
        //output << ans ;
        return output;

    }

    istream& zich::operator>>(istream& input,  Matrix& m){
        

            // needs work!!!!!!!


        // cout<< "please enter the amount of rows"<< endl; 
        // input >> m._row;
        // cout<< "please enter the amount of cols"<< endl; 
        // input >> m._col;
        // vector<double> new_v;
        // unsigned long co=(unsigned long)(m._col);
        // unsigned long ro=(unsigned long)(m._row);
        // unsigned long s=co*ro;
        // new_v.resize(s);
        // cout<< "please enter the marix values"<< endl; 
        // for (unsigned long i=0; i<s;i++){
        //     input >> new_v[i];
        // }
        // m._v=new_v;
        // return input;
        cout<< "first time called" << endl;
        string s;
        input>> s;
        cout << s<<endl;
        stringstream test(s);
        string segment;
        vector<string> seglist;
        vector<string> nums;
        vector<double> v;
        int row=1;
        int col=1;
        while(getline(test, segment, ',')) {
            seglist.push_back(segment);
            cout<< segment<< endl;
        }
        row=seglist.size();
        for (unsigned long i=0; i<seglist.size();i++){
                stringstream n(seglist[i]);
            while(getline(n, segment, ' ')) {
                nums.push_back(segment);
            }
            for (unsigned long j=0; i<nums.size();i++){
                v.push_back(stod(nums[j]));
            }
            nums.clear();
        }
        int v_size=(int)v.size();
        if(v_size/row>0) {
            col=v_size/row;
        }
        cout<< "row "<<row<<" col "<< col<< endl;
        Matrix new_m{v,row,col};
        return input;
    }