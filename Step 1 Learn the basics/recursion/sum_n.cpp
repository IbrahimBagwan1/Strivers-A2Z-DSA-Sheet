#include<bits/stdc++.h>
using namespace std;


class sol{
  public:
    void print(int count, int &sum){
      if(count==10){
        return;
      }
      cout<<count<<" ";
      sum=sum+count;
      count++;
      print(count,sum);
    }
};

int main(){
  sol s;
  int sum=0;
  s.print(1,sum);
  cout<<endl<< "The Sum is: "<< sum;
  return 0;
}