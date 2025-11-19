// Codigo.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Codigo {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() != 10)
            throw std::invalid_argument("O código deve ter 10 caracteres.");
        for (char c : s) {
            if (!(islower(c) || isdigit(c)))
                throw std::invalid_argument("Código contém caracteres inválidos.");
        }
    }
public:
    Codigo(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
