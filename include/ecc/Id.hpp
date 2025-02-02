/*
 * This file is part of MQT QFR library which is released under the MIT license.
 * See file README.md or go to https://www.cda.cit.tum.de/research/quantum/ for more information.
 */

#pragma once

#include "Ecc.hpp"
#include "QuantumComputation.hpp"
namespace ecc {
    class Id: public Ecc {
    public:
        Id(std::shared_ptr<qc::QuantumComputation> qc, std::size_t measureFq):
            Ecc({ID::Id, 1, 0, "Id", {}}, std::move(qc), measureFq) {}

    protected:
        void writeEncoding() override{};

        void measureAndCorrect() override{};

        void writeDecoding() override{};

        void mapGate(const qc::Operation& gate) override {
            qcMapped->emplace_back(gate.clone());
        }
    };
} // namespace ecc
