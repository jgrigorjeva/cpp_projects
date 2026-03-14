#ifndef PMERGEME
#define PMERGEME

#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <set>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iterator>
#include <algorithm>

#ifdef DEBUG
# define DEBUG_COUNT(x) x
# define DEBUG_PRINT(x) x
#else
# define DEBUG_COUNT(x)
# define DEBUG_PRINT(x)
#endif

extern volatile int g_count;

// input validation
bool parseInput(char *arg, std::vector<int> &sequence);
bool inputInvalid(std::vector<int> sequence);
bool duplicatesFound(std::vector<int> sequence);

template <typename T>
void printContainerSingles(T sequence, std::string msg="")
{
    std::cout << msg;
    int i = 1;
    bool shorten = false;
    if (sequence.size() > 5)
        shorten = true;
    #ifdef DEBUG
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    (void)i;
    (void)shorten;
    #else
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        if (shorten && i > 4)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        i++;
    }
    #endif
    std::cout << std::endl;
}

std::vector<int> sortVector(std::vector<int> &unsorted);
std::vector<int> getSortedIndicesVec(std::vector<int> &unsorted);

std::deque<int> sortDeque(std::deque<int> &unsorted);
std::deque<int> getSortedIndicesDeque(std::deque<int> &unsorted);

template <typename T>
int findPosition(T& to_sort, int b, int start, int end);


template <typename T>
std::pair<std::pair<int, int>, std::pair<int, int> > makeDoublePair(T& sequence, int index);


template <typename T, typename S>
T fillPairs(S &unsorted)
{
    T to_sort;
    int full_pair = unsorted.size() / 2;
    int half_pair = unsorted.size() % 2;
    for (int i = 0; i < full_pair; i++)
    {
        std::pair<std::pair<int, int>, std::pair<int, int> > new_pair;
        int j = 2*i;
        if (unsorted[j] > unsorted[j+1])
            new_pair = std::make_pair(std::make_pair(unsorted[j], j), std::make_pair(unsorted[j+1], j+1));
        else
            new_pair  = std::make_pair(std::make_pair(unsorted[j+1], j+1), std::make_pair(unsorted[j], j));
        DEBUG_COUNT(g_count++);
        to_sort.push_back(new_pair);
    }
    // the last pairless number
    if (half_pair)
    {
        to_sort.push_back(std::make_pair(std::make_pair(-1, -1), std::make_pair(unsorted[full_pair * 2], full_pair * 2)));
    }
    return (to_sort);
}

template <typename T, typename S>
T sortWithIndices(T &sequence, S &indices)
{
    T new_sequence;
    if (indices.size() == 1)
        return new_sequence = sequence;
    for (unsigned int i = 0; i < indices.size() && i < sequence.size(); i++)
    {
        new_sequence.push_back(sequence[indices[i]]);
    }
    if (indices.size() < sequence.size())
        new_sequence.push_back(sequence[sequence.size() - 1]);
    return new_sequence;
}

template <typename T>
void printPPCont(T cont, std::string message = "")
{
    std::cout << message;
    for (unsigned int i = 0; i < cont.size(); i++)
    {
        std::cout << "(" << cont[i].first.first << "," << cont[i].second.first << ") ";
    }
    std::cout << std::endl;
}

template <typename T>
void printPCont(T cont, std::string message = "")
{
    std::cout << message;
    for (unsigned int i = 0; i < cont.size(); i++)
    {
        std::cout << "(" << cont[i].first << "," << cont[i].second << ") ";
    }
    std::cout << std::endl;
}

template <typename T>
T getJIndexes(std::size_t max_index)
{
    T Jacobstahl;
    Jacobstahl.push_back(1);
    Jacobstahl.push_back(3);

    for (std::size_t i = 2; i < max_index; i++)
    {
        int J = Jacobstahl[i - 1] + 2*Jacobstahl[i - 2];
        Jacobstahl.push_back(J);
    }

    T indexes;
    int Ja = Jacobstahl[0];
    int Jb = Jacobstahl[1];
    int j = 1;
    indexes.push_back(Ja);
    int index = Jb;
    bool max_index_crossed = false;
    while (index > 0)
    {
        // std::cout << "index: "<< index << ", max index: " << max_index << ", Ja: " << Ja << ", Jb: " << Jb << std::endl;
        if (index > (int)max_index)
        {
            index--;
            continue;
        }
            
        if (index == (int)max_index)
            max_index_crossed = true;
        indexes.push_back(index);
        index--;
        if (index == Ja)
        {
            if (max_index_crossed)
                break;
            Ja = Jacobstahl[j];
            Jb = Jacobstahl[++j];
            index = Jb;
        }
    }
    
    return indexes;

}
template <typename T>
void updateJacobstahl(int i, T& sequence, int start)
{
    for (int j = start; j < (int)sequence.size(); j++)
    {
        if (sequence[j] >= i)
            (sequence[j])++;
        // might update the number of comparisons
    }
}

template <typename T, typename J>
void insertionSort(T& to_sort, J &JIndexes)
{
    // std::cout << "inserting: \n";
    for (int i = 0; i < (int)JIndexes.size(); i++)
    {
        int index = JIndexes[i] - 1;
        int b = to_sort[index].second.first;
        
        // std::cout << "index: " << index << ", bi: " << b << std::endl;
        if (i == 0)
        {
            to_sort.insert(to_sort.begin(), makeDoublePair(to_sort, index));
            updateJacobstahl(1, JIndexes, i + 1);
        }
        else
        {
            int position = findPosition(to_sort, b, 0, index);
            // printPPCont(to_sort, "the main sequence: \n");
            // std::cout << "insert number: " << b << " to position " << position << std::endl;
            to_sort.insert(to_sort.begin() + position, makeDoublePair(to_sort, index));
            updateJacobstahl(position + 1, JIndexes, i + 1);
            // 

        }
    }

}

// creates a double pair with the first pair taken from a container, the second pair is (-1, -1)
// the existing pair is taken from the second pair in the container
template <typename T>
std::pair<std::pair<int, int>, std::pair<int, int> > makeDoublePair(T& sequence, int index)
{
    if (index >=0 && index < (int)sequence.size())
        return std::make_pair(sequence[index].second, std::make_pair(-1,-1));
    else
        return std::make_pair(std::make_pair(-1,-1), std::make_pair(-1,-1));;
}
template <typename T>
int findPosition(T& to_sort, int b, int start, int end)
{
    
    int interval = end - start;
    int center = interval / 2 + start;
    // std::cout << "start: " << start << ", end: " << end << std::endl;
    if (interval == 0)
        return start;

    if (interval == 1)
    {
        DEBUG_COUNT(g_count++);
        if (b > to_sort[center].first.first)
            return center + 1;
        else
            return center;
    }
    DEBUG_COUNT(g_count++);
    if (b > to_sort[center].first.first)
        return findPosition<T>(to_sort, b, center + 1, end);
    else
        return findPosition<T>(to_sort, b, start, center);

}




#endif