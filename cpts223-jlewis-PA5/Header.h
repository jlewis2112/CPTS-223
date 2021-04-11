#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>          
#include <vector>         
#include <functional>     

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::deque;
using std::stringstream;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::getline;

using std::vector;
using std::string;

class job
{
public:
	job();
	job(int ticks, string desc, int procs, int left);
	~job();

	string	get_description() const;
	int get_id() const;
	int get_procs() const;
	int get_ticks() const;
	int get_left() const;

	void set_description(string newdescription);
	void set_id(int newid);
	void set_procs(int newprocs);
	void set_ticks(int newticks);
	void set_left(int left);

	void runJob();

private:
	string description;
	int ID;
	int n_procs;
	int n_ticks;
	int ticksleft;


};

struct compare
{
	bool operator()(const job& l, const job& r)
	{
		return l.get_left() > r.get_left();
	}
};


class company
{
public:
	company();
	company(int proccessors);
	~company();

	int getProcessors();
	int getProcessorsAvaliable();
	deque<job> getActiveQueue();
	priority_queue<job, vector<job>, compare> getWaitingQueue();

	void setProcessors(int proc);
	void setProcessorsAvaliable(int proc);
	void setActiveQueue(deque<job> active);
	void setWaitingQueue(priority_queue<job, vector<job>, compare> waiting);

	bool queueempty();
	bool insertJob(job newActive);
	bool insertJob(string description, int processors, int ticks);
	void tick();//returns true if job valid
	void tickNoPrompt();//returns true if jobs remaining
	void tickFromFile(fstream  * file);
	void findShortest();
	void DeleteShortest();
	bool CheckAvailability();
	void DecrementTimer();
	void ReleaseProcs();


private:
	int processors;
	int processorPool;
	deque<job> activeJobs;
	priority_queue<job, vector<job>, compare> waitingJobs;

};