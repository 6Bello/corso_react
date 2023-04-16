#include <iostream>
using namespace std;

int FloydAlgorithm(int nums[]){
    int tartoise=0;
    int hare=0;
    while(true) {
        tartoise = nums[tartoise];
        hare = nums[nums[hare]];
        if(tartoise==hare) break;
	}
    tartoise = 0;
    while (tartoise != hare) {
        tartoise = nums[tartoise];
        hare = nums[hare];
    }
    return hare;
}