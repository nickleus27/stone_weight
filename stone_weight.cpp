#include <queue> // for priority queue
#include <vector> // for vector
#include <iostream> // for cout and cin
#include <string> // for string
#include <sstream> // for istringstream

class Solution {
public:
    inline int poptop(std::priority_queue<int>* heap)
    {
        int top = heap->top();
        heap->pop();
        return top;
    }
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxheap(stones.begin(), stones.end()); // builds a max heap O(n)
        while (maxheap.size() > 1)
        {
            // grab the two heaviest stones
            // the max stones guaranteed to be at top
            // and after every pop, the next stone will be max at top
            int stone1 = poptop(&maxheap);
            int stone2 = poptop(&maxheap);
            int smash = stone1 - stone2;
            if (smash)
            {
                maxheap.push(smash); // add what is left from the smash back into the max heap
            }
        }
        // all the stones are smashed (except possibly 1)
        return maxheap.size() ? maxheap.top() : 0;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v;
    std::string line;
    int number;
    std::cout << "To play Last Stone Weight," << std::endl;
    std::cout << "Enter an array of numbers with each number seperated by white space: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
    {
        v.push_back(number);
    }
    std::cout << "Playing game with vector: [ ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;
    std::cout << "Weight of last remaining stone: " << sol.lastStoneWeight(v) << std::endl;
    return 0;
}