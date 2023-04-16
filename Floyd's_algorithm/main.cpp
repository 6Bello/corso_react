#include <iostream>
#include "librerie\FloydAlgorithm.h"

using namespace std;
int main() {
    int lenght;
    cin >> lenght;
    int nums[lenght];
    for (int i = 0; i < lenght; i++) {
        cin >> nums[i];
    }
    cout<<FloydAlgorithm(nums);
    return 0;
}
