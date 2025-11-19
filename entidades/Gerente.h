// Gerente.h
#pragma once
#include "Pessoa.h"
#include "../dominios/Ramal.h"
#include "../dominios/Senha.h"

/**
 * @brief Representa o gerente do hotel.
 */
class Gerente : public Pessoa {
private:
    Ramal ramal;
    Senha senha;
public:
    Gerente(const Nome& n, const Email& e, const Ramal& r, const Senha& s)
        : Pessoa(n, e), ramal(r), senha(s) {}
    void setRamal(const Ramal& r) { ramal = r; }
    void setSenha(const Senha& s) { senha = s; }
    Ramal getRamal() const { return ramal; }
    Senha getSenha() const { return senha; }
};
