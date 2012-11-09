#pragma once

#include "ofMain.h"
#include "ofFileUtils.h"
#include "dataReceiver.h"
#include "stockUtility.h"
#include "stock.h"
#include <iostream>
#include "ofEasyCam.h"
#include "Particle.h"
#include "Force.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        ofEasyCam cam;
        vector <Stock> stocks;
        vector <Particle> stockParticles;
        vector  <Force> forces;
        int redValue;
        int greenValue;
        int blueValue;
        int averageValue;
        int lastX, lastY;
        ofMesh mesh;
};
