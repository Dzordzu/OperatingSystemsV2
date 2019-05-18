//
// Created by dzordzu on 5/16/19.
//

#include <iostream>
#include <OperatingSystems/OperatingSystems.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Equal.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Proportional.h>
#include <OperatingSystems/Algorithms/FrameAllocation/WorkingSet.h>
#include <OperatingSystems/Algorithms/FrameAllocation/ErrorsControlling.h>
#include "ProcessorInfo.h"

int main() {

    using OperatingSystems::Processor::Process;
    using OperatingSystems::Processor::Processor;
    using OperatingSystems::Processor::Page;
    using OperatingSystems::Processor::Call;
    using OperatingSystems::Algorithms::PageReplacement::LRU;

    using namespace OperatingSystems::Algorithms::FrameAllocation;

    LRU lru;
    Process process("Own", 0, &lru);

    std::vector<Page> pages;
    pages.reserve(2000);
    pages.resize(65, {&process});

    ErrorsControlling algo;
    Proportional addAlgo;


    Processor processor(50, &algo, &addAlgo);
    OperatingSystems::Simulator::ProcessorInfo processorInfo(processor);
    processor.setFramesAllocationFrequency(10);

    processor.addProcess("Test", 10);
    processor.addProcess("Test2", 20);
    processor.addProcess("Test3", 50);
    processor.addProcess(process);
    processor.allocateFramesAfterAdd();

    std::cout<<processorInfo.fullInfo();


    for(Page & page : pages) {
        processor.resolveCall(Call(&page));
    }






//    Page page(&*processor.processesVal.begin());
//    processor.allocateFramesAfterAdd();

    for(Process &p : processor.processes) {
        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
    }

//    Call call(&page);
//    processor.resolveCall(call);




}
