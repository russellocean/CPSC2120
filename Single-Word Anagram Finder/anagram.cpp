/*
 * Name: Russell Welch
 * Date Submitted: 03/16/2023
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);
vector<string> anagram(string word, vector<string> wordlist);

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

// Finds anagrams of the given word within a list of words
vector<string> anagram(string word, vector<string> wordlist) {
    unordered_map<string, vector<string>> anagram_groups;
    string sorted_target = word;
    sort(sorted_target.begin(), sorted_target.end());

    // Process each word in the list
    for (const auto& word : wordlist) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());

        // If the sorted words match, they are anagrams
        if (sorted_word == sorted_target) {
            anagram_groups[sorted_target].emplace_back(word);
        }
    }

    // Return the anagrams corresponding to the target word
    return anagram_groups[sorted_target];
}