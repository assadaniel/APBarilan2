//
// Created by User on 07/08/2022.
//

#include "KSmallestRun.h"
#include "IrisReader.hpp"
#include "KSmallestElements.hpp"
void KSmallestRun::runKSmallest(int k, std::fstream& new_classified_stream, const std::string& unclassified_file_name) {
    IrisReader classifiedIrisReader("classified.csv"); // name of classified file
    Iris cIris;
    std::vector<Iris> classifiedIrises;
    while (classifiedIrisReader.getNextIris(cIris)) { classifiedIrises.push_back(cIris); }
    //Create Unclassified Iris vector
    IrisReader unclassifiedIrisReader(unclassified_file_name);
    Iris uIris;
    std::vector<Iris> unclassifiedIrises;
    while (unclassifiedIrisReader.getNextIris(uIris)) { unclassifiedIrises.push_back(uIris); }
    //Create Streams
    for (const Iris& unclassifiedIris: unclassifiedIrises) {
        //Write the types to files.
        new_classified_stream <<
        enumArr[typeFromIrises(unclassifiedIris, classifiedIrises, k, eucDistance)]
                << std::endl;
    }
}