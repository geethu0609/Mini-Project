
QUESTION:
  Design an algorithm that collects daily price quotes for some stock and returns the span of
  that stock&#39;s price for the current day.
  The span of the stock&#39;s price in one day is the maximum number of consecutive days
  (starting from that day and going backward) for which the stock price was less than or equal
  to the price of that day.

  For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the
  stock today is 2, then the span of today is 4 because starting from today, the price of the
  stock was less than or equal 2 for 4 consecutive days.
  Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock
  today is 8, then the span of today is 3 because starting from today, the price of the stock was
  less than or equal 8 for 3 consecutive days.

PROJECT:
  
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> prices;

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
       
        while (!prices.empty() && prices.top().first <= price) {
            span += prices.top().second;
            prices.pop();
        }
        
        prices.push({price, span});
        
        return span;
    }
};


int main() {
    StockSpanner stockSpanner;
    cout << stockSpanner.next(100) << endl;  
    cout << stockSpanner.next(80) << endl;   
    cout << stockSpanner.next(60) << endl;
    cout << stockSpanner.next(70) << endl;   
    cout << stockSpanner.next(60) << endl;   
    cout << stockSpanner.next(75) << endl;   
    cout << stockSpanner.next(85) << endl;   
    
    return 0;
}


