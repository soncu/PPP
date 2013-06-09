#include "../../../std_lib_facilities.h"

int main(int argc, char *argv[])
{
   vector<double> values;
   double temp, min, max, sum = 0.0;
   bool is_first = true;   
   
   cout<<"Please enter distances:"<<endl;
   
   while(cin>>temp){
        sum += temp;
        values.push_back(temp);
        
        if(is_first) {
            min = max = temp;
            is_first = false;
        }
        else {
            if (temp < min) 
                        min = temp;
           else if (temp > max)
                        max = temp;
        }                
   }
   
   cout<<"Sum is "<<sum<<endl;
   cout<<"Min is "<<min<<endl;
   cout<<"Max is "<<max<<endl;
   
   sort(values.begin(), values.end());   //for median, we sort
   
   if(values.size()%2) { //tek sayýda ise ortadaki sayý
         cout<<"median is "<<values[values.size()/2]<<endl;
   }
   else {                //çift sayýdalar ise ortadaki iki sayýnýn ortalamasý
         cout<<"median is "<<(values[values.size()/2-1]+values[values.size()/2])/2<<endl;
   }   
   
   keep_window_open("|");
   return 0;
}
