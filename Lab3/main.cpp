#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "BloomFilter.h"

using namespace std;
using namespace chrono;

int  main()
{
    BloomFilter bf;
    fstream newfile;
    ofstream outfile;
    int num_experiments = 10;
    double avg_insert_time = 0;

    for (int i = 0; i < num_experiments; i++) {
        newfile.open("/Users/victoria/Documents/CLionProjects/Lab3/in.txt");
        outfile.open("/Users/victoria/Documents/CLionProjects/Lab3/out.txt");
        high_resolution_clock::time_point start = high_resolution_clock::now();
        if (newfile.is_open()) //checking whether the file is open
        {
            string s;
            while (getline(newfile, s)) {
                if (s.substr(0, 1) == "+") {
                    string input_string = s.substr(2);
                    bf.insert(input_string);
                }
                if (s.substr(0, 1) == "?") {
                    string input_string = s.substr(2);
                    if (bf.contains(input_string)) {
                        outfile << input_string << " Y" << endl;
                    } else {
                        outfile << input_string << " N" << endl;
                    }
                }
            }
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double, std::milli> milliseconds_time = end - start;
        avg_insert_time = avg_insert_time + milliseconds_time.count();

        newfile.close();
        outfile.close();
    }
    avg_insert_time = avg_insert_time/(num_experiments);
    cout << "Average time of insertion into hashtable is " << avg_insert_time << " milliseconds." << endl;
    cout << endl;

}
