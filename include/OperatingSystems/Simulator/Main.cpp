//
// Created by dzordzu on 5/16/19.
//

#include <iostream>
#include <OperatingSystems/OperatingSystems.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Equal.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Proportional.h>

int main() {

    using OperatingSystems::Processor::Process;
    using OperatingSystems::Processor::Processor;
    using OperatingSystems::Processor::Page;
    using OperatingSystems::Processor::Call;
    using OperatingSystems::Algorithms::PageReplacement::LRU;
    using OperatingSystems::Algorithms::FrameAllocation::Equal;
    using OperatingSystems::Algorithms::FrameAllocation::Proportional;

    LRU lru;
    Process process("Own", 0, &lru);
    Page pageOwn(&process);

    Proportional algo;
    Processor processor(100, &algo);
    processor.addProcess("Test", 1);
    processor.addProcess("Test2", 2);
    processor.addProcess("Test3", 5);
    processor.addProcess(process);

    Page page(&*processor.processesVal.begin());
    processor.allocateFrames();

    for(Process &p : processor.processes) {
        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
    }

    Call call(&page);
    processor.resolveCall(call);




}
