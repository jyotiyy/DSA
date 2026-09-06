// Job sequencing using branch and bound : The problem states that given n jobs with profits
// ,execution time and deadline, achive the shedule which maximizes the overall 
// profit 

/* 
1. maximum deadline = nymber of slots 
2. Sort jobs by profit
3. Branching (take/skip)
4. Root Node


*/

#include<bits/stdc++.h>
using namespace std;


struct Job{
    char id;
    int deadline;
    int profit;
};
int n;
vector<Job> jobs;
int bestProfit = 0;
vector<char> bestShedule;
vector<char> shedule;
void branchBound(int index,int profit){
    if(index == n){
        if(profit > bestProfit){
            bestProfit = profit;
            bestShedule = shedule;
        }
        return;
    }
    int bound = profit;// finding the upper bound
    for(int i = index; i <n; i++){
        bound+=jobs[i].profit;
    }
    //prune
    if(bound <= bestProfit){
        return;
    }


    //take the job 
    int d = jobs[index].deadline;
    int placedslot = -1;
    for(int i = d; i >= 1; i--){
        if(shedule[i] == '-'){
            shedule[i] = jobs[index].id;
            placedslot = i;
            break;
        }
    }
    if(placedslot != -1){
        branchBound(index+1,profit+jobs[index].profit);
        shedule[placedslot] = '-';
    }
    //skip
    branchBound(index+1,profit);
}
int main(){
    jobs = {
        {'A',2,60},
        {'B',1,30},
        {'C',2,40},
        {'D',3,20}
    };
    n = jobs.size();
    sort(jobs.begin(),jobs.end(),[](Job a,Job b){
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for(auto job: jobs){
        maxDeadline = max(maxDeadline,job.deadline);
    }

    shedule.resize(maxDeadline+1,'-');
    bestShedule.resize(maxDeadline,'-');

    branchBound(0,0);
    cout << "Job Sequence: ";
    for(int i = 1; i<= maxDeadline; i++){
        if(bestShedule[i] != '-'){
            cout << bestShedule[i] << " ";
        }
    }
    cout << "\nMaximum Profit: " << bestProfit << "\n";
}