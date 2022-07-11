#include <bits/stdc++.h>
using namespace std;

class Hero
{
    private:

    int health;
    char level;

    public:
    //getters
    int getHealth()
    {
        return health;
    }
    int getLevel()
    {
        return level;
    }
    //setters
    void setHealth(int h)
    {
        health=h;
    }
    void setLevel(char l)
    {
        level=l;
    }
};
int main()
{
    Hero ramesh;
    //setting values
    ramesh.setHealth(12);
    ramesh.setLevel('A');
    //getting values
    cout<<ramesh.getHealth()<<endl;
    cout<<(char)ramesh.getLevel()<<endl;
    return 0;
}