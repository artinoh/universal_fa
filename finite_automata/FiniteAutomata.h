#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
namespace universal_fa
{
using transition_map = std::unordered_map<char, int>;

/*

This class is used to represent a finite automata. 
It has a name, description, initial state, final states, alphabet, and test strings.
It also has a method to process a string and return whether or not it is accepted by the automata.
The test strings are stored internally and can be used to test the automata via the process method.

*/


class FiniteAutomata
{
public:
    FiniteAutomata() { std::cout << "I am a finite automata being born" << std::endl;}
    ~FiniteAutomata() = default;

    void process();

    void add_initial_state(int state);
    void add_transition(int from_state, char symbol, int to_state);
    void add_final_state(int state, bool is_final);
    void add_alphabet(char symbol);
    void add_test_string(const std::string& str);
    void set_name(const std::string& name);
    void set_description(const std::string& description);

    std::string get_name() const;
    std::string get_description() const;

private:
    std::string m_name;
    std::string m_description;
    int m_initial_state;
    std::unordered_map<int, transition_map> m_transitions;
    std::unordered_map<int, bool> m_final_states;
    std::unordered_set<char> m_alphabet;
    std::vector<std::string> m_test_strings;
    bool process_string(const std::string& input_string);
};
}