/*
  chess invertor versus the emperor problem 
  about grains for each square on the board
*/

#include "myheader.h"

int main(int argc, char *argv[])
{
    cout<<square_number_for(1000)<<" squares for at least 1 thousand grains"<<endl;
    cout<<square_number_for(1000000)<<" squares for at least 1 million grains"<<endl;
    cout<<square_number_for(1000000000)<<" squares for at least 1 billion grains"<<endl;
    
    for(int i = 1; i < 65; i++)
    {
            if(i <= 32)
                cout<<"square ["<<i<<"]: "<<total_grains_for<unsigned int>(i)<<" grains"<<endl;
            else
                cout<<"square ["<<i<<"]: "<<total_grains_for<double>(i)<<" grains"<<endl;
            
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}

