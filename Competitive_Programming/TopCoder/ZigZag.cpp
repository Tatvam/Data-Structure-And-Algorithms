#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
 
using namespace std;

class ZigZag {
    public :
    int longestZigZag(vector <int> sequence){
        if(sequence.size() == 1)return 1;
        int n = sequence.size();
        vector<int> v(n-1,0);
        for(int i = 1; i<n ;i++){
            v[i-1] = sequence[i-1]-sequence[i];
        }
        int j = 0;
        while(j<v.size() && v[j] == 0)
            j++;
        if(j == v.size()){
            return 1;
        }
        int d = v[j];
        int l = 2;
        for(int k = j+1;k<n-1;k++){
            if(v[k]*d<0){
                d*=-1;
                l++;
        }
    }
        return l;
    }
};