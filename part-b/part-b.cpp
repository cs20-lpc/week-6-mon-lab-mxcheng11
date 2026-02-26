#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

/** 
 * Algorithm analysis:
 * 
 */
void towerHanoi(int numDisks, string source, string buffer , string target, int& numMoves)
{
    // TO DO

    // base case 
    if (numDisks == 1)
    {
        numMoves++;
        cout << "Moving Disc " << numDisks << " from " << source << " to " << target << endl;
        return;
    }

    // recursive case 
    towerHanoi(numDisks - 1, source, target, buffer, numMoves); // move n-1 disks from source to buffer

    // move biggest disk to target 
    numMoves++;
    cout << "Moving Disc " << numDisks << " from " << source << " to " << target << endl;

    // move n-1 disks from buffer to target
    towerHanoi(numDisks - 1, buffer, source, target, numMoves);

}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/


int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}
