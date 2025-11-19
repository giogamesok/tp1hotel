// Hospede.h
#pragma once
#include "Pessoa.h"
#include "../dominios/Endereco.h"
#include "../dominios/Cartao.h"

/**
 * @brief Representa um hóspede do hotel.
 */
class Hospede : public Pessoa {
private:
    Endereco endereco;
    Cartao cartao;
public:
    Hospede(const Nome& n, const Email& e, const Endereco& end, const Cartao& c)
        : Pessoa(n, e), endereco(end), cartao(c) {}
    void setEndereco(const Endereco& end) { endereco = end; }
    void setCartao(const Cartao& c) { cartao = c; }
    Endereco getEndereco() const { return endereco; }
    Cartao getCartao() const { return cartao; }
};
