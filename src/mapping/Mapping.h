//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_MAPPING_H
#define MC_INJECTION_MAPPING_H

#include <map>
#include <string>
#include "CM.h"
#include "Mem.h"
#include <iostream>

// Map of class names to mapping structures
extern std::map<std::string, CM*> lookup;

class Mapping {
public:
    Mapping() {
        // Populate the map
        setup();
    }

    static CM* getClass(const char* key);

    static const char* getClassName(const char* key);

    static void setup();
private:
    static void field(CM *cm, const char* name, const char* desc, bool isStatic);

    static void method(CM *cm, const char* name, const char* desc, bool isStatic);

    static void field(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic);

    static void method(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic);

    static CM* make(const char* key, const char* name);
};


#endif //MC_INJECTION_MAPPING_H
