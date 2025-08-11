#include<iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        int count=0;
        if(n<0) n=-n;
        while(n>0){
            count++;
            n=n/10;
        }
        return count;
    }
};