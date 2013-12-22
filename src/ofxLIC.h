//
//  ofxLIC.h
//  Created by lukasz karluk on 22/03/11.
//

#pragma once

#include "ofMain.h"

class ofxLICVectorField {
public:
    
    ofxLICVectorField();
    ~ofxLICVectorField();
    
    virtual void setup(int w, int h);
    virtual void setVector(float x, float y, ofVec2f & vec);
    virtual void setVector(vector<ofVec2f> & vecsToCopy);
    virtual ofVec2f & getVector(ofVec2f & p);
    virtual ofVec2f & getVector(float x, float y);
    virtual ofVec2f & getVector(int index);
    virtual int getWidth();
    virtual int getHeight();
    virtual int getSize();
    
    int width;
    int height;
    int size;
    vector<ofVec2f> vecs;
    ofVec2f vecValue;
};

class ofxLIC {
  
public:
    
    ofxLIC();
    ~ofxLIC();
    
    void setup(int w, int h);
    void setVectorField(ofxLICVectorField * vecFieldPtr);
    void setVector(float x, float y, ofVec2f & vec);
    void setVector(vector<ofVec2f> & vecs);
    
    ofPolyline & getStreamline(const ofVec2f & pos, int numOfPoints, float stepSize);
    ofPolyline & getStreamline(float x, float y, int numOfPoints, float stepSize);
    
    void RK(ofVec2f & p, double h);
    
    void draw(int stride=10);
    
    ofxLICVectorField * vecField;
    bool bVecFieldExternal;
    
    ofPolyline streamline;
};