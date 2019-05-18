//
// Created by dzordzu on 5/18/19.
//

#include "OperatingSystems/Simulator/CallsGenerator.h"

void OperatingSystems::Simulator::CallsGenerator::setPagesSource(const std::vector <Processor::Page> &sources) {
    this->sources = sources;
}
void OperatingSystems::Simulator::CallsGenerator::randomCenter() {
    std::mt19937 mt(device());
    std::uniform_int_distribution<> dist(1, sources.size()-1);

    this->center = dist(mt);
}
void OperatingSystems::Simulator::CallsGenerator::setDeviation(uint_fast32_t deviation) {
    CallsGenerator::deviation = deviation;
}
void OperatingSystems::Simulator::CallsGenerator::setPopulation(uint_fast32_t population) {
    CallsGenerator::population = population;
}
std::vector<OperatingSystems::Processor::Call> OperatingSystems::Simulator::CallsGenerator::generate() {
    std::vector<Call> calls;
    std::mt19937 mt(device());
    std::normal_distribution<> dist(0, deviation);

    for(int i=0; i<population; i++) {
        uint_fast32_t index = ((int)(dist(mt)) + center)%sources.size();

        calls.emplace_back(Call(&sources[index]));
    }
}
