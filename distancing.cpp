#include <iostream>
#include <vector>
#include "distancing.h"
#include <limits>
//#include "timer.h"


using namespace std;

//Input
void input() {
  cout << "# of tables: " << endl;
  cin >> n;
  cout << "# of people to be seated: " << endl;
  cin >> p;
  
  int y;


  for (int i = 0; i < n; i++) {
    cin >> y;
    tables.push_back(y);
  }
  


}

//Divide-and-conquer function finds the max distance between individuals sitting at tables
int findMaxMin() {
  if(p == 2) return tables.back() - tables.front();
  //variables l and r for lower and upper bound for range of solution
  int l = 1;
  int r = tables.back() - tables.front();
  //m is midpoint between l and r
  int m = 0;
  while (true) {
    m = l + (r-l)/2;
    if (m == l) break;
    if (distanceChecker(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return m;
}

//Helper function to find if the given range is possible
bool distanceChecker(int v) {
  //current table to place person at
  int curr = tables.front() + v;
  //start, mid, end, res indexes for binary search
  int start, mid, end, res;
  //r = remaining people to place (first person always placed at first table)
  for (int r = p - 1; r > 0; r--) {
    if (curr > tables.back()) return false;
    //binary search to find first element greater than minimum range v
    start = 0;
    end = tables.size();
    while (start <= end) {
      mid = (start + end)/ 2;
      if(tables[mid] < curr) {
	start = mid + 1;
      } else {
	res = mid;
	end = mid-1;
      }
    }
    curr = tables[res] + v;
  }
  return true;
}

int main() {
  input();
  cout << "Minimum Distance: " << findMaxMin() << endl;
}
