/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Kaih White

   Modified: 4/24/2021
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <string>
#include <vector>
#include <map>
#include "model.h"

using namespace std;

class map_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    string to_string();

protected:
    map<string, vector<string>> m;
    string seed;
};

#endif
