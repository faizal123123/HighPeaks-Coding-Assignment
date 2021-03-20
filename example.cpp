#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Goodies
{
    public:
    string name_of_item;
    int price_of_item;
    int stringTointeger(string str)
    {
        int temp = 0;
        for (int i = 0; i < str.length(); i++)
        {
            temp = temp * 10 + (str[i] - '0');
        }
        return temp;
    }
    string substring(string ip, int startpos, int length)
    {
        string str;
        for(int i = 0; i<length; i++)
        {
            str[i] = ip[ i + startpos];
        }
        return str;
    }
};
int main()
{
    string input, number;
    vector<Goodies> vg;
    ifstream ip_file;
    Goodies g;
    ip_file.open("sample_input.txt");
    if(!ip_file.is_open())
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while (!ip_file.eof())
        {
            getline(ip_file,input);
            for(int i = 0; i<input.size(); i++)
            {
                if(input[i] == ':')
                {
                    g.name_of_item = input.substr(0, i);
                    number = input.substr(i+2, input.size()-i-2);
                    g.price_of_item = g.stringTointeger(number);
                    break;
                }
            }
            vg.push_back(g);
        }
    }
    ip_file.close();
    int min_ind =0;
    Goodies temp;
    for(int i =0 ; i<vg.size()-1; i++) //Sorting
    {
        min_ind = i;
        for(int j = i+1; j<vg.size(); j++)
        {
            if(vg[j].price_of_item<vg[min_ind].price_of_item)
            {
                min_ind = j;
            }
        }
        temp = vg[i];
        vg[i] = vg[min_ind];
        vg[min_ind] = temp;
    }

    //Find minimum:
    cout<<"Enter number of employees:"<<endl;
    int no_of_emp = 0;
    cin>>no_of_emp;
    int temp2 = vg[3].price_of_item - vg[0].price_of_item;
    int min2 = 0;
    for(int i = 1; i<=vg.size()-no_of_emp; i++)
    {
        if(temp2 > vg[i + no_of_emp - 1].price_of_item - vg[i].price_of_item)
        {
            temp2 = vg[i + no_of_emp - 1].price_of_item - vg[i].price_of_item;
            min2 = i;
        }
    }
    ofstream file_out("sample_out.txt", ios::out);
    file_out<<"Here are the goodies which are selected for the distribution."<<endl;
    cout<<"Here are the goodies which are selected for the distribution."<<endl;
    for(int i = 0; i<no_of_emp; i++)
    {
        file_out<<vg[i+min2].name_of_item<<" : "<<vg[i+min2].price_of_item<<endl;
        cout<<vg[i+min2].name_of_item<<" : "<<vg[i+min2].price_of_item<<endl;
    }
    cout<<"And the difference between the chosen goods with the highest price and lowest price is: "<<temp2<<endl;
    file_out<<"And the difference between the chosen goods with the highest price and lowest price is: "<<temp2<<endl;
    file_out.close();
    return 0;
}
