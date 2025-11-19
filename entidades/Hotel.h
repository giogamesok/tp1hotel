#pragma once
#include "../dominios/Nome.h"
#include "../dominios/Endereco.h"
#include "../dominios/Telefone.h"
#include "../dominios/Codigo.h"
#include "Gerente.h"
#include "Quarto.h"
#include <vector>


/**
 * @brief Representa um hotel.
 *
 * Possui nome, endereço, telefone, código, gerente(s) e quartos.
// Hotel.h
#pragma once
#include "../dominios/Nome.h"
#include "../dominios/Endereco.h"
#include "../dominios/Telefone.h"
#include "../dominios/Codigo.h"
#include "Gerente.h"
#include "Quarto.h"
#include <vector>

/**
 * @brief Representa um hotel.
 */

class Hotel {
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;
    Gerente gerente;
    std::vector<Quarto> quartos;
public:
    Hotel(const Nome& n, const Endereco& e, const Telefone& t, const Codigo& c, const Gerente& g)
        : nome(n), endereco(e), telefone(t), codigo(c), gerente(g) {}
    void setNome(const Nome& n) { nome = n; }
    void setEndereco(const Endereco& e) { endereco = e; }
    void setTelefone(const Telefone& t) { telefone = t; }
    void setCodigo(const Codigo& c) { codigo = c; }
    void setGerente(const Gerente& g) { gerente = g; }
    void adicionarQuarto(const Quarto& q) { quartos.push_back(q); }
    Nome getNome() const { return nome; }
    Endereco getEndereco() const { return endereco; }
    Telefone getTelefone() const { return telefone; }
    Codigo getCodigo() const { return codigo; }
    Gerente getGerente() const { return gerente; }
    std::vector<Quarto> getQuartos() const { return quartos; }
};
