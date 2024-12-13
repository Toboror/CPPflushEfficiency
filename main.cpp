#include <iostream>
#include <vector>
#include <chrono>

void runSimulation(int length, int xLines, int state){

    using namespace std::chrono;

    std::pmr::vector<long long> timeTaken = {};

    for (int j = 0; j < length; j++) {
        // Starts the timer.
        auto start = high_resolution_clock::now();
        for (int i = 0; i < xLines; i++) {
                if (state == 1) {
                    std::cout << "This is some text without flushing the buffer.\n";
                } else if (state == 2){
                    std::cout << "This is some text with flushing the buffer." << std::endl;
                } else {
                    std::cout << "Invalid state.";
                    break;
                }
            }

        // Stops the timer and gets the duration by getting the difference between the start and stop time.
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // Adds the duration in the vector.
        timeTaken.push_back(duration.count());

        }


    long long totalTime = 0;

    for (const auto& time : timeTaken) {
        totalTime += time;
    }

    /* long long guarantees same amounts of bits on both 32- and 64-bit systems.
     * const unsigned long long, because it is never supposed to have a negative number.
     * Calculates the time based on the total amount of time all the simulaitons took and divides
     * it by the number of simulations ran. Then you get how much time one simulation took, and then
     * you take the average of all those times and store it in the averageTime var.
    */
    const unsigned long long averageTime = totalTime / timeTaken.size();

    std::cout << "Average time is: " << averageTime << "ms" << std::endl;

}

int main(){

    const int timesToRun = 10000;     // Decides how many times to simulate the written lines.
    const int xLinesInForLoop = 10000;    // Decides how many lines to write per simulation.

    // If state = 1, run the sim without flush. If state = 2, run with flush.
    runSimulation(timesToRun, xLinesInForLoop, 1);

    return 0;
}