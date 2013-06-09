#include "../../../std_lib_facilities.h"
using namespace std;

/* how many squares required to accomodate totol grains at least */
int square_number_for(unsigned int grains_total)
{
    int current_square;                  //initial 1
    unsigned int grains_current;         //initial 1
    unsigned int grains_sum = 0;         //initial 0
    
    for(current_square = grains_current = 1; grains_sum < grains_total; current_square++)
    {
		grains_sum += grains_current;
		grains_current *= 2;
    }
	
	if(grains_sum != grains_total) {
		cout<<"Absolute grain sum is "<<grains_sum<<endl;
	}
    
    return current_square - 1; //to adjust the exact position
}

/* how many total grains there for a given number of squares*/
template<typename T>
T total_grains_for(int num)
{
    T sum = 0;
    T grains_current = 1;
    
    for(int i = 1; i <= num; i++)
    {
            sum += grains_current;
            grains_current *= 2;
    }
    
    return sum;
}
