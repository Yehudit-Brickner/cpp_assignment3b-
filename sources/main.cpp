
#include <string>
#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace zich;



// int main(){
    
//     bool ans;

//     vector<double> v1={1,2,3,4,5,6,7,8,9}; //3x3
//     vector<double> v2={2.5,3.5,4.5}; // 1x3 and 3x1
//     vector<double> v3={2.0,4.2,6.4,8.6,10.8,13.0,15.2,17.4}; //4x2 2x4
//     vector<double> v4={0,1,0,1,2,1,0,1,0}; //3x3
    
//     Matrix mat1{v1,3,3};
//     cout<< "mat1\n" << mat1<< "\n"<< endl;
//     Matrix mat2{v2,3,1};
//     cout<< "mat2\n" << mat2<< "\n"<< endl;
//     Matrix mat3{v2,1,3};
//     cout<< "mat3\n" << mat3<< "\n"<< endl;
//     Matrix mat4{v3,4,2};
//     cout<< "mat4\n" << mat4<< "\n"<< endl;
//     Matrix mat5{v3,2,4};
//     cout<< "mat5\n" << mat5<< "\n"<< endl;
//     Matrix mat6{v4,3,3};
//     cout<< "mat6\n" << mat6<< "\n"<< endl;


//     // + 
//     Matrix mat7 = mat1+mat6;
//     cout<< "mat7\n" << mat7<< "\n"<< endl;

//     // * matrices
//     Matrix mat8 = mat2*mat3;
//     cout<< "mat8\n" << mat8<< "\n"<< endl;
//     Matrix mat9 = mat4*mat5;
//     cout<< "mat9\n" << mat9<< "\n"<< endl;
//     Matrix mat10 = mat5*mat4;
//     cout<< "mat10\n" << mat10<< "\n"<< endl;
//     Matrix mat11 = mat2*mat3;
//     cout<< "mat11\n" << mat11<< "\n"<< endl;
//     Matrix mat12 = mat3*mat2;
//     cout<< "mat12\n" << mat12<< "\n"<< endl;

//     // wrong equal

//     cout<< "mat9 and mat10 \n"<< mat9<< "\n"<<endl;
//     cout<< mat10<< "\n"<< endl;
//     try{
//         cout<< "comparing mat10 to mat9"<<endl;
//         ans =  mat10 == mat9;
//     }
//     catch(exception& ex){
//         cout << "   caught exception: " << ex.what() << "\n"<< endl;  
//     }
    
    
//     // == >= <= < > !=
//     cout << "mat1 and mat6 \n" << mat1<< "\n\n" <<mat6 << "\n"<< endl;
//     ans= mat1 == mat6;
//     cout <<"is mat1 equal to mat6? "<< ans<< endl;
//     ans= mat1 >= mat6;
//     cout <<"is mat1 bigger equal to mat6? "<< ans<< endl;
//     ans= mat1 <= mat6;
//     cout <<"is mat1 smaller equal to mat6? "<< ans<<endl;
//     ans= mat1 > mat6;
//     cout <<"is mat1 bigger then mat6? "<< ans<< endl;
//     ans= mat1 < mat6;
//     cout <<"is mat1 smaller then mat6? "<< ans<<endl;
//     ans= mat1 != mat6;
//     cout <<"is mat1 different from mat6? "<< ans<< "\n"<<endl;

//     // -=  == 
    
//     cout<< "mat7\n" << mat7<< "\n"<< endl;
//     bool ans8 = mat7==mat1;
//     cout <<"is mat7 equal to mat1? "<< ans8<< "\n"<< endl;
    

    
//     // + * - showing diference in order
//     Matrix mat13= (mat7+mat1)*3.45;
//     cout<< "mat13\n" << mat13<< "\n"<< endl;
//     mat13= mat7+(mat1*3.45);
//     cout<< "mat13\n" << mat13<< "\n"<< endl;
//     mat13= (mat7-mat1*3.45)+mat6;
//     cout<< "mat13\n" << mat13<< "\n"<< endl;
//     mat13= mat7-(mat1*3.45+mat6);
//     cout<< "mat13\n" << mat13<< "\n"<< endl;

//     // += wrong size
//     try{
//         mat1+=mat10;
//     }
//     catch(exception& ex){
//         cout << "   caught exception: " << ex.what() << "\n"<<endl;  
//     }
    
//     // -= wrong size
//     try{
//         mat2-=mat10;
//     }
//     catch(exception& ex){
//         cout << "   caught exception: " << ex.what() << "\n"<<endl;  
//     }

//     // +=
//     cout<< "mat1 before adding mat11 \n" << mat1<< "\n"<< endl;
//     cout<< "mat11 \n" << mat11<< "\n"<< endl;
//     mat1+=mat11;
//     cout<< "mat1 after adding mat11\n" << mat1<< "\n"<< endl;

//     // + - copying, left *, == 
//     Matrix mat14= +mat9;
//     cout<< "mat14 \n" << mat14<< "\n"<< endl;
//     Matrix mat15= -mat9;
//     cout<< "mat15 \n" << mat15<< "\n"<< endl;
//     Matrix mat16= -1*mat15;
//     cout<< "mat16 \n" << mat16<< "\n"<< endl;
//     ans = mat16==mat14;
//     cout <<"is mat16 equal to mat14? "<< ans<<"\n"<< endl;
//     cout<< "mat2 before *2 \n" << mat2<< "\n"<< endl;
//     mat2*=2;

//     // ++
//     cout<< "mat2 after *2 before add 1 \n" << mat2<< "\n"<< endl;
//     ++mat2;
//     cout<< "mat2 after add 1 before adding another 1 \n" << mat2<< "\n"<< endl;
//     Matrix mat17= mat2++;
//     cout<< "mat2 after add another 1 \n" << mat2<< "\n"<< endl;
//     cout<< "mat17 \n" << mat17 <<"\n"<<endl;


//     // --
//     cout<< "mat7 before subtracting 1 \n" << mat7<< "\n"<< endl;
//     --mat7;
//     cout<< "mat7 after subtracting 1 \n" << mat7<< "\n"<< endl;
//     Matrix mat18= mat7--;
//     cout<< "mat7 after sunbtracting another 1 \n" << mat7<< "\n"<< endl;
//     cout<< "mat18 \n" << mat18 <<"\n"<<endl;



//     // try{
//     //     Matrix matlast= +mat12;
//     //     cin >> matlast;
//     //     cout << "matlast \n"<<matlast<<"\n" <<endl;  
//     // }
//     // catch(exception& ex){
//     //     cout << "   caught exception: " << ex.what() << endl;  
//     // }

//     return 0; 

// }

