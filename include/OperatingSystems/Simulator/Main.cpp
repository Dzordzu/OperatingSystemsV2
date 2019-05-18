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
#include <OperatingSystems/Processor/ErrorCounter.h>
#include "ProcessorInfo.h"
#include "ProcessWrapper.h"

int main() {

    using namespace OperatingSystems::Algorithms::FrameAllocation;

    /*
     * CONFIGURATION
     */
    const uint_fast64_t frames = 50;
    std::shared_ptr<Algorithm> algorithm = std::make_shared<Algorithm>(new ErrorsControlling);
    std::shared_ptr<Algorithm> addAlgorithm = std::make_shared<Algorithm>(new Proportional);
    const uint_fast64_t allocationFrequency = frames;
    const uint_fast64_t minPages = 100;
    const uint_fast64_t maxPages = 300;
    const uint_fast64_t callsGroups = 300;
    const uint_fast64_t callsGroupCount = 5;
    const uint_fast64_t callsGroupDeviation = 2;




    /*
     * Namespaces declaration
     */
    using OperatingSystems::Processor::Process;
    using OperatingSystems::Processor::Processor;
    using OperatingSystems::Processor::Page;
    using OperatingSystems::Processor::Call;
    using OperatingSystems::Processor::ErrorCounter;
    using OperatingSystems::Algorithms::PageReplacement::LRU;
    using OperatingSystems::Simulator::ProcessWrapper;


    /*
     * Processes names
     */
    std::vector<std::string> names {
            "Docker", "MyApp", "OperatingSystems", "Test", "KDE", "NonWindowsApp", "Git", "Inkscape", "Gimp", "Firefox"
    };

    /*
     * Declare processor
     */
    Processor processor(frames, &*algorithm, &*addAlgorithm);
    processor.setFramesAllocationFrequency(allocationFrequency);

    /*
     * Declare processes
     */

    std::vector<ProcessWrapper> processes;
    processes.reserve(10);
    for(const std::string & name : names) {
        processes.emplace_back(ProcessWrapper(name));
    }

    /*
     * Declare counters
     */
    std::vector<ErrorCounter> errorCounters;
    errorCounters.reserve(12);
    for(const std::string & name : names) {
        errorCounters.emplace_back(ErrorCounter(name + " Counter"));
    }
    errorCounters.emplace_back(ErrorCounter("General Counter"));

    /*
     * Connect counters with processes
     */
    for(int i=0; i<processes.size(); i++) {
        processes[i]->setCounter(&errorCounters[i]);
    }

    /*
     * Add processes to processor
     */
    for(ProcessWrapper & pw : processes) {
        processor.addProcess(*pw);
    }

    /*
     * Add pages
     */
    std::vector<Page> pages;
    for(ProcessWrapper & pw : processes) {

        PagesGenerator pagesGenerator(*pw);
        for(Page &p : pagesGenerator.generate(minPages, maxPages)) {
            pages.emplace_back(p);
        }

    }

    /*
     * Allocate frames after addition of frames
     */
    processor.allocateFramesAfterAdd();

    /*
     * Show info
     */
    OperatingSystems::Simulator::ProcessorInfo processorInfo(processor);

    /*
     * Resolve random calls
     */
    CallsGenerator callsGenerator;
    callsGenerator.setPagesSource()
    for(int i=0; i<callsGroups; i++) {

        callsGenerator.randomCenter();
        callsGenerator.deviation(callsGroupDeviation);
        callsGenerator.population(callsGroupCount);

        for(Call & call : callsGenerator.generate()) {
            processor.resolveCall(call);
        }

    }



//    LRU lru;
//    Process process("Own", 0, &lru);








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
