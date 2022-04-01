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
double t_one[100] = {99,95,100,98,95.825,95,93,97,98,98,94.825,95.8,96,98.825,96,96,98,98.825,97,100,98.6,96,97,96,96,97,96,100,97.65,99,98.65,90,90,94.825,99,90.8,95.825,97,94.825,100,98,99,97.825,95.8,99,99.825,97,91.8,92,93.825,96,100};
double t_two[100] = {85.46,85,88,86,83,85,84,86,84,88,86,86,85,85,86,86,85,88,86,90,85,84.75,82,85,83,83,85,87,84,85,85,81,80,84,82.27,80,83,85,82,86,86,87.27,85,83,88,86.27,85,81,81,84,84,90};

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
 
    int cnt = 0, subsum = 0, ans = 0;
    int year_temp = 1961;
    for (size_t i=1; i<array.size(); ++i){
        string year;
        string temp = array[i][3];
        year = temp.substr(0,4);
        
        int cur_year = stoi(year);

        if (year_temp != cur_year){
            cout << ans << "\n";
            subsum = 0;
            ans = 0;
            cnt = 0;
            year_temp = cur_year; 
        }

        int idx = cur_year - 1961;
        double t_max = stoi(array[i][5]);
        
        if (t_max >= t_one[idx]){
            cnt ++;
            subsum += t_max;
            if (cnt >= 3 && subsum/cnt > t_two[idx] && t_max > t_two[idx]){
                ans ++;
            }
        }
        if (t_max < t_one[idx]){
            subsum = 0;
            cnt = 0;
        }
        
        /*
        int t_min = stoi(array[i][6]);
        int t_obs = stoi(array[i][7]);
        int precip = stoi(array[i][4]);
         */
        
        sum[cur_year] += t_max;
        numdays[cur_year] ++;
        
    }
    
    for (int i=1961; i<=2012; i++){
        float avg = float(sum[i] / numdays[i]);
        //cout << avg << "\n";
    }
 
 
 
}
