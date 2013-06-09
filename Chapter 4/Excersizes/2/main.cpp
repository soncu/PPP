#include "../../../std_lib_facilities.h"

int main(int argc, char *argv[])
{
   vector<double> values; 
   double a, val, sum = 0.0,
          min = 1.7E+308,     //max value for a double
          max = 1.7E-308,     //min value for a double
          m_to_cm = 100.0,    //1 m  = 100  cm
          in_to_cm = 2.54,    //1 in = 2.54 cm
          ft_to_in = 12;      //1 ft = 12   in
   string unit;
   string legals[] = {"m", "cm", "in", "ft"};
   unsigned sz = sizeof(legals)/sizeof(string);
   
   cout<<"Please keep entering a double\nfollowed by a unit(i.e. 24.3ft):('|' for exit)"<<endl;
   
   while(cin>>a>>unit) {
        /************ if not legal unit, skip iteration ***************/               
        bool exists = false;        
        for(unsigned i = 0;i < sz; i++) {
              if(unit == legals[i]) {
                      exists = true;
                      break;
              }
        }
        if(!exists) {
              cout<<"bilinmeyen birim"<<endl;
              continue;
        }        
        /************* guarantees that unit in legals **************/
        
        //girilen deðeri metreye çevirerek saklýyoruz
        val = unit == "m"? a : 
              unit == "cm"? a/100 : 
              unit == "in"? a*2.54/100 : a*12*2.54/100;
        
        cout<<"girdiginiz deger:"<<a<<endl;
        cout<<"girdiginiz birim:"<<unit<<endl;
        cout<<"girdiginiz uzunluk: "<<val<<" metre"<<endl;
        
        if(val < min) {
             min = val;
             cout<<"smallest"<<endl;
        }
        if(max < val) {
             max = val;
             cout<<"largest"<<endl;
        }
        
        cout<<"Toplam: "<<(sum+=val)<<" metre."<<endl;
        values.push_back(val);   //girilen deðerleri vectorde saklýyoruz
   }
   
   cout<<"Girdiginiz deger"<<(values.size() > 1? "ler sirali olarak:" : ":")<<endl;
   sort(values.begin(), values.end());
   for(unsigned int i = 0, len = values.size(); i < len; i++){
       cout<<values[i]<<(i+1 == len? "\n": ", ");         
   }
   
   //median: ortadaki sayý: tek ise tam ortadaki, çift ise ortadaki sayýlarýn ortalamasý
   if(values.size()%2)      //tek ise
   {
         cout<<"median is "<<values[values.size()/2]<<endl;
   }
   else
   {
        cout<<"median is "<<(values[values.size()/2-1] + values[values.size()/2])/2<<endl;
   }
   
   cout<<"Program is terminating.."<<endl;
   
   keep_window_open("|");
   return 0;
}
