#include "../FiniteAutomataBuilder.h"

namespace universal_fa
{

FiniteAutomataBuilder& FiniteAutomataBuilder::set_initial_state(int state)
    {
        m_fa.set_initial_state(state);
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_transitions(const std::unordered_map<int, transition_map>& transitions)
    {
        for (const auto& [from_state, transition] : transitions)
        {
            for (const auto& [symbol, to_state] : transition)
            {
                m_fa.set_transition(from_state, symbol, to_state);
            }
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_final_states(const std::unordered_map<int, bool>& final_states)
    {
        for (const auto& [state, is_final] : final_states)
        {
            m_fa.set_final_state(state, is_final);
        }
        return *this;
    }

    FiniteAutomataBuilder& FiniteAutomataBuilder::set_alphabet(const std::unordered_map<char, int>& alphabet)
    {
        for (const auto& [symbol, index] : alphabet)
        {
            m_fa.set_alphabet(symbol, index);
        }
        return *this;
    }

    FiniteAutomata FiniteAutomataBuilder::build() const
    {
        return m_fa;
    }

}