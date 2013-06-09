/*
    PPP - Bjarne Stroustrup
    Chapter 4, Exercise 10,
    The Scissors-rock-paper Game
    (Finish date:14.04.2013 19:23)
*/

#include "../../../std_lib_facilities.h"
//#include<ctime>
using namespace std;

#define X 1000000
#define Y 10

/* procedural programming */
void put_values(vector<int>&);
void show_values(vector<int>&);
void show_statistics(vector<int>&);
void put_hr(void);
void get_pieces(void);
void show_pieces(void);
void adjust_points(void);
void show_points(void);
void show_comparisons(void);
void show_get_choices(void);
void dealloc(void);

/* global variables */
vector<string> pieces;
int** points;

int main(int argc, char *argv[])
{
    srand(time(NULL));  //real randomness
    vector<int> a(X);
    
    put_values(a);
    
    //show_values(a);
    
    put_hr();
    
    show_statistics(a);

    put_hr();
    
    get_pieces();
    
    put_hr();
    
    show_pieces();
    
    put_hr();
    
    adjust_points();
    
    put_hr();
    
    show_points();
    
    put_hr();
    
    show_comparisons();
    
    put_hr();
    
    show_get_choices(); //start the game
    
    put_hr();
    
    dealloc();
    
    system("pause");

    return EXIT_SUCCESS;
}

void put_hr()
{
    cout<<"*******************"<<endl;
}

void put_values(vector<int>& a)
{
    for(int i = 0; i < X; i++) {
       a[i] = rand() % Y;
    }
}

void show_values(vector<int>& a)
{
     for(int i = 0; i < X; i++)
     {
             cout<<"a["<<i<<"]="<<a[i]<<endl;
     }
}

void show_statistics(vector<int>& a)
{
    cout<<"Rastgele olusturulan sayilarin istatistikleri:"<<endl;
     for(int i = 0; i < Y; i++)
     {
             int count = 0;
             for(int j = 0; j < X; j++)
             {
                     if(a[j] == i)
                     {
                            count += 1;
                     }
             }
             cout<<i<<" : "<<count<<endl;
     }
}

void get_pieces()
{
    string temp;
    bool is_different;
    cout<<"Lutfen farkli parca giriniz(orn: makas, tas, kagit..)"<<endl;
    cout<<"Bitirmek icin \"ok\" girin."<<endl;
    
    while(cin>>temp && temp != "ok") {

        is_different = true;
        for(int i = 0; i < pieces.size(); i++) {
            if(temp == pieces[i])
            {
                is_different = false;
                break;
            }
        }
        if(!is_different)
        {
            cout<<"Lutfen farkli deger girin"<<endl;
            cout<<"\""<<temp<<"\" listede mevcut."<<endl;
            continue;
        }
        //entered a new value
        pieces.push_back(temp);
        cout<<"\""<<temp<<"\" listeye eklendi."<<endl;
    }
}
void show_pieces()
{
    for(int i = 0; i < pieces.size(); i++)
    {
        cout<<"pieces["<<i<<"] : "<<pieces[i]<<endl;
    }
}
void adjust_points()
{
    unsigned int len = pieces.size();
    
    if(len == 0) {  //early return
        return;
    }
    
    int val;

    //dynamic allocation of bi-directional array with pointer
    points = new int*[len];
    
    for(int i = 0; i < len; i++)
    {
        points[i] = new int[len];
    }
    
    //initialization
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            points[i][j] = -2;
        }
    }
    
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            // kagit vs kagit : 0; equal value
            if(i == j) {
                points[i][j] = 0;
                continue;
            }
            
            if(points[i][j] == -2) {

                cout<<pieces[i]<<" mi "<<pieces[j]<<" mi?"<<endl;
                cout<<" 1:"<<pieces[i]<<endl;
                cout<<"-1:"<<pieces[j]<<endl;
                cin>>val;
                
                points[j][i] = -1 * (points[i][j] = val);
            }
        }
    }
}
void show_points()
{
    for(int i = 0, len = pieces.size(); i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            cout<<points[i][j]<<" ";
        }
        cout<<endl;
    }
}
void show_comparisons()
{
    for(int i = 0, len = pieces.size(); i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            switch(points[i][j])
            {
                case 0:
                    cout<<pieces[i]<<" = "<<pieces[j]<<endl;
                    break;
                case 1:
                    cout<<pieces[i]<<" > "<<pieces[j]<<endl;
                    break;
                case -1:
                    cout<<pieces[i]<<" < "<<pieces[j]<<endl;
                default:
                    break;
            }
        }
    }
}
void show_get_choices() //main game promts
{
    cout<<"\t -- Oyun Basladi --"<<endl;

    int temp, randChoice, len = pieces.size();
    
    while(true)
    {
        cout<<"Seciminizi yapiniz:(Cikis icin '-1')"<<endl;
        for(int i = 0; i < len; i++)
        {
            cout<<(i + 1)<<" : "<<pieces[i]<<endl;
        }

        cin>>temp;

        if(temp == -1) {
            cout<<"cikis yapildi..."<<endl;
            return;
        }

        if(temp < 1 || temp > len) {
            cout<<"Yanlis girdiniz!!!"<<endl;
            continue;
        }
        
        cout<<"Seciminiz: "<<pieces[temp - 1]<<endl;
        cout<<"Benim secimim ise: ";

        randChoice = rand() % len;

        cout<<pieces[randChoice]<<endl;

        put_hr();

        if(temp - 1 == randChoice) {
            cout<<"\t.BERABERE."<<endl;
        }
        else if(points[temp - 1][randChoice] == 1) {
            cout<<pieces[temp - 1]<<" > "<<pieces[randChoice]<<endl;
            cout<<"\tSEN KAZANDIN!!!"<<endl;
        }
        else if(points[temp - 1][randChoice] == -1) {
            cout<<pieces[temp - 1]<<" < "<<pieces[randChoice]<<endl;
            cout<<"\tBEN KAZANDIM!!!"<<endl;
        }
        cout<<endl;
    }
}
void dealloc()
{
    //release memory held by bi-directional array
    for(int i = 0, len = pieces.size(); i < len; i++)
    {
        delete [] points[i];
    }

    delete [] points;

    pieces.clear();
}
