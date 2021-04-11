#include"Header.h"

////////////////////////////Job Functions
job :: job(){
	description = " ";
	n_procs = 0;
	n_ticks = 0;
	ticksleft = 0;
}
job ::  job(int ticks, string desc, int procs, int left){
	description = desc;
	n_procs = procs;
	n_ticks = ticks;
	ticksleft = left;
}
job :: ~job(){
}

string job::get_description() const{
	return description;
}
int job::get_procs() const{
	return n_procs;
}
int job::get_ticks() const{
	return n_ticks;
}
int job::get_left() const{
	return ticksleft;
}
int job::get_id() const {
	return this->ID;
}

void job :: set_left(int left){
	ticksleft = left;
}
void job::set_description(string newdescription){
	description = newdescription;
}
void job::set_procs(int newprocs){
	n_procs = newprocs;
}
void job::set_ticks(int newticks){
	n_ticks = newticks;
}
void job::set_id(int newid) {
	this->ID = newid;
}

void job::runJob() {//constant
	this->ticksleft--;
}
////////////////////////////////////Company Functions
company::company() {
	this->processors = 0;
	this->processorPool = 0;
}
company::company(int proccessors) {
	this->processors = proccessors;
	this->processorPool = proccessors;
}
company::~company() {
	this->activeJobs.clear();
	while (this->waitingJobs.empty() == false)
	{
		this->waitingJobs.pop();
	}
}

int company::getProcessors() {
	return this->processors;
}
int company::getProcessorsAvaliable() {
	return this->processorPool;
}
deque<job> company::getActiveQueue() {
	return this->activeJobs;
}
priority_queue<job, vector<job>, compare> company::getWaitingQueue() {
	return this->waitingJobs;
}

void company::setProcessors(int proc) {
	this->processors = proc;
}
void company::setProcessorsAvaliable(int proc) {
	this->processorPool = proc;
}
void company::setActiveQueue(deque<job> active) {
	this->activeJobs.clear();
	this->activeJobs = active;
}
void company::setWaitingQueue(priority_queue<job, vector<job>, compare> waiting) {
	while (this->waitingJobs.empty() == false)
	{
		this->waitingJobs.pop();
	}
	this->waitingJobs = waiting;
}

bool company::queueempty() {
	if (this->activeJobs.empty() == true && this->waitingJobs.empty() == true)//if both queues are empty
	{
		return true;
	}
	else//there is a job running or waiting
	{
		return false;
	}
}
bool company::insertJob(string description, int processors, int ticks) {
	static int id = 1;//static  to maintain value for consecutive  runs
	job temp = job(ticks, description, processors, ticks);
	if (this->processors < processors)//if there are not enough processors (total, not currently avaliable) to handle job
	{
		cout << "ERROR attempting to insert job " << id << " proccessors required more than total processors!\n";
		id++;
		return false;
	}
	else//there are enough processors to handle job eventually
	{
		temp.set_id(id);
		cout << "Inserted job " << id << " into waiting queue.\n";
		id++;
		this->waitingJobs.push(temp);
		return true;
	}
}
bool company::insertJob(job newActive) {//only used from findShortest to insert top wait to active
	this->activeJobs.push_back(newActive);
	return true;
}
void company::tick() {//user input variant
	string description = "";
	int processors = 0, ticks = 0;
	cout << "Type new job description. (\"exit\" to stop)\n";//PROMPT
	cin >> description;
	if (description == "exit")//if they stop inputing jobs
	{
		while (this->queueempty() == false)//run tick without input until both queues are empty
		{
			this->tickNoPrompt();
		}
	}
	else//they input a new job
	{
		cout << "Type numeric value of processors required\n";
		cin >> processors;
		cout << "Type numeric value of ticks required\n";
		cin >> ticks;
		this->insertJob(description, processors, ticks);//insert new job to waiting
		this->DecrementTimer();//decrement active jobs
		this->ReleaseProcs();//remove finished jobs
		this->findShortest();//move jobs if valid to active
	}
}
void company::tickNoPrompt() {
	this->DecrementTimer();//decrement active jobs
	this->ReleaseProcs();//remove finished jobs
	this->findShortest();//move jobs if valid to active
}
void company::tickFromFile(fstream  * file) {
	
	string description = "";
	string templine = "";
	int processors = 0, ticks = 0;
	
	if (!(*file).eof())//if there are lines left
	{
		getline((*file), description, ' ');
		(*file) >> processors;
		getline((*file), templine);
		ticks = stoi(templine);
		this->insertJob(description, processors, ticks);//insert new job to waiting queue
		this->DecrementTimer();//decrement active jobs
		this->ReleaseProcs();//remove finished jobs
		this->findShortest();//move jobs if valid to active
	}
	else//file is done reading
	{
		while (this->queueempty() == false)//until both queues are empty run tick without input
		{
			this->tickNoPrompt();
		}
	}
}
void company::findShortest() {//linear worst case
	if (this->CheckAvailability())//if there are enough processors to insert top of waiting to active queue
	{
		this->processorPool = this->processorPool - this->waitingJobs.top().get_procs();//remove processors required for new active job
		this->insertJob(waitingJobs.top());//insert job to active queue
		cout << "Job " << waitingJobs.top().get_id() <<" D:" << waitingJobs.top().get_description() << " P:" << waitingJobs.top().get_procs() << " T:" << waitingJobs.top().get_ticks() << " moved to active queue.\n";
		DeleteShortest();//remove job from waiting queue
	}
}
void company::DeleteShortest() {//constant
	this->waitingJobs.pop();//remove shortest from waiting
}
bool company::CheckAvailability() {//constant
	if (this->waitingJobs.empty() == false && this->waitingJobs.top().get_procs() <= this->processorPool)//if there are enough processors to insert top of waiting to active queue
	{
		return true;
	}
	else
	{
		return false;
	}
}
void company::DecrementTimer() {
	for (int i = 0; i < this->activeJobs.size(); i++)//DECREMENT all ticks left by invoking runJob on all jobs
	{
		this->activeJobs.at(i).runJob();
	}
}
void company::ReleaseProcs() {
	vector<deque<job>::iterator> deletions;//vector of deletions
	for (deque<job>::iterator i = this->activeJobs.begin(); i < this->activeJobs.end(); i++)//marks all empty jobs for deletion
	{
		if (i->get_left() == 0)//if job completed
		{
			deletions.push_back(i);
		}
	}
	for (int i = deletions.size() - 1; i >= 0; i--)//REMOVE //deletes from active jobs last to first to ensure indecies stay at the correct value
	{
		cout << "Job " << deletions.at(i)->get_id() << " D:" << deletions.at(i)->get_description() << " P:" << deletions.at(i)->get_procs() << " T:" << deletions.at(i)->get_ticks() << " completed.\n";
		this->processorPool = this->processorPool + deletions.at(i)->get_procs();//put processors back to processor Pool
		this->activeJobs.erase(deletions.at(i));
	}
}