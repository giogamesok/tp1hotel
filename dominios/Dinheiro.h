// Dinheiro.h
#pragma once
#include <stdexcept>

class Dinheiro {
private:
    double valor;
    void validar(double v) {
        if (v < 0.01 || v > 1000000.0)
            throw std::invalid_argument("Valor inválido para dinheiro.");
    }
public:
    Dinheiro(double v) { validar(v); valor = v; }
    void setValor(double v) { validar(v); valor = v; }
    double getValor() const { return valor; }
};
