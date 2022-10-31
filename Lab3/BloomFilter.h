#pragma once
#include<cmath>
#include<vector>
#include<string>
#include<random>
#include<ctime>


class BloomFilter {
private:
    float p = 0.01;// ймовірність хибного спрацювання
    long long n = 1E6;// кількість елементів, що зберігаються у фільтрі-множині
    int capacity = 0;
    long long m = (long long)n*log(1/p)/(log(2)*log(2)); // size of bits array
    long long l = (long long)1LL * log(1 / p) / (log(2) * 1LL) + 1; // number of hash functions
    std::vector<int> bits_arr;
    std::vector<int> seeds;
public:
    BloomFilter(){
        bits_arr.resize(m);
        for (int i=0; i < l; i++){
            int p = rand();
            if (p % 2 == 0)
                p++;
            if (p < 256) {
                p *= (256/p*2);
            }
            seeds.push_back(p);
        }
    }

    std::vector <long long> h(std::string &s) {
        std::vector<long long> res;
        srand(time(nullptr));
        for (int i=0; i < l; i++){
            long long val = s[0];
            int j = 1;
            while (j < s.size()){
                val *= seeds[i];
                val += s[j++];
                val %= m;
            }
            res.push_back(val);
        }
        return res;
    }

    bool insert(std::string& s) {
        if (capacity >= n)
            return false;
        std::vector<long long> values = h(s);
        for (int i=0; i < l; i++){
            bits_arr[values[i]] = 1;
            capacity++; //why do we need this????
        }
        return true;
    }

    bool contains(std::string& s) {
        std::vector<long long> values = h(s);
        for (int i=0; i < l; i++){
            if (bits_arr[values[i]] == 0)
                return false;
        }
        return true;
    }
};
