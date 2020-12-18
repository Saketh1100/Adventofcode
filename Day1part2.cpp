#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{

    fstream indata;
    indata.open("day1data");
    vector<int> v;
    int p;
    if (indata.fail())
    {
        cout << "some thing is wrong";
    }
    while (indata >> p)
    {
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int l = v.size() - 1;
    int j=l;
    int count=1;
    int i;
    int a=0;
    int b=0;
    int c=0;
    

    for(int k=0;k<=l;k++)
    {
        int sum=2020-v[k];
        i=k+1;//because in previous value of k  i which are less than k combinations are already` covered
        j=l;
        while (i < j&&j!=k)
        {
            if (v[i] + v[j] == sum)//using same logic for sum of 2 numbers;
            {
                
                a=i;
                b=j;
                c=k;
                break;

                count=0;
            }
            else if (v[i] + v[j] < sum)
            {
                i++;
            }
            else if (v[i] + v[j] > sum)
            {
                j--;
            }
        }
        if(count==0)
        {
            break;
            
        }
    }
    
    
    cout << v[a]<<endl<<v[b]<<endl<<v[c] << endl;
    

    return 0;
}