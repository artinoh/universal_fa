#pragma once
#include "FiniteAutomata.h"

/*
Builder class for FiniteAutomata.
*/

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
    FiniteAutomataBuilder& set_alphabet(const std::vector<char>& alphabet);
    FiniteAutomataBuilder& set_test_strings(const std::vector<std::string>& test_strings);
    FiniteAutomataBuilder& set_name(const std::string& name);
    FiniteAutomataBuilder& set_description(const std::string& description);
    FiniteAutomata build() const;

private:
    FiniteAutomata m_fa;
};
}