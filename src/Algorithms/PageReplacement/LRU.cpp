//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/PageReplacement/LRU.h"
//#include <iostream>

void OperatingSystems::Algorithms::PageReplacement::LRU::replacePage(
        OperatingSystems::Algorithms::PageReplacement::Page &page) {
    addUsedPage(page);
    Page * pageToReplace = *usedPages.begin();

    for(Frame &frame : *frames) {
        if(frame.getPage() == pageToReplace) {
//            std::cout<<"Replaced page "<<frame.getPage()<<" with "<<&page<<std::endl;
            frame.setPage(&page);
            break;
        }
    }

    usedPages.erase(usedPages.begin());
}
void OperatingSystems::Algorithms::PageReplacement::LRU::pageAlreadyLoaded(
        OperatingSystems::Algorithms::PageReplacement::Page &page) {
    addUsedPage(page);
}
void OperatingSystems::Algorithms::PageReplacement::LRU::addUsedPage(
        OperatingSystems::Algorithms::PageReplacement::Page &page) {
    usedPages.remove(&page);
    usedPages.emplace_back(&page);
}
void OperatingSystems::Algorithms::PageReplacement::LRU::addToFrame(OperatingSystems::Processor::Page &page,
                                                                    OperatingSystems::Processor::Frame &frame) {
    addUsedPage(page);
    Algorithm::addToFrame(page, frame);
//    std::cout<<"Added "<<frame.getPage()<<" to "<<&frame<<std::endl;
}
