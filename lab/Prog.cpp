//
//  Prog.cpp
//  ProgLab
//
//  Created by Artemiy Sindeev on 19.02.17.
//  Copyright © 2017 Artemiy Sindeev. All rights reserved.
//

#include "Prog.h"

#define A 4
#define B 1
#define C 0
#define D -24
#define E -6
#define F 45

#define XMIN -100
#define XMAX 100
#define YMIN -100
#define YMAX 100
#define eps 0.001


Lab::Lab(){
    this->a = A;
    this->b = B;
    this->c = C;
    this->d = D;
    this->e = E;
    this->f = F;
    this->xMax = XMAX;
    this->xMin = XMIN;
    this->yMax = YMAX;
    this->yMin = YMIN;
    this->epsilon = eps;
};

Lab::~Lab(){
}

void Lab::setABCDEF(float a,float b,float c,float d,float e,float f){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->f = f;
}


void Lab::checkFlags(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        if(strncmp(argv[i], "-f", 2) == 0){
            std::cout << "FLAG!";
        }
    }
}

float Lab::func(float x, float y, float a, float b, float c, float d, float e, float f){
    return a*x*x + b*y*y + c*x*y + d*x + e*y + f;
}

float Lab::func(float x, float y){
    return func(x, y, this->a, this->b, this->c, this->d, this->e, this->f);
}

float Lab::minFunc(float x, float y){
    
    int iterCount = (this->xMax + this->yMax - this->yMin - this->xMin)/this->epsilon;
    float xMin = XMIN;
    float yMin = YMIN;
    float* result = new float[iterCount];
    float min = 0;
    
    for(int i = 0; i < iterCount; i++)
    {
        result[i] = func(xMin, yMin, A, B,C,D,E,F);
        if(result[i] < min){
            min = result[i];
        }
        if(xMin != XMAX){
            xMin += eps;
        }else{
            xMin = XMIN;
            if(yMin != YMAX){
                yMin += eps;
            }
        }
    }
    
    return min;
}





