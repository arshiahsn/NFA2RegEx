//===========================Created by Arshia.Hsn===========================
#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
//===========================Transition Table===========================
  class transition  
  {
    public:
      int from;								//Principle (Mabda') State
      char input;							//Edges (Yaal)
      int to;								//Destination (Maghsad) State
	  transition(int from_state,char input_symbol,int to_state);         
      static bool smaller(transition a, transition b);               
      friend ostream &operator<<(ostream &stream, transition trans);
  };
//===============================NFA Class===============================
  class NFA
  {
  public:
	set<int> Q;								//Q (States)
	set<char> Sigma;						//Sigma (Alphabet)
	vector<transition> Delta;				//Delta (Transition Table)
	int q0;									//q0 (Starting State)
	set<int> F;								//F (Final States)
	set<int> Principles;					//A set of all principle states
	set<int> Destinations;					//A set of all destination states
	NFA();									//Constructor
	void Convert(void);						//Convert to RegEx Function

  };
  




#endif