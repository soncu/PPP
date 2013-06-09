#include "../../../std_lib_facilities.h"
using namespace std;

int main(int argc, char *argv[])
{
    unsigned int Min = 1, Max = 100, counter = 0;
    bool temp;
    
    cout<<"Welcome to number guessing game"<<endl;
    
    while(Min < Max) {
         cout<<"Is your number less than "<<(Min + Max)/2<<" ("<<Min<<","<<Max<<")"<<endl;
         cin>>temp;
         
         if(temp) 
             Max = (Min + Max)/2;
         else     
             Min = (Min + Max)/2;
         
         if(Min == Max) {
                cout<<"You thought number "<<Min<<endl;
                break;
         }         
         else if(Max - Min == 1) {
                cout<<"Is your number "<<Min<<" ?"<<endl;
                cin>>temp;
                
                if(temp)
                    cout<<"Ok, your number is "<<Min<<endl;
                else
                    cout<<"Then your number is "<<Max<<endl;
                break;        
         }                         
         
         if(counter++ > 7) break;         
    }
    
    //cout<<"Tuttugunuz sayi ya "<<Min<<" ya da "<<Max<<endl;
    
    keep_window_open("m");
    return EXIT_SUCCESS;
}
