#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct process {
	int processID;
	int processBT;
};

bool compareID(process a, process b) {
	return a.processID < b.processID;
}

bool compareByBT(process a, process b) {
	return a.processBT < b.processBT;
}

vector <int> calculateTurnaroundTime(vector <process> processes);
vector<int> calculateWaitingTime(vector<int> turnAround,vector <process> processes);
void DrawGanttChart(vector <process> processes, vector <int> turnAround);

int main() {
	int choice;
	while (true) {
		cout << "1.First Come First Served.\n";
		cout << "2.Shortest Job First.\n";
		cout << "3.Exit.\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "=====================================================\n";
		if (choice == 3) {
			break;
		}
		int num;
		cout << "Enter number of process: ";
		cin >> num;
		vector <process> processes(num);
		for (int i = 0; i < num; i++) {
			cout << "Enter the ID for process" << i + 1 << ": ";
			cin >> processes[i].processID;
			cout << "Enter the Burst time for process" << i + 1 << ": ";
			cin >> processes[i].processBT;
		}
		if (choice == 1) {
			std::sort(processes.begin(), processes.end(), compareID);
			vector <int> turnaroundTime = calculateTurnaroundTime(processes);
			vector<int> waitingTime = calculateWaitingTime(turnaroundTime, processes);
			float waitAver = 0;
			float turnaroundAver = 0;
			for (int i = 0; i < processes.size(); i++) {
				turnaroundAver += turnaroundTime[i];
				waitAver += waitingTime[i];
			}
			cout << "The process Gannt Chart is: \n";
			DrawGanttChart(processes, turnaroundTime);
			cout << "The average turnaround time for processes = ";
			cout << turnaroundAver / processes.size() << "\n";
			cout << "The average waiting time for processes = ";
			cout << waitAver / processes.size() << "\n";
		}
		else if (choice == 2) {
			std::sort(processes.begin(), processes.end(), compareByBT);
			vector <int> turnaroundTime = calculateTurnaroundTime(processes);
			vector<int> waitingTime = calculateWaitingTime(turnaroundTime, processes);
			float waitAver = 0;
			float turnaroundAver = 0;
			for (int i = 0; i < processes.size(); i++) {
				turnaroundAver += turnaroundTime[i];
				waitAver += waitingTime[i];
			}
			cout << "The process Gannt Chart is: \n";
			DrawGanttChart(processes, turnaroundTime);
			cout << "The average turnaround time for processes = ";
			cout << turnaroundAver / processes.size() << "\n";
			cout << "The average waiting time for processes = ";
			cout << waitAver / processes.size() << "\n";
			cout << "\n=================================================\n\n\n\n\n\n";
		}
	}
	
}

vector<int> calculateWaitingTime(vector <int> turnAround,vector <process> processes) {
	vector<int> waiting(processes.size());
	for (int i = 0; i < processes.size(); i++) {
		if (i == 0) {
			waiting[i] == 0;
			continue;
		}
		waiting[i] = turnAround[i] - processes[i].processBT;
	}
	return waiting;
}

vector<int> calculateTurnaroundTime(vector <process> processes) {
	vector <int> processTurnAround(processes.size());
	for (int i = 0; i < processTurnAround.size(); i++) {
		if (i == 0) {
			processTurnAround[i] = processes[i].processBT;
			continue;
		}
		processTurnAround[i] = processes[i - 1].processBT + processes[i].processBT;
	}
	return processTurnAround;
}

void DrawGanttChart(vector <process> processes, vector <int> turnAround) {
	for (int i = 0; i < processes.size(); i++) {
		cout << "   P" << processes[i].processID << "   |";
	}
	cout << "\n";
}