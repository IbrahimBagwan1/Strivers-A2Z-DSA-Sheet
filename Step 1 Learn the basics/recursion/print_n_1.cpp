#include<bits/stdc++.h>
using namespace std;


class sol{
  public:
    int count=10;
    void print(){
      if(count==0) return;
      cout<<count<<" ";
      count--;
      print();
    }
};

int main(){
  sol s;
  s.print();
  return 0;
}