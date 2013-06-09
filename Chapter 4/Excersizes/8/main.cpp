/*
  chess invertor versus the emperor problem 
  about grains for each square on the board
*/
#include "../../../std_lib_facilities.h"
using namespace std;

int square_number_for(unsigned int);

int main(int argc, char *argv[])
{
    cout<<square_number_for(1000)<<" squares for at least 1 thousand grains"<<endl;
    cout<<square_number_for(1000000)<<" squares for at least 1 million grains"<<endl;
    cout<<square_number_for(1000000000)<<" squares for at least 1 billion grains"<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

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
