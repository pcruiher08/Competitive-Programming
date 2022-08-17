from automata.tm.dtm import DTM
from automata.tm.ntm import NTM
cinco = NTM (
states = {"q1","q2","q3","q4","q5","q6"},
input_symbols = {"a","b"},
tape_symbols = {"a","b","c","."},
transitions = {
    "q1": {
        "a": {("q1","a","R")},
        "b": {("q1","b","R")},
        "c": {("q1","c","R") , ("q2","c","R") , ("q4","c","L")}
    },
    "q2": {
        "a": {("q3","a","R")}
    },
    "q3": {
        "b": {("q6","b","R")}
    },
    "q4": {
        "b": {("q5","b","L")}
    },
    "q5": {
        "a": {("q6","a","R")}
    }
},
initial_state ="q1",
blank_symbol =".",
final_states ={"q6"}
)

cinco.read_input("aba") #accepted
cinco.read_input("abba") #accepted
cinco.read_input("a") #rejected with exception

