#include "string"
#include <iostream>
using namespace std;
class PayoutTable{
    public:
        PayoutTable(){}
        // check combination and return appropriate cash prize
        int getPayment(std::string result){
           if(result == "AAA"){
               return 14;
           }else if(result == "BBB"){
               return 35;
           }else if(result == "CCC"){
               return 100;
           }else if(result == "777"){
               return 999;
           }else{
               return 0;
           }
        }
};