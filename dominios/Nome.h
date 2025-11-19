// Nome.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Nome {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() < 5 || s.length() > 20)
            throw std::invalid_argument("Nome deve ter entre 5 e 20 caracteres.");
        if (!isalpha(s[0]) || !isalpha(s[s.size()-1]))
            throw std::invalid_argument("Primeiro e último caracteres devem ser letras.");
        for (char c : s) {
            if (!(isalpha(c) || isdigit(c) || c == ' '))
                throw std::invalid_argument("Nome deve conter só letras, dígitos ou espaço.");
        }
    }
public:
    Nome(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
