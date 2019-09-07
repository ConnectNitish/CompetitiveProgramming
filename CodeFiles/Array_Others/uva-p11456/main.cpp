/******************************************************************************
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2451
*******************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

template<typename T>
void print(T val)
{
    cout << val << " ";
}

int debug=0;

vector<vector<int>> arrangment;
int maxSize=0;
void maxTrain(vector<int> &data,int index,vector<int> &actualData)
{
    if(debug)
    cout << " INdex " << index << " Actual Size " << actualData.size() <<  endl;
    
    if(index>=actualData.size())
    {
        arrangment.push_back(data);
        
        // for(auto a:data)
        //     cout << a << " ";
        
        if(debug)
        {
            cout << " ******* " << endl;
            for_each(data.begin(),data.end(),print<int>);
            cout << endl << endl;
        }
        
        if(maxSize<data.size())
            maxSize = data.size();
        return;
    }
    
    for(int i=index;i<actualData.size();i++)
    {
        bool removefromlast = true;
        int size_of_vector = data.size();
        
        if(data.size()==0)
        {
            data.push_back(actualData[i]);
        }
        else
        {
            if(data.size()==1)
            {
                if(data[0]<=actualData[i])
                    data.push_back(actualData[i]);
                else
                {
                    data.insert(data.begin(),actualData[i]);
                    removefromlast = false;
                }
            }
            else
            {
                int first = data[0];
                int last = data[data.size()-1];
                if(actualData[i]>=last)
                    data.push_back(actualData[i]);
                else if(actualData[i]<=first)
                {
                    data.insert(data.begin(),actualData[i]);
                    removefromlast = false;
                }
            }
        }
        
        bool addedElement = false;
        
        if(size_of_vector<data.size())
            addedElement = true;
        
        if(debug)
        {
            cout << " ######################## " << endl;
            for_each(data.begin(),data.end(),print<int>);
            cout << endl;
        }
        
        maxTrain(data,i+1,actualData);
        
        if(addedElement==true)
        {
            
            
            if(removefromlast == true)
            {
                data.pop_back();
            }
            else
            {
                data.erase(data.begin());
            }
        }
        
        if(debug)
        {
            cout << " -------------- " << endl;
            for_each(data.begin(),data.end(),print<int>);
            cout << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        arrangment.clear();
        maxSize = 0;
        
        int N;
        cin >> N;
        int i=0;
        int V;
        vector<int> ID;
        while(i<N)
        {
            cin >> V;
            ID.push_back(V);
            i++;
        }
        vector<int> temp;
        maxTrain(temp,0,ID);
        cout << maxSize << endl;
    }
    return 0;
}



