//
// Created by sorge on 03/04/2021.
//
#include <iostream>
#include "src/include/FList.h"

int main(int argc, char *argv[]) {

    FList<long> listEntier;
    FList<std::string> listString;

    for(auto i = 0; i < 1000; i++)
    {
        listEntier.push_back(i);
        listString.push_back("totoro ");
    }

    auto sum = 0;
    auto t7 = std::chrono::high_resolution_clock::now();
    for (auto e : listEntier) sum += e;
    auto t8 = std::chrono::high_resolution_clock::now();
    std::cout << "Delta t4-t3: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
    std::cout << "somme : " << sum << std::endl;

    auto lf_fold = [](auto n1, auto n2) {
        return n1+n2;
    };

    auto t5 = std::chrono::high_resolution_clock::now();
    long res = listEntier.foldLeft(0, lf_fold);
    auto t6 = std::chrono::high_resolution_clock::now();
    std::cout << "Delta t4-t3: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
    std::cout << "foldleft : " << res << std::endl;

    auto lf_map = [](std::string p){
        int i = 0;
 //      p="mon voisin "+p;
        return p;
    };

    std::list<std::string> uneListe;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto e : listString)
    {
        //std::cout << "passage : " << uneListe.size() << std::endl;
        uneListe.push_back(lf_map(e));
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
    
    auto t3 = std::chrono::high_resolution_clock::now();
    FList<std::string> resMap = listString.map(lf_map);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Delta t4-t3: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;

    auto lf_map2 = []( auto p){
            return p;
    };

    //long resFlatMap1 = listEntier.flatMap(lf_map2);
    // stackoverflow, std::string +operator maybe...
    //auto resFlatMap = listString.flatMap(lf_map);

    spdlog::info("retour OK");
}