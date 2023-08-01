#include "../FiniteAutomataUtilities.h"
#include "../../components/config.h"


//naked namespace to keep functions private to this file
namespace
{

/*
The alphabet is a list of ranges or single characters.
A range is defined as a character, a dash, and another character.
For example, the alphabet "a-z" contains all lowercase letters.
this function parses the alphabet and returns a vector of all characters in the alphabet.
*/
std::vector<char> parse_alphabet(const std::vector<std::string>& alphabet)
{
    //if alphabet is a single character, add it to the alphabet
    //if it contains a range of characters, add all characters in the range to the alphabet
    //else throw exception
    std::vector<char> result;
    for (const auto& s : alphabet)
    {
        if (s.size() == 1)
            result.push_back(s[0]);
        else if (s.size() == 3 && s[1] == '-')
        {
            for (char c = s[0]; c <= s[2]; ++c)
                result.push_back(c);
        }
        else
            throw std::runtime_error("Invalid alphabet=" + s);
    }
    return result;
}

std::unordered_map<int, bool> create_final_states(const std::vector<int>& final_states)
{
    std::unordered_map<int, bool> result;
    for (const auto& s : final_states)
    {
        result[s] = true;
    }
    return result;
}

/*
There can be multiple transitions so we have a vector defining the transitions for each state.
The string defining the transitions for each state is a comma separated list of transitions which can be either a single character or a range of characters.
For example, the transition "a-z=1,0-9=2" means that there is a transition from state 0 to state 1 for all lowercase letters and a transition from state 0 to state 2 for all digits.

This function parses the transitions and returns a map of transitions for each state.
*/

std::unordered_map<int, universal_fa::transition_map> parse_transition(const std::vector<std::vector<std::string>>& transitions)
{
    std::unordered_map<int, universal_fa::transition_map> result;
    for (int i=0; i< transitions.size(); i++)
    {
        int state = i;
        for (auto transition : transitions[i])
        {
            //split transition at = to get symbol and state
            auto pos = transition.find('=');
            if (pos == std::string::npos)
                throw std::runtime_error("Invalid transition=" + transition);
            auto symbol = transition.substr(0, pos);
            auto to_state = std::stoi(transition.substr(pos+1));

            //parse symbol it could either be a single character or a range of characters
            std::vector<char> symbols;
            if (symbol.size() == 1)
                symbols.push_back(symbol[0]);
            else if (symbol.size() == 3 && symbol[1] == '-')
            {
                for (char c = symbol[0]; c <= symbol[2]; ++c)
                    symbols.push_back(c);
            }
            else
                throw std::runtime_error("Invalid symbol=" + symbol);

            //add transition for each symbol
            for (auto s : symbols)
            {
                result[state][s] = to_state;
            }
        }
    }

    //print transitions
    std::cout << "Transitions:" << std::endl;
    for (auto state : result)
    {
        std::cout << state.first << ": ";
        for (auto transition : state.second)
        {
            std::cout << transition.first << "->" << transition.second << " ";
        }
        std::cout << std::endl;
    }

    return result;
}
}
namespace universal_fa::utils
{

    /*
    the public function to build a finite automata from a file
    */

    FiniteAutomata build_fa_from_file(const std::string& file_path)
    {
        std::cout << "Building FA from file: " << file_path << std::endl;
        universal_fa::components::Config config(file_path);
        FiniteAutomataBuilder builder;

        auto name = config.get<std::string>("name");
        builder.set_name(name);

        auto description = config.get<std::string>("description");
        builder.set_description(description);

        auto initial_state = config.get<int>("initial_state");
        builder.set_initial_state(initial_state);

        auto alphabet = config.get_vector<std::string>("alphabet");
        builder.set_alphabet(parse_alphabet(alphabet));

        auto final_states = config.get_vector<int>("final_states");
        builder.set_final_states(create_final_states(final_states));

        auto test_strings = config.get_vector<std::string>("test_strings");
        builder.set_test_strings(test_strings);

        auto num_transitions = config.get<int>("num_transitions", 2);
        
        
        std::vector<std::vector<std::string>> transitions;
        for (int i = 0; i < num_transitions; ++i)
        {
            auto transition = config.get_vector<std::string>("transitions." + std::to_string(i));
            if (transition.empty())
                break;

            transitions.push_back(transition);
        }
        builder.set_transitions(parse_transition(transitions));
        
        return builder.build();
    }
}
