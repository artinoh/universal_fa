#pragma once
#include "FiniteAutomata.h"

namespace universal_fa
{
class FiniteAutomataBuilder
{
public:
    FiniteAutomataBuilder() = default;
    ~FiniteAutomataBuilder() = default;

    FiniteAutomataBuilder& set_initial_state(int state);
    FiniteAutomataBuilder& set_transitions(const std::unordered_map<int, transition_map>& transitions);
    FiniteAutomataBuilder& set_final_states(const std::unordered_map<int, bool>& final_states);
    FiniteAutomataBuilder& set_alphabet(const std::unordered_map<char, int>& alphabet);
    FiniteAutomata build() const;

private:
    FiniteAutomata m_fa;
};
}