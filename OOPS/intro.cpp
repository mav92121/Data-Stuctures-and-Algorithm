#include <bits/stdc++.h>
using namespace std;
//creating a class
class Hero
{
    //properties
    private:
    int level=12;
    
    public:
    int health=120;

    //default constructure
    Hero()
    {
        //constructure called
    }

    //copy constructor
    Hero(Hero &temp) // if we don't pass by reference then it will give error
    {
        this->health=temp.health;
        this->level=temp.level;
    }
    void print()
    {
        cout<<level<<endl; 
    }
};

int main()
{
    // static creation of Object
    Hero h1;
    cout<<"Size : "<<sizeof(h1)<<endl; // size of properties

    cout<<h1.health<<endl;
    h1.print();
    // cout<<h1.level<<endl; -> error as it is private


    // dynamic creation of Object

    Hero *b =new Hero;
    // or
    Hero *c=new Hero();


    cout<<(*b).health<<endl;
    // or
    cout<<b->health<<endl;
    Hero m(h1);
    cout<<m.health<<endl;

    delete b;
    delete c;
    return 0;
}