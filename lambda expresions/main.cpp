/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jim_4067
 *
 * Created on August 1, 2020, 12:44 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
 * 
 */

std::vector<int> generate_random_num(int num_of_nums, int min, int max);

int main() {

    std::vector<int> rand_vec = generate_random_num(10, 10, 50);

    std::sort(rand_vec.begin(), rand_vec.end(),
            [] (int x, int y) {
                return x < y;
            });
    for (auto index : rand_vec) {
        std::cout << index << "\t";
    }

    //copy_if similar to filter in JS
    std::vector<int> even_vals;
    std::copy_if(rand_vec.begin(), rand_vec.end(),
            std::back_inserter(even_vals),
            [] (int x) {
                return (x % 2) == 0; });

    std::cout << "\neven values from above \n";
    for (auto val : even_vals) {
        std::cout << val << "\t";
    }

    //sum the values in a vector
    //the values in the brackets tell the lambda to include values from outside it
    int sum = 0;
    std::for_each(rand_vec.begin(), rand_vec.end(),
            [&] (int x) {
                return sum += x;
            });
    std::cout << "\nthe sum is : " << sum << std::endl;

    //calculating the multiplication
    std::vector<int> double_vec;
    std::for_each(rand_vec.begin(), rand_vec.end(),
            [&] (int x) {
                return double_vec.push_back(x * 2);
            });
    std::cout << "each val multiplies by two\n";
    for (auto val : double_vec) {
        std::cout << val << "\t";
    }

    std::vector<int> vec1{1, 2, 3, 4};
    std::vector<int> vec2{1, 2, 3, 4};
    std::vector<int> vec3(4);
    transform(vec1.begin(), vec1.end(), vec2.begin(),
            vec3.begin(),
            [] (int x, int y) {
                return x + y;
            });
    std::cout << "\nthe values of the addition\n";
    for (auto val : vec3) {
        std::cout << val << "\t";
    }

    int age = 18;
    bool can_i_vote = (age >= 18) ? true : false;
    std::string who_votes = (can_i_vote) ? "yes you can" : "no you cannot";
    //any value is going to be displayed as true/false instead of 1/0
    std::cout.setf(std::ios::boolalpha);
    std::cout << "\nCan Jimmy Vote ? " << can_i_vote << "\n";
    std::cout << who_votes;

    //calculating fibonaci 
    std::function<int(int) > fib =
            [&fib] (int n) {
                return n < 2 ? n : fib(n - 1) + fib(n - 2);
            };

    std::cout << "\nfib 4 : " << fib(4);
    



    return 0;
}

std::vector<int> generate_random_num(int num_of_nums, int min, int max) {
    std::vector<int> return_vec;

    srand(time(NULL));
    int index = 0;
    int random_val = 0;
    while (index < num_of_nums) {
        random_val = min + std::rand() % ((max - min) + 1);
        return_vec.push_back(random_val);

        index++;
    }

    return return_vec;
}