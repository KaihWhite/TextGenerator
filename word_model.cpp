/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Kaih White

   Modified: 04/25/2021
*/

#include "word_model.h"
#include <sstream>
#include <iostream>

void word_model::initialize(string text, int order) {
    istringstream ob(text);
    string word;
    vector<string> words;
    while(ob >> word){
        words.push_back(word);
    }
    if(order == 1) {
        int random = rand() % words.size();
        for (int i = 0; i < words.size() - 1; i++) {
            if(i == random){seed = words[i];}
            if (m.count(words[i])) {
                m[words[i]].push_back(words[i+1]);
            }
            else{
                m.insert(pair<string, vector<string>> (words[i],{words[i+1]}));
            }
        }
    }
    else{
        int random = rand() % (words.size() - order);
        for (int i = 0; i < words.size() - order; i++) {
            string item = "";
            for(int j = i; j < order + i; j++){
                item += words[j];
                if(j < order + i - 1){
                    item += " ";
                }
            }
            if(i == random){seed = item;}
            if (m.count(item)){
                m[item].push_back(words[i + order]);
            }
            else{
                m.insert(pair<string, vector<string>> (item,{words[i + order]}));
            }
        }
    }
}


string word_model::generate(int size) {
    string fin = "";
    for(int i = 0; i < size; i++){
        int ran = rand() % m[seed].size();
        string nextc = m[seed][ran];
        fin += nextc + " ";
        istringstream oj(seed);
        string thing;
        int count = 0;
        seed = "";
        while(oj >> thing){
            if (count > 0){
                seed += thing + " ";
            }
            count++;
        }
        seed += nextc;
    }
    return fin;
}
