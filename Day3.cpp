#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int tree(vector<string> v,int a,int b)
{
    int x = 0;
    int y;
    int h = 322;
    int count = 0;
    for(y=0;y<323;y=y+b)
    {
        if (v[y][x] =='#')
        {
            x=((x+a)%31);
            count++;
        }
        else{
            x=((x+a)%31);
        }
    }
    return count;
}

int main()
{
    ifstream indata;
    string p;
    
    indata.open("day3data");
    if(indata.fail())
    {
        cout<<"something is wrong"<<endl;
    }
    vector<string> v;
    
    while(indata>>p)
    {
       
        v.push_back(p);
        
    }
    int t1=tree(v,1,1);
    int t2=tree(v,3,1);
    int t3 = tree(v, 5, 1);
    int t4 = tree(v, 7, 1);
    int t5 = tree(v, 1, 2);
    //PART1
    cout<<t2<<endl;
    //PART2
    cout<<(t1*t2*t3*t4*t5)<<endl;//multiply all the values
    
    return 0;
}
