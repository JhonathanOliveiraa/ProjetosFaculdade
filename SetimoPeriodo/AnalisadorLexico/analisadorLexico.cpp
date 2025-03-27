#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

struct Token {
    string value, type;
};

vector<string> keywords = {"if", "else", "while", "int", "float"};
vector<string> operators = {"+", "-", "*", "/", "=", "!=", "<=", ">="};
vector<string> punctuation = {"(", ")", "{", "}", ";"};

bool isKeyword(const string &word) {
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

bool isOperator(const string &word) {
    return find(operators.begin(), operators.end(), word) != operators.end();
}

bool isPunctuation(const string &word) {
    return find(punctuation.begin(), punctuation.end(), word) != punctuation.end();
}

bool isInteger(const string &word) {
    return word.find_first_not_of("0123456789") == string::npos;
}

bool isFloat(const string &word) {
    return word.find('.') != string::npos && word.find_first_not_of("0123456789.") == string::npos;
}

vector<Token> tokenize(const string &code) {
    vector<Token> tokens;
    string token;
    istringstream stream(code);
    char ch;
    bool inString = false;

    while (stream.get(ch)) {
        if (ch == '"') {
            if (inString) {
                token += ch;
                tokens.push_back({token, "string"});
                token.clear();
                inString = false;
            } else {
                if (!token.empty()) {
                    tokens.push_back({token, "identificador"});
                    token.clear();
                }
                token += ch;
                inString = true;
            }
        } else if (inString) {
            token += ch;
        } else if (isspace(ch)) {
            if (!token.empty()) {
                if (isKeyword(token)) tokens.push_back({token, "palavra-chave"});
                else if (isInteger(token)) tokens.push_back({token, "literal inteiro"});
                else if (isFloat(token)) tokens.push_back({token, "literal ponto flutuante"});
                else tokens.push_back({token, "identificador"});
                token.clear();
            }
        } else if (isPunctuation(string(1, ch))) {
            if (!token.empty()) {
                if (isKeyword(token)) tokens.push_back({token, "palavra-chave"});
                else if (isInteger(token)) tokens.push_back({token, "literal inteiro"});
                else if (isFloat(token)) tokens.push_back({token, "literal ponto flutuante"});
                else tokens.push_back({token, "identificador"});
                token.clear();
            }
            tokens.push_back({string(1, ch), "pontuação"});
        } else if (isOperator(string(1, ch))) {
            if (!token.empty()) {
                tokens.push_back({token, "identificador"});
                token.clear();
            }
            string op(1, ch);
            if (stream.peek() == '=' || (ch == '!' && stream.peek() == '=')) {
                op += stream.get();
            }
            tokens.push_back({op, "operador"});
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        if (isKeyword(token)) tokens.push_back({token, "palavra-chave"});
        else if (isInteger(token)) tokens.push_back({token, "literal inteiro"});
        else if (isFloat(token)) tokens.push_back({token, "literal ponto flutuante"});
        else tokens.push_back({token, "identificador"});
    }
    return tokens;
}

int main() {
    vector<string> codes = {
        "int a = 5 + 10 * 2; // soma e multiplicação\nfloat b = 3.14 - 1.5;\na = a + b;",
        "int x = 42; // inicialização\nif (x != 0) {\n    print(\"x é positivo\");\n} else {\n    print(\"x é zero\"); // mensagem alternativa\n}",
        "float temp = 10.5;\nwhile (temp >= 0.0) { // loop decrescente\n    temp = temp - 2.5;\n    print(\"temperatura atual\");\n}"
    };
    
    for (size_t i = 0; i < codes.size(); ++i) {
        cout << "Código-Fonte " << (i + 1) << ":\n";
        vector<Token> tokens = tokenize(codes[i]);
        for (const auto &token : tokens) {
            cout << "(" << token.value << ", " << token.type << ")\n";
        }
        cout << "\n----------------------------------------\n\n";
    }
    
    return 0;
}
