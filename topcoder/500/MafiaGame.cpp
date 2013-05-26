#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MafiaGame {
public:
	double probabilityToLose(int, vector <int>);
};

double MafiaGame::probabilityToLose(int N, vector <int> decisions) {
	int size = decisions.size(), i, cnt, prevcnt=-1, maxi;
	map<int, bool> vulnerable;
	map<int, bool>::iterator it1, mini;

	for(i=0; i<N; i++)
		vulnerable[i] = 1;
		
	map<int, int> votes;
	map<int, int>::iterator it;

	while(true)
	{
		cout<<"At loop start\nVulnerable: ";
		for(it1 = vulnerable.begin(); it1 != vulnerable.end(); it1++)
			cout<<(*it1).first<<" ";
		cout<<endl;

		votes.clear();
		for(it = votes.begin(); it != votes.end(); it++)
			cout<<(*it).first<<":"<<(*it).second<<" ";
		cout<<endl;
		
		for(i=0; i<size; i++)
			if(vulnerable[decisions[i]] == 1)
			{
				cout<<"Voting against: "<<decisions[i]<<endl;
				votes[decisions[i]]++;
			}

		for(i=0; i<N; i++)
			if(i >= size || vulnerable[decisions[i]] == 0)
			{
				mini = vulnerable.begin();
				cout<<"Vulnerable: ";
				for(it1 = vulnerable.begin(); it1 != vulnerable.end(); it1++)
				{
					cout<<(*it1).first<<" ";
					cout<<"Comparing votes for " << (*mini).first << " with those for " << (*it1).first <<endl;
					if(votes[(*mini).first] > votes[(*it1).first])
						mini = it1;
				}
				cout<<endl;

				cout<<"Voting against: "<<(*mini).first<<endl;
				votes[(*mini).first]++;
			}


		maxi = -1;
		for(it = votes.begin(); it != votes.end(); it++)
		{
			cout<<(*it).first<<":"<<(*it).second<<" ";
			if(maxi < (*it).second)
				maxi = (*it).second;
		}
		cout<<endl;
		cout<<"Maximum is " << maxi << endl;


		cnt = 0;
		vulnerable.clear();
		cout<<"New vulnerable: ";
		for(it = votes.begin(); it != votes.end(); it++)
			if(maxi == (*it).second)
			{
				cout<<(*it).first<<" ";
				cnt++;
				vulnerable[(*it).first] = 1;
			}
		cout<<endl;

		printf("Count is %d\n", cnt);
		printf("Previous Count is %d\n", prevcnt);
		if(cnt == prevcnt)
			return 0;

		if(cnt == 1)
			return (*votes.begin()).first;

		cout<<"At loop end:\nVulnerable: ";
		for(it1 = vulnerable.begin(); it1 != vulnerable.end(); it1++)
			cout<<(*it1).first<<" ";
		cout<<endl;

		votes.clear();
		for(it = votes.begin(); it != votes.end(); it++)
			cout<<(*it).first<<":"<<(*it).second<<" ";
		cout<<endl;
		prevcnt = cnt;
	}	
}


double test0() {
	int p0 = 3;
	int t1[] = {1, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 5;
	int t1[] = {1, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 20;
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 23;
	int t1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.14285714285714285;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
