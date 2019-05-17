//
// Created by dzordzu on 5/16/19.
//

#ifndef OPERATINGSYSTEMS_PROCESSOR_PROCESSOR_H
#define OPERATINGSYSTEMS_PROCESSOR_PROCESSOR_H

#include <vector>
#include <list>
#include <cstdint>
#include <memory>
#include <OperatingSystems/Algorithms/FrameAllocation/Algorithm.h>
#include <OperatingSystems/Algorithms/PageReplacement/Algorithm.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include "Process.h"
#include "Call.h"
#include <stdexcept>
#include <functional>

namespace OperatingSystems {
    namespace Processor {


        class Processor {
            using FramesAlgorithm = Algorithms::FrameAllocation::Algorithm;
            using PagesAlgorithm = Algorithms::PageReplacement::Algorithm;
            using LRU =  Algorithms::PageReplacement::LRU;

            friend FramesAlgorithm;
            /*
             * @XXX EXACTLY!
             */
        public:
            std::list<Process> processesVal;
            std::vector<std::reference_wrapper<Process>> processes;
        private:
            int framesAmount = 0;
            int freeFrames = 0;
            FramesAlgorithm * framesAlgorithm;
            FramesAlgorithm * framesAlgorithmOnAdd;
            std::list<std::unique_ptr<PagesAlgorithm>> pagesAlgorithms;
            std::list<Page> pages;

            int framesAllocationFrequency = 2; // calls to allocation
            int allocationsCounter = 0;

        public:
            Processor(int framesAmount, FramesAlgorithm *framesAlgorithm, FramesAlgorithm *framesAlgorithmOnAdd);
            Processor(int framesAmount, FramesAlgorithm *framesAlgorithm) : Processor(framesAmount, framesAlgorithm, framesAlgorithm) {}
            virtual void resolveCall(Call call);
            void allocateFrames();
            void allocateFramesAfterAdd();
            void addProcess(const std::string name, int pagesAmount);
            void addProcess(Process &process);
            int getFramesAmount() const;
            int getFreeFramesAmount() const;
            void setFramesAllocationFrequency(int framesAllocationFrequency);
            int getFramesAllocationFrequency() const;
            const std::string name = "MASAKRATOR V1488XD (controller JB2GMD)";
        };

    }
}



#endif //OPERATINGSYSTEMS_PROCESSOR_PROCESSOR_H
