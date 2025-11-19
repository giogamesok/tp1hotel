#pragma once
#include "../interfaces/IGerenteService.h"
#include "../entidades/Gerente.h"
#include <vector>
#include <algorithm>

/**
 * @class GerenteService
 * @brief Implementação concreta do serviço de gerentes.
 */
class GerenteService : public IGerenteService {
private:
    std::vector<Gerente> gerentes;
public:
    std::vector<Gerente> listarGerentes() const override {
        return gerentes;
    }

    void criarGerente(const Gerente& gerente) override {
        gerentes.push_back(gerente);
    }

    void removerGerente(const std::string& ramal) override {
        gerentes.erase(std::remove_if(gerentes.begin(), gerentes.end(),
            [&ramal](const Gerente& g) {
                return g.getRamal().getValor() == ramal;
            }), gerentes.end());
    }
};
