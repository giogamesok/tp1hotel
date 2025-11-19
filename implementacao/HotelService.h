#pragma once
#include "../interfaces/IHotelService.h"
#include "../entidades/Hotel.h"
#include <vector>
#include <algorithm>

/**
 * @class HotelService
 * @brief Implementação do serviço de hotéis, gerenciando um vetor local.
 */
class HotelService : public IHotelService {
private:
    std::vector<Hotel> hoteis;
public:
    std::vector<Hotel> listarHoteis() const override {
        return hoteis;
    }

    void criarHotel(const Hotel& hotel) override {
        hoteis.push_back(hotel);
    }

    void atualizarHotel(const Hotel& hotel) override {
        auto it = std::find_if(hoteis.begin(), hoteis.end(),
            [&hotel](const Hotel& h) {
                return h.getCodigo().getValor() == hotel.getCodigo().getValor();
            });
        if (it != hoteis.end()) {
            *it = hotel; // Atualiza hotel existente
        }
    }

    void removerHotel(const std::string& codigo) override {
        hoteis.erase(std::remove_if(hoteis.begin(), hoteis.end(),
            [&codigo](const Hotel& h) {
                return h.getCodigo().getValor() == codigo;
            }), hoteis.end());
    }
};
