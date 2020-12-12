#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
int main()
{
    
    fstream indata;
    indata.open("day1data");
    vector<int>v;
    int p;
    if(indata.fail())
    {
        cout<<"some thing is wrong";
    }
    while(indata>>p)
    {
        v.push_back(p);
    }

    sort(v.begin(),v.end());
    
    int j=v.size();
    int i=0;
    

     while(true)
   {
       if(v[i]+v[j]==2020)
       {
           
           break;
       }
       else if(v[i]+v[j]<2020)
      {
          i++;

       }
       else if (v[i] + v[j] > 2020)
       {
           j--;
       }
     }
     
    cout<<(v[i]*v[j])<<endl;
    indata.close();
   

   

    
    

    return 0;
}