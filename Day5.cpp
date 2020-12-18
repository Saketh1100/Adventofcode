#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void getrow(char p,vector<int>&v)
{

    if(p=='F')
    {
        v[0]=v[0];
        v[1]=(v[0]+v[1])/2;
    }
    else if(p=='B')
    {
        v[0]=(v[0]+v[1]+1)/2;
        v[1]=v[1];
    }
}
void getcolumn(char p,vector<int>&v)
{
    if(p=='R')
    {
        v[0] = (v[0] + v[1] + 1) / 2;
        v[1] = v[1];
    }
    else if(p=='L')
    {
        v[0] = v[0];
        v[1] = (v[0] + v[1]) / 2;
    }
}
int getID(string str)
{
    vector<int>v1;
    vector<int>v2;
    v2.push_back(0);
    v2.push_back(7);
    v1.push_back(0);
    v1.push_back(127);
   for(int a=0;a<7;a++)
   {
       getrow(str[a],v1);
       
   }
   for(int a=7;a<10;a++)
   {
       getcolumn(str[a],v2);
   }
   return v1[0]*8+v2[0];
}
int main()
{
    vector<int> v;
    fstream indata;
    string p;
    indata.open("Day5data");
    if (indata.fail())
    {
        cout << "something is wrong";
    }
    while (indata)
    {
        getline(indata,p);
        int l = getID(p);
        v.push_back(l);
    }
    
    sort(v.begin(), v.end());
    int k=v.size();
    cout<<"part1:"<<v[k-1]<<endl;
    for(int i=0;i<k;i++)
    {
        if(v[i+1]-v[i]==2)
        {
            cout<<"part2:"<<v[i+1]-1<<endl;
        }

    }
    
    return 0;
}
