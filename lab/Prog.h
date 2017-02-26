//
//  Prog.h
//  ProgLab
//
//  Created by Artemiy Sindeev on 19.02.17.
//  Copyright © 2017 Artemiy Sindeev. All rights reserved.
//

#ifndef Prog_h
#define Prog_h
#endif
#pragma once
#include <fstream>
#include <iostream>

class Lab
{
public:
    Lab();
    ~Lab();
    void checkFlags(int argc, char* argv[]);
    void parseData(std::ifstream file, std::string &data);
    void openFile(std::string path);
    void writeToFile(std::string path);
    void writeToFile(std::ofstream file);
    float func(float x, float y, float a, float b, float c, float d, float e, float f);
    float func(float x, float y);
    float minFunc(float x, float y);
    float maxFunc(float x, float y);
    void setABCDEF(float a,float b,float c,float d,float e,float f);
private:
    std::ifstream inputData;
    std::ofstream outputData;
    std::string data;
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float a,b,c,d,e,f;
    float epsilon;
};
