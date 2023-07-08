#include "../FiniteAutomata.h"

namespace universal_fa
{

void FiniteAutomata::set_initial_state(int state)
{
    m_initial_state = state;
}
void FiniteAutomata::set_transition(int from_state, char symbol, int to_state)
{
    m_transitions[from_state][symbol] = to_state;
}
void FiniteAutomata::set_final_state(int state, bool is_final)
{
    m_final_states[state] = is_final;
}
void FiniteAutomata::set_alphabet(char symbol, int index)
{
    m_alphabet[symbol] = index;
}

bool FiniteAutomata::process_string(const std::string& str)
{
    return true;
}

}