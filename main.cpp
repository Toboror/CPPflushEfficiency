#include <iostream>
#include <vector>
#include <chrono>

void withoutFlush(int length, int xLines){

    using namespace std::chrono;

    std::pmr::vector<long long> timeTaken = {};

    for (int j = 0; j < length; j++) {

        auto start = high_resolution_clock::now();

        for (int i = 0; i < xLines; i++) {
            std::cout << "This is some text without flushing the buffer.\n";
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

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

void withFlush(int length, int xLines){
    using namespace std::chrono;

    std::pmr::vector<long long> timeTaken = {};

    for (int j = 0; j < length; j++) {

        auto start = high_resolution_clock::now();

        for (int i = 0; i < xLines; i++) {
            std::cout << "This is some text with flushing the buffer." << std::endl;
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

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

    //withoutFlush(timesToRun, xLinesInForLoop);    // Runs the simulation WITHOUT FLUSHING after every line.
    withFlush(timesToRun, xLinesInForLoop);      // Runs the simulation WITH FLUSHING after every line.

    return 0;
}
