#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "HashTable.h"

using namespace std;
using namespace chrono;

void get_min_max_chain_length_hashtable(mt19937 gen,  uniform_int_distribution<> unif_distr){
    for (int i = 3; i < 7; i++) {
        int N = pow(10, i);
        int table_size = N / 100;
        HashTable* hashTable = new HashTable(table_size);

        cout << "N: " << N << endl;
        cout << "Size of the table: " << table_size << endl;

        for (int j = 0; j < N; j++) {
            hashTable->put_value(unif_distr(gen)); // // pass the generator to the distribution.
        }
        hashTable->get_max_min_length_hashtable();
        delete hashTable;
        cout << endl;
    }
}
void get_avg_insert_time(int N, mt19937 gen, uniform_int_distribution<> unif_distr) {

    int table_size = N / 100;
    int num_experiments = 10;
    double avg_insert_time = 0;
    HashTable* hashTable;

    cout << "N: " << N << endl;
    cout << "Size of the table: " << table_size << endl;

    for (int i = 0; i < num_experiments; i++) {
        hashTable = new HashTable(table_size);

        int* random_numbers_array = new int[N];

        for (int j = 0; j < N; j++) {
            random_numbers_array[j] = unif_distr(gen);
        }

        high_resolution_clock::time_point start = high_resolution_clock::now();
        for (int j = 0; j < N; j++) {
            hashTable->put_value(random_numbers_array[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double, std::micro> microseconds_time = end - start;
        avg_insert_time = avg_insert_time + microseconds_time.count();

        delete[] random_numbers_array;
        delete hashTable;
    }

    avg_insert_time = avg_insert_time/(num_experiments * N);

    cout << "Average time of insertion into hashtable is " << avg_insert_time << " microseconds." << endl;
    cout << endl;
}

int main()
{
    random_device rand_dev; // non-deterministic generator
    mt19937 gen(rand_dev());  // to seed mersenne twister
    uniform_int_distribution<> unif_distr(0, INT_MAX); // distribute results between 1 and 6 inclusive

    get_min_max_chain_length_hashtable(gen, unif_distr);

    for(int i = 3; i < 7; i++) {
        get_avg_insert_time(pow(10, i), gen, unif_distr);
    }

    return 0;
}

