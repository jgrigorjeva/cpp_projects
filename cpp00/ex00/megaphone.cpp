#include <iostream>
#include  <cctype>

using std::cout;

char my_toupper(char ch);
void my_printchar(char ch);

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        int j = 0;
		while (argv[i][j])
		{
			my_printchar(argv[i][j]);
			j++;
		}
    }
	cout << std::endl;
   return 0;
}

char my_toupper(char ch)
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

void my_printchar(char ch)
{
    cout << my_toupper(ch);
}