#include <random>
#include <ctime>
using namespace std;
mt19937_64 twister(time(NULL));
uniform_int_distribution<int> randomnum(0,2147483647);
#define rand() randomnum(twister)
