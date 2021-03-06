//
// Created by dzordzu on 5/16/19.
//

#include "OperatingSystems/Processor/Processor.h"
//#include <iostream>

void OperatingSystems::Processor::Processor::resolveCall(Call & call) {

    if(&call == nullptr) throw std::logic_error("Call should never be nullptr");

    framesAlgorithm->alwaysRun(*call.getPage());

    if(call.getPage() == nullptr) throw std::logic_error("Page pointer should never (ever be nullptr)");
    if(call.getPage()->getProcess() == nullptr) throw std::logic_error("Page->process pointer should never (ever be nullptr)");

    if(call.getPage()->getProcess()->resolvePage(*call.getPage())) {
        if(errorCounter != nullptr) errorCounter->add();
        framesAlgorithm->pageError(*call.getPage());
    }

    if(allocationsCounter >= 0) allocationsCounter++;
//    std::cout<<"Time left to allocations"<<framesAllocationFrequency - allocationsCounter;

    if(allocationsCounter == framesAllocationFrequency) {
        allocationsCounter = 0;
        framesAlgorithm->allocateFrames();
//        std::cout<<"Frames allocated "<<std::endl;
    }
}
void OperatingSystems::Processor::Processor::allocateFrames() {
    framesAlgorithm->allocateFrames();
}


void OperatingSystems::Processor::Processor::addProcess(const std::string name, int pagesAmount) {
    pagesAlgorithms.emplace_back(std::make_unique<LRU>());
    this->processesVal.emplace_back(Process(name, 0, &(**pagesAlgorithms.rbegin())));
    this->processes.emplace_back(*processesVal.rbegin());

    for(int i=0; i<pagesAmount; i++) {
        pages.emplace_back(Page(&*processesVal.rbegin()));
    }
    framesAlgorithmOnAdd->allocateFrames();
}



OperatingSystems::Processor::Processor::Processor(int framesAmount, FramesAlgorithm *framesAlgorithm,
                                                  FramesAlgorithm *framesAlgorithmOnAdd)
        : freeFrames(framesAmount), framesAlgorithm(framesAlgorithm), framesAmount(framesAmount), framesAlgorithmOnAdd(framesAlgorithmOnAdd) {
    if(framesAmount == 0) throw std::logic_error("No frames");
    if(framesAlgorithm == nullptr) throw std::logic_error("Couldn't find frames allocation algorithm");
    framesAlgorithm->processor = this;
    framesAlgorithmOnAdd->processor = this;
}
int OperatingSystems::Processor::Processor::getFramesAmount() const {
    return framesAmount;
}
int OperatingSystems::Processor::Processor::getFreeFramesAmount() const {
    return freeFrames;
}
void OperatingSystems::Processor::Processor::addProcess(OperatingSystems::Processor::Process &process) {
    this->processes.emplace_back(process);
}
void OperatingSystems::Processor::Processor::setFramesAllocationFrequency(int framesAllocationFrequency) {
    Processor::framesAllocationFrequency = framesAllocationFrequency;
}
void OperatingSystems::Processor::Processor::allocateFramesAfterAdd() {
    framesAlgorithmOnAdd->allocateFrames();
}
int OperatingSystems::Processor::Processor::getFramesAllocationFrequency() const {
    return framesAllocationFrequency;
}
void OperatingSystems::Processor::Processor::setErrorCounter(OperatingSystems::Processor::ErrorCounter *errorCounter) {
    Processor::errorCounter = errorCounter;
}
const std::vector<std::reference_wrapper<OperatingSystems::Processor::Process>>
OperatingSystems::Processor::Processor::getProcesses() const {
    return processes;
}
