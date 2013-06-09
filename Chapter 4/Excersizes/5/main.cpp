/**
*  This program is a simple calculator
*  only 5 operations are supported
*  Date : 17 Mart 2013 12:45
****************************/

#include "../../../std_lib_facilities.h"

int main(int argc, char *argv[])
{
    double arg1, arg2, result;
    char op;
    
    cout<<"Please enter a calculation operation (25.1 67.9 %)"<<endl;
    
    while(cin>>arg1>>arg2>>op) {
                                   
        switch(op){
                   case '+':
                        result = arg1 + arg2;
                        break;
                   case '-':
                        result = arg1 - arg2;
                        break;
                   case '*':
                        result = arg1 * arg2;
                        break;
                   case '/':
                        result = arg1 / arg2;
                        break;
                   case '%':
                        result = (int)arg1%(int)arg2;
                        break;
                   default:
                           break;
        }
        
        cout<<"your result is "<<result<<endl;
        
        cout<<"Please enter a calculation operation (25.1 67.9 %)"<<endl;
    }    
    
    keep_window_open();
    return EXIT_SUCCESS;
}
