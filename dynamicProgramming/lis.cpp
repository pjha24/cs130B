// 1/14/22 dynamic programming practice of longest increasing subsequence 

#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int> A){
    //subproblem: make a DAG out of the sequences. the longest increasing subsequence is the longest path in the DAG
    //to find the longest increasing subsequence at an index i: add 1 to the longest increasing subquence up to i that is less than A[i](can include i as the next value in the subsequence)

    vector<int> L(A.size(), 0); 
    L[0] = 0;
    for(int i = 1; i < A.size(); i++){
        L[i] = 1;
        for(int j = 1; j < i; j++){
            if ((A[j] < A[i]) && (L[j] + 1 > L[i]))
                L[i] = 1 + L[j];
        }
    }
    //print subsequence array
    cout<<"printing subsequence arrray: " <<endl;
    for(int i = 0; i < L.size(); i++){
        cout<< L[i] << " ";
    }
    cout<<endl;
    //find max in subsequence array
    int max = 0;
    for(int i = 0; i < L.size();i++){
        if (L[i] > max)
            max = L[i];
    }
    return max;
}


int main(){
    vector <int> A;
    A.push_back(5);
    A.push_back(2);
    A.push_back(8);
    A.push_back(6);
    A.push_back(3);
    A.push_back(6);
    A.push_back(9);
    A.push_back(7);
    
    cout<< longestIncreasingSubsequence(A) <<endl;
    return 0;
}