//
// Created by dzordzu on 5/17/19.
//


#include "OperatingSystems/Algorithms/FrameAllocation/Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>

void OperatingSystems::Algorithms::FrameAllocation::Algorithm::setFramesAmount(Process &process, int amount) {
    if(amount>process.getFramesAmount() && processor->freeFrames < amount-process.getFramesAmount()) amount = processor->freeFrames + process.getFramesAmount();

    processor->freeFrames -= (amount-process.getFramesAmount());
    process.frames.resize(amount, Frame());
}
std::vector<std::reference_wrapper<OperatingSystems::Processor::Process>> & OperatingSystems::Algorithms::FrameAllocation::Algorithm::getProcesses() {
    return processor->processes;
}
const std::string OperatingSystems::Algorithms::FrameAllocation::Algorithm::getProcessorName() {
    return processor->name;
}


