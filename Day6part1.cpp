#include <iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
void getcount(string s,vector<int>&v2)
{
    vector<char>v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());

    int k = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (v[i] == v[i - 1])
        {
            continue;
        }
        else if (v[i] != v[i - 1])
        {
            k++;
        }
    }
    v2.push_back(k);
}


int main()
{
    string p;
    string word = "";
    vector<string>v;
    vector<string>v1;
    
    ifstream indata;
    indata.open("Day6data");
    if(indata.fail())
    {
        cout<<"something is wrong"<<endl;
    }
    while (getline(indata, p))
    {
        v.push_back(p);
    }
    int k=0;
    for(int i=0;i<2196;i++)
    {
        if(v[i].empty()) 
        {
            
            v1.push_back(word);//clubbing all charecters in group
            word="";
            k=0;
        }
        else{
            word=word.append(v[i]);
            k++;
        }
    }
    vector<int>v3;
    for(int i=0;i<v1.size();i++)
    {
        getcount(v1[i],v3);
    }
    

    int sum=0;
    for(int i=0;i<v1.size();i++)
    {
        sum=sum+v3[i];
    }
    cout<<"Part1 : "<<sum<<endl;
    
    return 0;
}