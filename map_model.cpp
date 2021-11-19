/*
   CmI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Kaih White

   Modified: 4/24/2021
*/

#include "map_model.h"
#include <iostream>

using namespace std;

void map_model::initialize(string text, int order) {
    if(order == 1) {
        int random = rand() % text.size();
        for (int i = 0; i < text.size() - 1; i++) {
            if(i == random){seed = string(1, text[i]);}
            if (m.count(string(1, text[i]))) {
                m[string(1, text[i])].push_back(string(1, text[i+1]));
            }
            else{
                m.insert(pair<string, vector<string>> (string(1, text[i]),{string(1, text[i+1])}));
            }
        }
    }
    else{
        int random = rand() % (text.size() - order);
        for (int i = 0; i < text.size() - order; i++) {
            string item = text.substr(i, order);
            if(i == random){seed = item;}
            if (m.count(item)){
                m[item].push_back(string(1, text[i+order]));
            }
            else{
                m.insert(pair<string, vector<string>> (item,{string(1, text[i+order])}));
            }
        }
    }
}

string map_model::generate(int size) {
    string fin = "";
    for(int i = 0; i < size; i++){
        int ran = rand() % m[seed].size();
        string nextc = m[seed][ran];
        fin += nextc;
        seed = seed.substr(1, seed.size() - 1) + nextc;
    }
    return fin;
}
