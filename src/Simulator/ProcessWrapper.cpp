//
// Created by dzordzu on 5/18/19.
//

#include "OperatingSystems/Simulator/ProcessWrapper.h"

OperatingSystems::Simulator::ProcessWrapper::ProcessWrapper(const std::string name) {
    algorithm = std::unique_ptr<Algorithm>(new Algorithm);
    process = std::unique_ptr<Process>(new Process(name, 0, &*algorithm));
}
OperatingSystems::Processor::Process& OperatingSystems::Simulator::ProcessWrapper::operator*() {
    return *process;
}
OperatingSystems::Simulator::ProcessWrapper::Process *OperatingSystems::Simulator::ProcessWrapper::operator&() {
    return &*process;
}
OperatingSystems::Simulator::ProcessWrapper::Process *OperatingSystems::Simulator::ProcessWrapper::operator->() {
    return &*process;
}
