#include "../FiniteAutomataBuilder.h"

namespace universal_fa
{

FiniteAutomataBuilder& FiniteAutomataBuilder::set_initial_state(int state)
    {
        m_fa.add_initial_state(state);
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_transitions(const std::unordered_map<int, transition_map>& transitions)
    {
        for (const auto& [from_state, transition] : transitions)
        {
            for (const auto& [symbol, to_state] : transition)
            {
                m_fa.add_transition(from_state, symbol, to_state);
            }
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_final_states(const std::unordered_map<int, bool>& final_states)
    {
        for (const auto& [state, is_final] : final_states)
        {
            m_fa.add_final_state(state, is_final);
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_alphabet(const std::vector<char>& alphabet)
    {
        for (const auto& symbol : alphabet)
        {
            m_fa.add_alphabet(symbol);
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_test_strings(const std::vector<std::string>& test_strings)
    {
        for (const auto& str : test_strings)
        {
            m_fa.add_test_string(str);
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_name(const std::string& name)
    {
        m_fa.set_name(name);
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_description(const std::string& description)
    {
        m_fa.set_description(description);
        return *this;
    }

    FiniteAutomata FiniteAutomataBuilder::build() const
    {
        return m_fa;
    }

}