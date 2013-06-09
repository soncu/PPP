/**
*  This program is a modified simple calculator
*  only 5 operations are supported
*  Date : 1 Nisan 2013 21:58
****************************/

#include "../../../std_lib_facilities.h"

vector<string> digits(10);    //global vector variable

bool is_num(const string&);
int string_to_digit(const string&);

int main(int argc, char *argv[])
{
    string arg1, arg2;
    double result;
    char op;
    
    digits[0] = "zero";
    digits[1] = "one";
    digits[2] = "two";
    digits[3] = "three";
    digits[4] = "four";
    digits[5] = "five";
    digits[6] = "six";
    digits[7] = "seven";
    digits[8] = "eight";
    digits[9] = "nine";
    
    cout<<"Please enter a calculation operation (\"5\" \"nine\" *)"<<endl;
    cout<<"Then result will be 5 * 9 = 45"<<endl;
    
    while(cin>>arg1>>arg2>>op) {
        
        int i1 = string_to_digit(arg1);
        int i2 = string_to_digit(arg2);

        if(i1 == -1 || i2 == -1) {
              cout<<"Your entered numbers out of allowed range"<<endl;
              cout<<"Please enter a calculation operation (\"5\" \"nine\" *)"<<endl;
              continue;
        }               
                                   
        switch(op){
                   case '+':
                        result = i1 + i2;
                        break;
                   case '-':
                        result = i1 - i2;
                        break;
                   case '*':
                        result = i1 * i2;
                        break;
                   case '/':
                        result = i1 / i2;
                        break;
                   case '%':
                        result = i1 % i2;
                        break;
                   default:
                           break;
        }
        cout<<i1<<" "<<op<<" "<<i2<<endl;
        cout<<"your result is "<<result<<endl;
        
        cout<<"Please enter a calculation operation (\"5\" \"nine\" *)"<<endl;
    }    
    
    keep_window_open();
    return EXIT_SUCCESS;
}

/* is entered parameter is number or not */
bool is_num(const string& s)
{
     string::const_iterator it = s.begin();
     
     //to handle signed integers
     if(*it == '-' || s[0] == '+') it++;
     
     while(it != s.end() && isdigit(*it)) ++it;
	 
     return !s.empty() && it == s.end();
}

/* return int representation of entered value, -1 for unwanted values
   s: "0"-"9" or "zero"-"nine" values */
int string_to_digit(const string& s)
{
       if(is_num(s))
       {
           int num = atoi(s.c_str());
           return num < 0 ? -1: num;
       }
       else
       {
           unsigned int i, len = digits.size();
           for(i = 0; i < len; i++)
           {
                    if(s == digits[i])
                         return i;
                    //else continue;    
           }
           //if(i == len) //can be used, but not necessare since after the loop it means no matching string in the vector
           
           return -1;
       }
}
