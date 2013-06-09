#include "../../../std_lib_facilities.h"

bool is_num(const string&);

int main(int argc, char *argv[])
{
    vector<string> digits(10);
    string temp;
    
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
    
    for(unsigned int i = 0; i < digits.size(); i++) {
               cout<<i<<" : "<<digits[i]<<endl;
    }
    
    cout<<"Please enter a digit(string or number):"<<endl;
    
    while(cin>>temp) {
                     
    /** clean screen or exit **/
         if(temp == "cls") {
               system("CLS");
               goto linex;
         }
         else if(temp == "exit") {
               system("EXIT");
               break;
         }
    /** clean screen or exit **/
                     
        if(is_num(temp)) {   //if entered an integer
              
              int dig = atoi(temp.c_str());
              
              if(dig < 0 || dig >= digits.size()) {
                   cout<<"you entered a number out of range"<<endl;
              }
              else {
                   cout<<"you entered: "<<dig<<" and result: "<<digits[dig]<<endl;
              }                            
        }
        else {
             
             int i = 0, len = digits.size();
             
             while(i < len && temp != digits[i]) {
                  i++;
             }
             
             if(i == len) {
                  cout<<"you entered an undefined string"<<endl;     
             }
             else {
                  cout<<"you entered: "<<temp<<" and result: "<<i<<endl;
             }              
        }
        
 linex:   
        cout<<"Please enter a digit(string or number):"<<endl;
    }
    
    keep_window_open();
    return EXIT_SUCCESS;
}

bool is_num(const string& s)
{
     string::const_iterator it = s.begin();
     
     //to handle signed integers
     if(*it == '-' || s[0] == '+') it++;
     
     while(it != s.end() && isdigit(*it)) ++it;
	 
     return !s.empty() && it == s.end();
}
