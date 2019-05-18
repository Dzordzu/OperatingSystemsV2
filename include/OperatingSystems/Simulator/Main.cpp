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
#include "PagesGenerator.h"
#include "CallsGenerator.h"

int main() {

    using namespace OperatingSystems::Algorithms::FrameAllocation;

    /*
     * CONFIGURATION
     */
    const uint_fast64_t frames = 600;
    std::shared_ptr<Algorithm> algorithm(new Proportional);
    std::shared_ptr<Algorithm> addAlgorithm(new Proportional);

    std::cout<<(algorithm == nullptr);

    const uint_fast64_t allocationFrequency = 3000000;
    const uint_fast64_t minPages = 100;
    const uint_fast64_t maxPages = 300;
    const uint_fast64_t callsGroups = 3000;
    const uint_fast64_t callsGroupCount = 1000;
    const uint_fast64_t callsGroupDeviation = 10;






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
    using OperatingSystems::Simulator::PagesGenerator;
    using OperatingSystems::Simulator::CallsGenerator;


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
    processor.setErrorCounter(&errorCounters[processes.size()]);

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

        PagesGenerator pagesGenerator(pw);
        for(Page p : pagesGenerator.generate(minPages, maxPages)) {
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
    callsGenerator.setPagesSource(pages);
    for(int i=0; i<callsGroups; i++) {

        callsGenerator.randomCenter();
        callsGenerator.setDeviation(callsGroupDeviation);
        callsGenerator.setPopulation(callsGroupCount);

        for(Call & call : callsGenerator.generate()) {
            processor.resolveCall(call);
        }

    }

    std::cout<<processorInfo.fullInfo()<<std::endl;


    for(ErrorCounter & ec : errorCounters) {
        std::cout<<ec.getCounterName()<<" "<<ec.getErrors()<<std::endl;
    }



//    LRU lru;
//    Process process("Own", 0, &lru);







//

//
//
//    for(Page & page : pages) {
//        processor.resolveCall(Call(&page));
//    }






//    Page page(&*processor.processesVal.begin());
//    processor.allocateFramesAfterAdd();
//
//    for(Process &p : processor.processes) {
//        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
//    }

//    Call call(&page);
//    processor.resolveCall(call);




}
