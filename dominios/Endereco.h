// Endereco.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Endereco {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() < 5 || s.length() > 30)
            throw std::invalid_argument("Endereço deve ter entre 5 e 30 caracteres.");
        for (char c : s) {
            if (!(isalpha(c) || isdigit(c) || c==',' || c=='.' || c==' '))
                throw std::invalid_argument("Endereço contém caracteres inválidos.");
        }
    }
public:
    Endereco(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
