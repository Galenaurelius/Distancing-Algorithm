#ifndef DISTANCING_H
#define DISTANCING_H

#include <iostream>
#include <vector>
using namespace std;

	//n is number of spots, p is number of people
	int n, p;

  
	//vector of ints containing the distance from each table
	vector<int> tables;

	//reads input
	void input();
	//checks a range to see if it works with the given set of tables, returns true if it does, false otherwise
	bool distanceChecker(int v);
	
	//driver function
	int findMaxMin();	
  
#endif
