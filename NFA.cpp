//===========================Created by Arshia.Hsn===========================
#include"NFA.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;


transition::transition(int from_state,char input_symbol,int to_state)				//Definition for constructor
{
	 from=from_state;
     input=input_symbol;
     to=to_state;
}
bool transition::smaller(transition a, transition b)
{ 
	if(a.from<b.from) return true;
	else if(a.from>b.from) return false;
	else return a.input<b.input;
}

NFA::NFA()
{
	q0=0;
}

////===========================Convert Function===========================
void NFA::Convert()
{
	set<int>::const_iterator z;
	int cnt = 0;
	string r[20][20][20];												//A three dimensional string array used to initialize regular expressions
	string re = " ";
	for(int k = 0;k<=Q.size();k++)										//Initializing 3-D Array using 3 fors
		for (int i = 1;i<=Q.size();i++)
			for(int j = 1;j<=Q.size();j++)
				{
					//if(k == Q.size() && i>1)
					//	break;
					if(k == 0)											//For the first column
					{
						for(int l = 0;l<Delta.size();l++)				//Traverse on Transition table inorder to find desired edge (from i to j)
						{
							if(Delta[l].from == i && Delta[l].to == j)  //Finding the edge from i to j
							{
								string temp(1,Delta[l].input);			//Casting char to string
								if(j == i)
									{
										if(r[k][i][j] != "")
											r[k][i][j] = r[k][i][j] +"+" + temp + "+ epsilon";
										else
											r[k][i][j] = temp + "+ epsilon";
									}
								else
									{
										if(r[k][i][j] != "")
											r[k][i][j] = r[k][i][j] +"+" + temp;
										else
											r[k][i][j] = temp;

									}
							}

						}
					}
					else																//For other than first columns
					{
						if(r[k-1][k][k] != "" && r[k-1][i][j] != "")					//Initializing array using dynamic solution
							r[k][i][j] = r[k-1][i][k] + "(" + r[k-1][k][k] + ")*" + r[k-1][k][j] + "+" + r[k-1][i][j];
						else
							if(r[k-1][k][k] != "")
								r[k][i][j] = r[k-1][i][k] + "(" + r[k-1][k][k] + ")*" + r[k-1][k][j];
							else
								if(r[k-1][k][j] != "")
									r[k][i][j] = r[k-1][i][k] + r[k-1][k][j] + "+" + r[k-1][i][j];
								else
									r[k][i][j] = r[k-1][i][k] + r[k-1][k][j];
					}
			}
	
	for(z=F.begin();z != F.end();z++)								//Initializing answer array using first->final transitions.
		re += r[Q.size()][1][*z];
	cout<<"\nThe equal RegEx is : "<<re;

}
