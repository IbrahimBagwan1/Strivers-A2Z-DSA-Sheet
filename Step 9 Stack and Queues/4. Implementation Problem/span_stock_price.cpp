#include <iostream>
#include <deque>
using namespace std;

class StockSpanner {
public:
    deque<pair<int,int>> dq;
    StockSpanner() {}

    int next(int price) {
        int freq = 1;
        while(!dq.empty() && price >= dq.back().first){
            pair<int,int> ele = dq.back();
            freq += ele.second;
            dq.pop_back();
        }
        dq.push_back({price, freq});
        return freq;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(prices[0]);

    cout << "Stock span results: ";
    for(int i=0; i<n; i++) {
        cout << obj->next(prices[i]) << " ";
    }
    cout << endl;

    delete obj;
    return 0;
}
