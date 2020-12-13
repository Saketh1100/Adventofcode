#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include<iomanip>
#include<sstream>//for converting string digits to int 

using namespace std;
int Separatewords(string str)//function for finding whether password is valid or not
{
    vector<string>v;//this vector is to store words in a give line
    
    int j=0;
    string word = "";
    
    int l=str.length();
    
    for (int i=0;i<l;i++)//Goes through all charecters and separates word 
    {
        string x;
        x=str[i];
        if ((x == " "||x=="-")&&i != l-1)
        {
            if(word=="")
            {
                continue;
            }
            else{
                v.push_back(word);
            }
            
            
            
            word = "";
        }
        else if(x==":")
        {

            if (word == "")
            {
                continue;
            }
            else
            {
                v.push_back(word);
            }
            word="";
        }
        
        
        else if(i==l-1)
        {
            word=word+x;//making a 

            if (word == "")
            {
                continue;
            }
            else
            {
                v.push_back(word);
            }
        }
        else
        {
            word = word + x;
        }
    }
    int count=0;//for finding frequecy of required charecter
    
    for(int y=0;y<v[3].length();y++)
    {
        char s=v[2][0];
        
        if(v[3][y]==s)
        {
            
            count++;
        }
    }
    
    stringstream sss(v[0]);//for converting '15' to 15 (example)
    int x=0;
    sss>>x;
    stringstream ss(v[1]);
    int z=0;
    ss>>z;
    if(z>=count&&x<=count )//checking wheather count is in range of given numbers
    {
        return 1;//this returned value stored in a vector v1 in main function
    }
    else
    {
        return 0;
    }
    


    
}

int main()
{
    string p;//to store a line from a given data 
    vector<int>v1;
    
    
    ifstream indata;//for reading data from file
    indata.open("Day2 data");
    if(indata.fail())
    {
        cout<<"something went wrong"<<endl;//for any kind of error messages
    }
    
    
    while(indata)
    {
        getline(indata,p);//taking a line at a time and checking its validity

        int x=Separatewords(p);//returns either 0 or 1 based on its validity
        if(x==1)
        {
            v1.push_back(1);//main reason to add 1 to a vector is to easily count no of valid passwords
        }
    }
    cout<<v1.size()<<endl;
    

    return 0;


}