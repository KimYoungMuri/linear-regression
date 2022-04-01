#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
 
const int maxN = 300005;
const int INF = 1e9;
using namespace std;
 
double sum[2000] = {}, numdays[2000] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ifstream in("/Users/youngkim/Desktop/LR_Research/DAWSON_COMBINED_STATION.csv");
    string line, field;
    vector< vector<string> > array;  // the 2D array
    vector<string> v;                // array of values for one line only
 
    while ( getline(in,line) ){
        v.clear();
        stringstream ss(line);
 
        while (getline(ss,field,',')){
            v.push_back(field);  // add each field to the 1D array
        }
 
        array.push_back(v);  // add the 1D array to the 2D array
    }
 
    string year;
    int cur_time=1961;
    int start = 2, end=2;
    for (size_t i=1; i<array.size(); ++i){
        string temp = array[i][3];
        year = temp.substr(0,4);
        //cout << temp << "\n";
        string lengthened = temp.substr(5,6);
        string month = lengthened.substr(0,2);
        //cout << month << "\n";
        int cur_year = stoi(year);
        if (cur_time != cur_year){
            printf("=PERCENTILE.EXC(E%d:E%d,0.81)\n", start, end+1);
            cur_time = cur_year;
            start = i;
        }
        end = i;
        int t_max = stoi(array[i][5]);
        
        int t_min = stoi(array[i][6]);
        int t_obs = stoi(array[i][7]);
        int precip = stoi(array[i][4]);
        
        if (month == "05" or month == "06" or month == "07" or month == "08" or month == "09"){
            sum[cur_year] += t_max;
            numdays[cur_year] ++;
        }
    }
    printf("=PERCENTILE.EXC(E18321:E18686,0.81)\n");
    
    for (int i=1961; i<=2012; i++){
        //cout << year << ": " << sum[i] << " " << numdays[i] << "\n";

        float avg = float(sum[i] / numdays[i]);
        //cout << avg << "\n";
        //cout << i << "\n";
    }
 
 
 
}
