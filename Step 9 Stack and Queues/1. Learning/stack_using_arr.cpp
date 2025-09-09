#include<bits/stdc++.h>
using namespace std;

void push(vector<int> & arr, int n){
  arr.push_back(n);
}

int pop(vector<int> &arr){
  int n = arr.size();
  int ret = -1;
  if(n!=0){
    ret = arr[n-1];
    arr.pop_back();
  }

  return ret;
}

void display(vector<int> arr){
  int n = arr.size();
  if(n==0)return;
  for(int i=n-1; i>=0; i--){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int> st;
  while(1){
    int n;
    cout<<"Do you want to Push:"<<" Enter 1: "<<endl;
    cout<<"Do you want to POP:"<<" Enter 2: "<<endl;
    cout<<"Do you want to Display:"<<" Enter 3: "<<endl;
    cin>>n;

    switch (n)
    {
    case 1:
      int num;
      cin>>num;
      push(st,num);
      break;
    case 2:
      int pop1;
      pop1 = pop(st);
      cout<<pop1<<endl;
      break;
    
    case 3:
      display(st);
      break;

    default:
      return 0;
      break;
    }
  }
  return 0;
}