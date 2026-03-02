#include "PmergeMe.hpp"

#include <cmath> //for ceil()
#include <iostream>

extern volatile int g_count;


std::vector<int> sortVector(std::vector<int> &unsorted)
{
    std::vector<int> indices = getSortedIndicesVec(unsorted);
    std::vector<int> sorted = sortWithIndices(unsorted, indices);
    return sorted;
}
std::deque<int> sortDeque(std::deque<int> &unsorted)
{
    std::deque<int> indices = getSortedIndicesDeque(unsorted);
    std::deque<int> sorted = sortWithIndices(unsorted, indices);
    return sorted;
}
std::vector<int> getSortedIndicesVec(std::vector<int> &unsorted)
{

    // std::vector<std::pair<int, int> >    unsorted_vop = 
    // std::vector<int> sorted_indices;

    // printContainerSingles(unsorted, "the unsorted vector is: ");
    // int size = (int)(ceil((float)(unsorted.size() / 2.)));
    // std::cout << "unsorted size: " << unsorted.size() << ", new vector size: " << size<<std::endl;

    std::vector<int> sorted;
    if (unsorted.size() == 1)
    {
        sorted.push_back(0);
        return sorted;
    }
    else if (unsorted.size() == 2)
    {
        if (unsorted[0] < unsorted[1])
        {
            sorted.push_back(0);
            sorted.push_back(1);
        }
        else
        {
            sorted.push_back(1);
            sorted.push_back(0);
        }
        DEBUG_COUNT(g_count++);
        return sorted;
    }
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > to_sort = fillPairs<std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > >(unsorted);
    // printPPCont(to_sort, "pairs before sorting: ");
    // sort first elements of pairs that are != -1
    std::vector<int> firsts;
    for (unsigned int i = 0; i < to_sort.size(); i++)
    {
        if (to_sort[i].first.first != -1)
            firsts.push_back(to_sort[i].first.first);
    }


    std::vector<int> sorted_firsts = getSortedIndicesVec(firsts);
    // printContainerSingles(sorted_firsts, "The sorted firsts are: ");
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > sorted_pairs = sortWithIndices(to_sort, sorted_firsts);
    // printPPCont(sorted_pairs, "sorted pairs: ");

    // std::cout << "*** Now doing the insertions ***" << std::endl;
    // calculate Jacobstahl numbers 
    std::vector<int> JIndexes = getJIndexes<std::vector<int> >(sorted_pairs.size());
    // printContainerSingles(JIndexes, "The Jacobstahl sequence is: ");
    // updateJacobstahl<std::vector<int> > (3, JIndexes, 2);
    // printContainerSingles(JIndexes, "The Jacobstahl sequence is: ");
    insertionSort(sorted_pairs, JIndexes);

    // get indexes from the sorted main chain
    for (unsigned int i = 0; i < sorted_pairs.size(); i++)
    {
        if (sorted_pairs[i].first.first != -1)
            sorted.push_back(sorted_pairs[i].first.second);
    }

    return sorted; 

}

std::deque<int> getSortedIndicesDeque(std::deque<int> &unsorted)
{

    std::deque<int> sorted;
    if (unsorted.size() == 1)
    {
        sorted.push_back(0);
        return sorted;
    }
    else if (unsorted.size() == 2)
    {
        if (unsorted[0] < unsorted[1])
        {
            sorted.push_back(0);
            sorted.push_back(1);
        }
        else
        {
            sorted.push_back(1);
            sorted.push_back(0);
        }
        DEBUG_COUNT(g_count++);
        return sorted;
    }
    std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > to_sort = fillPairs<std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > >(unsorted);
    std::deque<int> firsts;
    for (unsigned int i = 0; i < to_sort.size(); i++)
    {
        if (to_sort[i].first.first != -1)
            firsts.push_back(to_sort[i].first.first);
    }


    std::deque<int> sorted_firsts = getSortedIndicesDeque(firsts);
    std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > sorted_pairs = sortWithIndices(to_sort, sorted_firsts);
    std::deque<int> JIndexes = getJIndexes<std::deque<int> >(sorted_pairs.size());

    insertionSort(sorted_pairs, JIndexes);

    // get indexes from the sorted main chain
    for (unsigned int i = 0; i < sorted_pairs.size(); i++)
    {
        if (sorted_pairs[i].first.first != -1)
            sorted.push_back(sorted_pairs[i].first.second);
    }

    return sorted; 

}
