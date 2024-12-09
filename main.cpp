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

    long long averageTime = totalTime / timeTaken.size();

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

    long long averageTime = totalTime / timeTaken.size();

    std::cout << "Average time is: " << averageTime << "ms" << std::endl;
}

int main(){

    // Amount of lines in total is (timesToRun * xLinesInForLoop).
    // It has a time complexity of O(n^2), because for every run it has to go through 2 for-loops.
    const int timesToRun = 10000;     // Decides how many times to simulate the written lines.
    const int xLinesInForLoop = 10000;    // Decides how many lines to write per simulation.

    const int* ptrTimesToRun = &timesToRun;   // Pointer which points to the mem address for the var deciding x times to run.
    const int* ptrXlines = &xLinesInForLoop;  // Pointer which points to the mem address for the var deciding x lines to simulate.

    //withoutFlush(timesToRun, xLinesInForLoop);    // Runs the simulation WITHOUT FLUSHING after every line.
    withFlush(*ptrTimesToRun, *ptrXlines);      // Runs the simulation WITH FLUSHING after every line.

    return 0;
}
