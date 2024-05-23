#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Adding elements to the queue (FIFO)
    myQueue.push(10); // Queue now contains: 10
    myQueue.push(20); // Queue now contains: 10, 20
    myQueue.push(30); // Queue now contains: 10, 20, 30

    // Accessing and removing elements from the front of the queue
    while (!myQueue.empty()) {
        int frontElement = myQueue.front();
        std::cout << "Front element: " << frontElement << std::endl;
        myQueue.pop();
    }

    return 0;
}
