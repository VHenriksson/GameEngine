//
// Created by viktor on 2021-02-06.
//

#ifndef GAMEENGINE_HASHFUNCTION_H
#define GAMEENGINE_HASHFUNCTION_H


#include <cstddef>
#include <unordered_map>
#include <iostream>

static std::hash<std::string> hasher;

static std::size_t getHash(std::string string){
    std::cout << string << " hashed to " << hasher(string) << std::endl;
        return hasher(string);
    }


#endif //GAMEENGINE_HASHFUNCTION_H
