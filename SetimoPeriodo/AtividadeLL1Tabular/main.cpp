#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Definição da tabela LL(1)
map<pair<string, string>, vector<string>> parsingTable = {
    {{"S", "if"}, {"if", "E", "then", "S", "else", "S"}},
    {{"S", "a"}, {"a"}},
    {{"E", "b"}, {"b"}},
    {{"E", "c"}, {"c"}}
};

// Função para verificar se um símbolo é terminal
bool isTerminal(const string& symbol) {
    return symbol == "if" || symbol == "then" || symbol == "else" || symbol == "a" || symbol == "b" || symbol == "c" || symbol == "$";
}

// Função para converter a pilha em string
string printStack(stack<string> s) {
    vector<string> stackContents;
    while (!s.empty()) {
        stackContents.push_back(s.top());
        s.pop();
    }
    reverse(stackContents.begin(), stackContents.end());

    string result = "[ ";
    for (const auto& s : stackContents) {
        result += s + " ";
    }
    result += "]";
    return result;
}

// Função para converter a entrada em string
string printInput(vector<string>& tokens, int index) {
    string result;
    for (size_t i = index; i < tokens.size(); ++i) {
        result += tokens[i] + " ";
    }
    return result;
}

// Função do parser LL(1)
bool parse(vector<string> tokens) {
    stack<string> parsingStack;
    parsingStack.push("$");
    parsingStack.push("S");
    
    int index = 0;
    string lookahead = tokens[index];
    
    // Cabeçalho da tabela
    cout << left << setw(30) << "Pilha" 
         << setw(30) << "Entrada" 
         << "Ação" << endl;
    cout << string(90, '-') << endl;

    while (!parsingStack.empty()) {
        // Salva o estado da pilha antes de alterá-la
        string stackState = printStack(parsingStack);
        string inputState = printInput(tokens, index);

        string top = parsingStack.top();
        parsingStack.pop();

        if (isTerminal(top)) {
            if (top == lookahead) {
                // Atualiza a entrada antes de imprimir a ação
                index++;
                lookahead = (index < tokens.size()) ? tokens[index] : "$";

                // Exibe estado atualizado
                cout << left << setw(30) << stackState
                     << setw(30) << inputState
                     << "Match " << top << endl;
            } else {
                cout << "Erro de sintaxe!" << endl;
                return false;
            }
        } else {
            if (parsingTable.find({top, lookahead}) != parsingTable.end()) {
                vector<string> production = parsingTable[{top, lookahead}];

                // Exibe antes de modificar a pilha
                cout << left << setw(30) << stackState
                     << setw(30) << inputState
                     << top << " → ";
                for (const auto& sym : production) cout << sym << " ";
                cout << endl;

                // Insere a produção na pilha (em ordem reversa)
                for (auto it = production.rbegin(); it != production.rend(); ++it) {
                    parsingStack.push(*it);
                }
            } else {
                cout << "Erro de sintaxe!" << endl;
                return false;
            }
        }
    }

    cout << string(90, '-') << endl;
    cout << "Entrada aceita!" << endl;
    return lookahead == "$";
}

int main() {
    vector<string> input = {"if", "b", "then", "a", "else", "a", "$"};
    
    parse(input);
    
    return 0;
}
