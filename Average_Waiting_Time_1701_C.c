//1701. Average Waiting Time LeetCode (Medium Level)
// Coded by Rafi Ahmed(https://github.com/rahme007) 
#include<stdio.h>
#include<stdlib.h>


double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    double avg = customers[0][1];
    double sumTime = customers[0][0] + customers[0][1];
    for (int i = 1; i < customersSize;i++) {

        // if chef is not waiting then he will follow this if condition
        if (sumTime > customers[i][0]) {
            sumTime = sumTime + customers[i][1];
            avg += sumTime - customers[i][0];
        }
        
        // if chef is idle for at least 1 unit of time, he follows this else condition
        else {
            avg += customers[i][1];
            sumTime = customers[i][0] + customers[i][1];
        }

    }
    avg = avg / customersSize;

    return avg;
}


int main() {

    int customers[6][2] = { {2,3} ,{6,3},{7,5},{11,3},{15,2},{18,1} };
    int customersColSize = 2;

    int* customersPtr[6];

    for (int i = 0; i < 6; i++) {
        customersPtr[i] = customers[i];
    }
    double avg = averageWaitingTime(customersPtr, 6, &customersColSize);

    printf("%lf\n", avg);

    return 0;
}