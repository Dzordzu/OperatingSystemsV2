//
// Created by dzordzu on 5/18/19.
//

#include "OperatingSystems/Simulator/ProcessorInfo.h"

OperatingSystems::Simulator::ProcessorInfo::ProcessorInfo(OperatingSystems::Processor::Processor &processor)
        : processor(processor) {}
const std::string OperatingSystems::Simulator::ProcessorInfo::fullInfo() const{
    return name() + "\n" + frames() + "\n" + freeFrames() + "\n" + allocationFrequency() + "\n" + processes();
}
const std::string OperatingSystems::Simulator::ProcessorInfo::name() const{
    return "Processor name: " + processor.name;
}
const std::string OperatingSystems::Simulator::ProcessorInfo::frames() const{
    return "Frames amount: " + std::to_string(processor.getFramesAmount());
}
const std::string OperatingSystems::Simulator::ProcessorInfo::freeFrames() const {
    return "Free frames amount: " + std::to_string(processor.getFreeFramesAmount());
}
const std::string OperatingSystems::Simulator::ProcessorInfo::allocationFrequency() const {
    std::string result = "Frame allocation: ";
    if(processor.getFramesAllocationFrequency() == -1) result += "never";
    else result += "after " + std::to_string(processor.getFramesAllocationFrequency()) += " calls";
    return result;
}
const std::string OperatingSystems::Simulator::ProcessorInfo::processes() const {
    std::string result = "Processes: \n";

    for(const Processor::Process &process : processor.getProcesses()) {
        result += process.getName() + ": weight(" + std::to_string(process.getWeight()) + "), framesAmount("
                + std::to_string(process.getFramesAmount()) + ") \n";
    }
    return result;
}
