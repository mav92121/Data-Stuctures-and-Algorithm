// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

struct petrolPump
{
    int petrol;
    int distance;
};

#include <bits/stdc++.h>
using namespace std;

int tour(petrolPump p[],int n)
{
    int start=0;
    int need=0;
    int balance=0;
    for(int i=0;i<n;i++)
    {
        balance+=p[i].petrol-p[i].distance;
        if(balance<0)
        {
            start=i+1;
            need+=(balance);
            balance=0;
        }
    }
    if(need+balance>=0)return start;
    return -1;
}