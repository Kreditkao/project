#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


struct Product {
    string name;
    double price;
};

bool compareProducts(const Product& a, const Product& b) {
    return a.price < b.price;
}

