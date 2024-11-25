#include <iostream>
#include <vector>
#include <chrono>
#include <memory_resource>

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

    int timesToRun = 10000;
    int xLinesInForLoop = 10000;

    //withoutFlush(timesToRun, xLinesInForLoop);
    withFlush(timesToRun, xLinesInForLoop);



    return 0;
}
