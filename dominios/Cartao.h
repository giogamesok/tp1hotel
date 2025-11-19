// Cartao.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Cartao {
private:
    std::string numero;
    void validar(const std::string& n) {
        if (n.size() != 16)
            throw std::invalid_argument("Cartão deve ter 16 dígitos.");
        int soma = 0, alt = 0;
        for (int i = 15; i >= 0; --i) {
            if (!isdigit(n[i]))
                throw std::invalid_argument("Cartão só aceita dígitos.");
            int digito = n[i] - '0';
            if (alt) digito = (digito * 2 > 9) ? digito * 2 - 9 : digito * 2;
            soma += digito;
            alt = !alt;
        }
        if (soma % 10 != 0)
            throw std::invalid_argument("Cartão inválido pelo algoritmo de Luhn.");
    }
public:
    Cartao(const std::string& n) { validar(n); numero = n; }
    void setNumero(const std::string& n) { validar(n); numero = n; }
    std::string getNumero() const { return numero; }
};
