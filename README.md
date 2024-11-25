# Testing flushing the buffer in C++ compared to not flushing.

### Goal of this project:
The goal of this project was to test if always flushing the buffer after every written line is slower.

### Hypothesis: 
Flushing the buffer after every written line is slower than not flushing after writing all lines.

### Methodology:
Created two methods where one flushes after every written line and one that does not.
It runs the method 100,000 times with 10,000 lines and calculates the average time used in ms.

### Values:
Run 1: w/out flush: 6090ms, with flush: 7032ms  
Run 2: w/out flush: 6017ms, with flush: 6885ms  
Run 3: w/out flush: 6005ms, with flush: 6864ms  
Run 4: w/out flush: 5959ms, with flush: 6926ms  
Run 5: w/out flush: 6053ms, with flush: 6870ms

### Results:
The average time used for the method that does not flush after every written line is 6024.8ms.
The average time used for the method that flushes after every written line is 6915.4ms.

Without flushing, it is 12.87% faster

### Conclusion:

In conclusion, the hypothesis was correct. Flushing the buffer after every written line is slower than not flushing after writing all lines.

btw the time complexity is O(N^2), so don't do as I did and change the number of times it runs to 1,000,000.
