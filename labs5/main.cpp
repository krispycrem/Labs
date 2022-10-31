#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "BloomFilter.h"

using namespace std;
using namespace chrono;

int  main()
{
    
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double, std::milli> milliseconds_time = end - start;
        avg_insert_time = avg_insert_time + milliseconds_time.count();

        newfile.close();
        outfile.close();

}
