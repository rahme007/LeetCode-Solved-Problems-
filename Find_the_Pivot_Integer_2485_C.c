#include<stdio.h>


int pivotInteger(int n) {
    int x = n;

    while (x>0) {
        int diff = n - x + 1;
        int sum1 = ((diff)*(2*x +(diff-1)))/2; //arithmetic sum from an integer x 
        int sum2 = (x*(x+1))/2; // arithmetic sum from 1 to x
        if (sum1 == sum2)
            return x;
        x--;
    }
    return -1;
    
}

int main() {

    int n = 8;
    int pivotInt = pivotInteger(n);
    printf("%d\n", pivotInt);
    return 0;
}