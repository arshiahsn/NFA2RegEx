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



int main() 
{
    

  cout<<"======================== Enter your desired keyword : ========================\n";
  cout<<"Note : State names can only be numbers. \nEnter - Start - and input a starting state, \nEnter - Final - and input a final state,\nEnter - Language - to declare your \nlanguage alphabet(press . to end alphabet input),\nEnter - Exit - to exit, \nor enter a principle state's name to start inputing a transition. \n";
  cout<<"Enter - Convert - to convert the NFA to Regular Expression.\n";
  cout<<"==============================================================================\n";
  NFA myNFA;
  string Input;

  while(!cin.eof())													//Input loop
  {
	a:
	cin >> Input;
	getchar();
	int Principle;       
	string Symbol;     
	int Destination;         
	int Final;   
    if(cin.eof()) break;
	if(Input == "Language")
	{
		char inpt;
		cout<<"\nInsert your language alphabet : \n";
		while(cin>>inpt)
		{
			if(inpt == '.') 
				{
					cout<<"You successfully enterd yourlanguage alphabet.";
					goto a;
				}
			myNFA.Sigma.insert(inpt);
		}
	}
    if(Input=="Start")
    {
      cout<<"\nInsert your Starting State's name : \n";
	  cin >> myNFA.q0 ;
      myNFA.Q.insert(myNFA.q0);
	  cout<<endl;
      continue;
    }
    else if(Input=="Final")
    {
      cout<<"\nInsert your Final State's name : \n";
	  cin >> Final;
      myNFA.F.insert(Final);
	  cout<<endl;
      continue;
    }
	else if(Input=="Exit")
		goto Exit;
    else if(Input=="Convert") 
    {                            
		sort(myNFA.Delta.begin(), myNFA.Delta.end(), transition::smaller );
		set<int>::const_iterator iter1;										//Iterators are used to traverse sets Q and F
		cout<<"\nYour states are : ";
		for(iter1=myNFA.Q.begin(); iter1 != myNFA.Q.end(); iter1++) 
		{
				cout << *iter1<<" ";
				//if((iter1++) != myNFA.Q.end())
				//	cout<<",";

		}
		cout<<"\nYour starting state is : "<<myNFA.q0<<endl;
		cout<<"\nYour final state(s) are : ";
		for(iter1=myNFA.F.begin(); iter1 != myNFA.F.end(); iter1++) 
		{	
			cout << *iter1<<" ";
			//if((++iter1) != myNFA.F.end())
			//		cout<<",";
		}
		cout<<"\nTransisions are : ";
		for(int g = 0;g<myNFA.Delta.size();g++)
			{
				cout<<myNFA.Delta[g].from<<"-"<<myNFA.Delta[g].input<<"->"<<myNFA.Delta[g].to;
				if(g!= myNFA.Delta.size()-1)cout<<" | ";
		}
		cout << endl;
		cout<<"\nStarting conversion......\n";
		myNFA.Convert();
		cout<<endl<<endl<<"         Conversion finished."<<endl<<endl;
		goto a;
    }
    else
    {
      cout<<"\nYou have entered a Principle State's name. \n";
	  Principle = atoi(Input.c_str());
      myNFA.Q.insert(Principle);
      myNFA.Principles.insert(Principle);
    }
    cout<<"\nNow insert an input symbol : \n";
	cin >> Symbol; 
	if(cin.eof()) break;
    if(Symbol =="epsilon") Symbol[0]= '\0';    // epsilon
    
    cout<<"\nNow insert a Destination State's name : \n";
    cin >> Destination;     
	if(cin.eof()) break;
    myNFA.Q.insert(Destination);
    myNFA.Destinations.insert(Destination);
    myNFA.Delta.push_back(transition(Principle, Symbol[0], Destination));
    cout<<endl<<"The transition is : "<<Principle<<"-"<<Symbol[0]<<"->"<<Destination<<endl;
  }
       Exit:;
  
  
}