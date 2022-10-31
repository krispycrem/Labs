#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <fstream>
#include <chrono>
#include <vector>
#include <fstream>

#include "HashMap.h"

using namespace std;
using namespace chrono;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, left = 0, right = 0; i < n; ++i) {
        if (i <= right)
            z[i] = min (right - i + 1, z[i - left]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > right)
            left = i, right = i + z[i] - 1;
    }
    return z;
}

int main() {
    HashMap* hmap;
    int tableSize = 100000;
    hmap = new HashMap(tableSize);

    fstream newfile;
    newfile.open("/Users/victoria/Documents/CLionProjects/lab2/in.txt");
    high_resolution_clock::time_point start = high_resolution_clock::now();
    if(newfile.is_open()) //checking whether the file is open
    {
        string s;
        while(getline(newfile, s)){ //read data from file object and put it into string.

            if(s.substr(0, 1) == "+"){
                hmap->insert_value(s.substr(2));
                vector<int> res_z_func =  z_function(s.substr(2));
                /*cout<<"result ";
                for (auto v : res_z_func){
                    cout<<v<<" ";
                }*/
            }
            if(s.substr(0, 1) == "-"){
                hmap->delete_value(s.substr(2));
                vector<int> res_z_func =  z_function(s.substr(2));

                /*cout<<"result ";
                for (auto v : res_z_func){
                    cout<<v<<" ";
                }*/
            }
            if(s.substr(0, 1) == "?"){
                hmap->search_value(s.substr(2));
                vector<int> res_z_func =  z_function(s.substr(2));

                /*cout<<"result ";
                for (auto v : res_z_func){
                    cout<<v<<" ";
                }*/
            }
        }
        newfile.close(); //close the file object.
    }
    delete hmap;
}
