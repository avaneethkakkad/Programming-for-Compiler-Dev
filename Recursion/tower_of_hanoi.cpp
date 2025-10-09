#include <iostream>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 1) {
        //    cout << "Move disc 1 from rod " << from << " to rod " << to << endl;
            return 1;
        }

        int count = 0;
        count += towerOfHanoi(n - 1, from, aux, to); // Move n-1 disks to auxiliary
       // cout << "Move disc " << n << " from rod " << from << " to rod " << to << endl;
        count += 1;
        count += towerOfHanoi(n - 1, aux, to, from); // Move n-1 disks to destination

        return count;
    }
};
