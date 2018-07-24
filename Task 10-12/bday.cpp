#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t t = time(NULL);
    tm *ts = localtime(&t);

    if (ts->tm_mon == 5 && ts->tm_mday == 23)
        cout << "Happy bday, m8!";

    return 0;
}
