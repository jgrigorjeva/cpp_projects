#include "Span.hpp"
#include "Colors.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int main()
{
    std::cout << BG "*** constructor test ***\n" RST;
    std::cout << BB "Empty span\n" RST;
    Span empty;
    empty.print();

    std::cout << BB "Random span (max 10 elements)\n" RST;
    Span random(10);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        random.addNumber(rand() % 1000);
    }
    random.print();
    
    std::cout << BB "Copy of random span\n" RST;
    Span random_copy(random);
    random_copy.print();

    std::cout << BB "Copy assignment of random span\n" RST;
    Span random_assigned;
    random_assigned = random;
    random_assigned.print();

    std::cout << BG "*** Member functions test ***\n" RST;
    std::cout << BB "Add multiple elements to a new span\n" RST;
    Span larger_span(100);
    while (larger_span.size() < 100)
        larger_span.addNumbers(10, rand() % 100);
    larger_span.print();
   
    std::cout << BB "Longest and shortest span (on random span)\n" RST;
    std::cout << "shortest span: " << random.shortestSpan() << std::endl;
    std::cout << "longest span: " << random.longestSpan() << std::endl;

    std::cout << BG "*** Exceptions ***\n" RST;
    try
    {
        random.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        empty.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BG "*** Large span (10 001 number)\n" RST;
    Span bigSpan(10001);
    while (bigSpan.size() < 10000)
        bigSpan.addNumbers(100, rand() % 1000);
    bigSpan.addNumber(-10);
    std::cout << BOLD "test exception: \n" RST;
    try
    {
       bigSpan.addNumbers(10, -200);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longest span: " << bigSpan.longestSpan() << std::endl;
    
}