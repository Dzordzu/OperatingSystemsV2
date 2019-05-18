//
// Created by dzordzu on 5/18/19.
//

#include "OperatingSystems/Simulator/PagesGenerator.h"

OperatingSystems::Simulator::PagesGenerator::PagesGenerator(
        ProcessWrapper &process) : process(process) {}


std::vector<OperatingSystems::Processor::Page>
OperatingSystems::Simulator::PagesGenerator::generate(uint_fast64_t min, uint_fast64_t max) {
    std::mt19937 mt(device());
    std::uniform_int_distribution<> dist(min, max);

    std::vector<Processor::Page> result;
    for(uint_fast64_t i=0; i<dist(mt); i++) {
        result.emplace_back(Processor::Page(&*process));
    }
    return result;
}
