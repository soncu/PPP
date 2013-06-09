#include "../../../std_lib_facilities.h"

bool is_prime(int);
vector<int>* get_primes(int, int, int);
void show_values(vector<int>*);

int main(int argc, char *argv[])
{
    /*
    for(int i = 2; i < 100; i++)
    {
        if(is_prime(i))
            cout<<i<<" is prime"<<endl;
        else
            cout<<i<<" is not prime"<<endl;
    }
    */
    
    /*  *************************** */
    int min, max, count;
    vector<int>* ptr = get_primes(9, 123, -1);
    show_values(ptr);
    ptr->clear();
    /*  *************************** */
    
    ptr = get_primes(1000, 0, 12);
    show_values(ptr);
	ptr->clear();
    
	cout<<"*********************"<<endl;
	cout<<"Please enter min, max or count (-1 for no count)"<<endl;
	cin>>min>>max>>count;
	ptr = get_primes(min, max, count);
    show_values(ptr);
    ptr->clear();

    keep_window_open();
    return EXIT_SUCCESS;
}

void show_values(vector<int>* p)
{
    int len = p->size();
    cout<<len<<" total vaues;"<<endl;
    for(int i = 0; i < len; i++)
    {
        cout<<"ptr["<<i<<"] : "<<(*p)[i]<<endl;
    }
}

vector<int>* get_primes(int min, int max, int count = -1)
{
    vector<int>* primes = new vector<int>;

    if(count == -1) {

        for(int i = min; i <= max; i++)
        {
            if(is_prime(i)) {
                primes->push_back(i);
            }
        }
    }
    else {

        int counter = 0;
        for(int i = min; counter < count; i++)
        {
            if(is_prime(i)) {
                primes->push_back(i);
                counter++;
            }
        }
    }

    return primes;
}

bool is_prime(int num)
{
    if(num < 2) {
        return false;
    }

    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
