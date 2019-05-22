//
// Created by dzordzu on 5/17/19.
//


#include "OperatingSystems/Algorithms/FrameAllocation/ErrorsControlling.h"

void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::allocateFrames() {
    std::sort(getProcesses().begin(), getProcesses().end(),[](std::reference_wrapper<Process> p1, std::reference_wrapper<Process> p2)->bool {return p1.get().errors>p2.get().errors;});

    for(Process & p : getProcesses()) {
        double errorsFrequency = (double)p.errors/(double)processor->getFramesAllocationFrequency();
        if(errorsFrequency < min) {
            setFramesAmount(p, (int)(p.getFramesAmount()*(1.0-stepReduction)));
        }
        else if(errorsFrequency > max) {
            setFramesAmount(p, p.getFramesAmount()+guaranteedStepAddition);
            setFramesAmount(p, (int)(p.getFramesAmount()*(1+stepAddition)));
        }
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, getProcesses().size()-1);

    while(processor->getFreeFramesAmount() > 0) {
        Process & p = getProcesses()[dist(mt)];
        setFramesAmount(p, p.getFramesAmount()+1);
    }

}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setMin(double min) {
    ErrorsControlling::min = min;
}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setMax(double max) {
    ErrorsControlling::max = max;
}
void
OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::pageError(OperatingSystems::Processor::Page &page) {
    page.getProcess()->errors++;
}


void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setStepReduction(double stepReduction) {
    ErrorsControlling::stepReduction = stepReduction;
}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setGuaranteedStepAddition(
        int guaranteedStepAddition) {
    ErrorsControlling::guaranteedStepAddition = guaranteedStepAddition;
}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setStepAddition(double stepAddition) {
    ErrorsControlling::stepAddition = stepAddition;
}
