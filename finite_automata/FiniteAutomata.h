#pragma once
#include <iostream>
#include <unordered_map>

namespace universal_fa
{
using transition_map = std::unordered_map<char, int>;

class FiniteAutomata
{
public:
    FiniteAutomata() { std::cout << "I am a finite automata being born" << std::endl;}
    ~FiniteAutomata() = default;

    bool process_string(const std::string& input_string);

    void set_initial_state(int state);
    void set_transition(int from_state, char symbol, int to_state);
    void set_final_state(int state, bool is_final);
    void set_alphabet(char symbol, int index);

private:
    int m_initial_state;
    std::unordered_map<int, transition_map> m_transitions;
    std::unordered_map<int, bool> m_final_states;
    std::unordered_map<char, int> m_alphabet;
};
}