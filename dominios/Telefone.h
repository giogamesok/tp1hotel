// Telefone.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Telefone {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.empty() || s[0] != '+' || s.size() < 12 || s.size() > 15)
            throw std::invalid_argument("Telefone inválido, deve começar com '+' e ter tamanho correto.");
        for (size_t i=1; i<s.size(); ++i)
            if (!isdigit(s[i]))
                throw std::invalid_argument("Telefone deve conter só dígitos após '+'.");
    }
public:
    Telefone(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
