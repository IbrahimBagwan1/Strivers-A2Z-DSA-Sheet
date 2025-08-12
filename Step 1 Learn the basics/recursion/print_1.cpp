#include<bits/stdc++.h>
using namespace std;


class sol{
  public:
    int count=0;
    void print(){
      if(count==10) return;
      cout<<count<<" ";
      count++;
      print();
    }
};

int main(){
  sol s;
  s.print();
  return 0;
}