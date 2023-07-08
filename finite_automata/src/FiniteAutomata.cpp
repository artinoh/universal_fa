#include "../FiniteAutomata.h"

namespace universal_fa
{

void FiniteAutomata::add_initial_state(int state)
{
    m_initial_state = state;
}
void FiniteAutomata::add_transition(int from_state, char symbol, int to_state)
{
    m_transitions[from_state][symbol] = to_state;
}
void FiniteAutomata::add_final_state(int state, bool is_final)
{
    m_final_states[state] = is_final;
}
void FiniteAutomata::add_alphabet(char symbol)
{
    m_alphabet.insert(symbol);
}

void FiniteAutomata::add_test_string(const std::string& str)
{
    m_test_strings.push_back(str);
}

bool FiniteAutomata::process_string(const std::string& str)
{
    int current_state = m_initial_state;

    for (const char& c : str) {
        // Check if the character is in the alphabet
        if (m_alphabet.find(c) == m_alphabet.end()) {
            std::cout << "Character '" << c << "' is not in the automata's alphabet ";
            return false;
        }

        // Check if there is a transition from the current state with the current symbol
        auto it = m_transitions.find(current_state);
        if (it == m_transitions.end()) {
            std::cout << "No transition from state " << current_state << " with symbol '" << c << "'";
            return false;
        }

        // Get the transition map for the current state
        transition_map& state_transitions = it->second;

        // Check if there is a transition with the current symbol
        auto trans_it = state_transitions.find(c);
        if (trans_it == state_transitions.end()) {
            std::cout << "No transition from state " << current_state << " with symbol '" << c << "'";
            return false;
        }

        // Move to the next state
        current_state = trans_it->second;
    }

    // After processing the string, check if we are in a final state
    auto final_it = m_final_states.find(current_state);
    if (final_it == m_final_states.end() || final_it->second == false) {
        std::cout << "The string ended in a non-final state: " << current_state;
        return false;
    }

    // If we've reached this point, the string is accepted by the automata
    return true;
}

void FiniteAutomata::set_name(const std::string& name)
{
    m_name = name;
}

void FiniteAutomata::set_description(const std::string& description)
{
    m_description = description;
}

std::string FiniteAutomata::get_name() const
{
    return m_name;
}

std::string FiniteAutomata::get_description() const
{
    return m_description;
}

void FiniteAutomata::process()
{
    for (const auto& str : m_test_strings)
    {
        std::cout << m_name << " processing string:" << str << " " << (process_string(str) ? "   >>> accepted <<<" : "   >>> rejected <<<") << std::endl;
    }
}
}