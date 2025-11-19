#pragma once
#include "../interfaces/IQuartoService.h"
#include "../entidades/Quarto.h"
#include <vector>
#include <algorithm>

/**
 * @class QuartoService
 * @brief Implementação do serviço para gerenciamento de quartos.
 */
class QuartoService : public IQuartoService {
private:
    std::vector<Quarto> quartos;
public:
    std::vector<Quarto> listarQuartos() const override {
        return quartos;
    }

    void adicionarQuarto(const Quarto& quarto) override {
        quartos.push_back(quarto);
    }

    void removerQuarto(const std::string& codigo) override {
        quartos.erase(std::remove_if(quartos.begin(), quartos.end(),
            [&codigo](const Quarto& q) {
                return q.getCodigo().getValor() == codigo;
            }), quartos.end());
    }
};
