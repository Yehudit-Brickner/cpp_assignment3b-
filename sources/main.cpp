
#include <string>
#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace zich;



int main(){
    std::cout<<"helllo world"<<endl;
    vector<double> v1={1,2,3,4,5,6,7,8,9}; //3x3
    vector<double> v2={2.5,3.5,4.5}; // 1x3 and 3x1
    vector<double> v3={2.0,4.2,6.4,8.6,10.8,13.0,15.2,17.4}; //4x2 2x4
    vector<double> v4={0,1,0,1,2,1,0,1,0}; //3x3
    
    Matrix mat1{v1,3,3};
    cout<< "mat1\n" << mat1<< "\n"<< endl;
    Matrix mat2{v2,3,1};
    cout<< "mat2\n" << mat2<< "\n"<< endl;
    Matrix mat3{v2,1,3};
    cout<< "mat3\n" << mat3<< "\n"<< endl;
    Matrix mat4{v3,4,2};
    cout<< "mat4\n" << mat4<< "\n"<< endl;
    Matrix mat5{v3,2,4};
    cout<< "mat5\n" << mat5<< "\n"<< endl;
    Matrix mat6{v4,3,3};
    cout<< "mat6\n" << mat6<< "\n"<< endl;




    Matrix mat7 = mat1+mat6;
    cout<< "mat7\n" << mat7<< "\n"<< endl;
    Matrix mat8 = mat2*mat3;
    cout<< "mat8\n" << mat8<< "\n"<< endl;
    Matrix mat9 = mat4*mat5;
    cout<< "mat9\n" << mat9<< "\n"<< endl;
    Matrix mat10 = mat5*mat4;
    cout<< "mat10\n" << mat10<< "\n"<< endl;
    Matrix mat11 = mat2*mat3;
    cout<< "mat11\n" << mat11<< "\n"<< endl;
    Matrix mat12 = mat3*mat2;
    cout<< "mat12\n" << mat12<< "\n"<< endl;


    try{
        cout<< "comparing mat10 to mat9"<<endl;
        bool ans1 =  mat10 == mat9;
    }
    catch(exception& ex){
        cout << "   caught exception: " << ex.what() << endl;  
    }
    bool ans2= mat1 == mat6;
    cout <<"is mat1 equal to mat6? "<< ans2<< endl;
    bool ans3= mat1 >= mat6;
    cout <<"is mat1 bigger equal to mat6? "<< ans3<< endl;
    bool ans4= mat1 <= mat6;
    cout <<"is mat1 smaller equal to mat6? "<< ans4<< "\n"<<endl;


    mat7-=mat6;
    cout<< "mat7\n" << mat7<< "\n"<< endl;
    bool ans5 = mat7==mat1;
    cout <<"is mat7 equal to mat1? "<< ans5<< "\n"<< endl;
    
    Matrix mat13= mat7+mat1*3.45;
    cout<< "mat13\n" << mat13<< "\n"<< endl;
    try{
        mat1+=mat10;
    }
    catch(exception& ex){
        cout << "   caught exception: " << ex.what() << "\n"<<endl;  
    }
    cout<< "mat1 before \n" << mat1<< "\n"<< endl;
    cout<< "mat11 \n" << mat11<< "\n"<< endl;
    mat1+=mat11;
    cout<< "mat1 after\n" << mat1<< "\n"<< endl;


    Matrix mat14= +mat9;
    cout<< "mat14 \n" << mat14<< "\n"<< endl;
    Matrix mat15= -mat9;
    cout<< "mat15 \n" << mat15<< "\n"<< endl;
    Matrix mat16= -1*mat15;
    cout<< "mat16 \n" << mat16<< "\n"<< endl;
    bool ans6= mat16==mat14;
    cout <<"is mat16 equal to mat14? "<< ans6<<"\n"<< endl;






   
   
    
    return 0;
}