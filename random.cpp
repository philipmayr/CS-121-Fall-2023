#include "random.h"
#include <cstdlib>

long get_random_num(long lower_bound, long upper_bound)
{
    return static_cast<long>(rand() % 
                             (upper_bound - lower_bound + 1) + 
                             lower_bound);
}
