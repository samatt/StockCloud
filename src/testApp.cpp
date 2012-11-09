#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
/*
    ofSetVerticalSync(true);
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	ofHideCursor();
*/
    dataReceiver data;
    stockUtility utils ;
    vector <std::string> stockList;
    redValue =0;
    blueValue = 0;
    greenValue=0;
    
    cam.setNearClip(0.1);
    cam.setFarClip(100);//"1meter"totheright,"5meters"awayfromobject
    cam.setPosition(ofVec3f(1,0,5));
    
    stockList =  data.fileReader("/Volumes/Macintosh HD/Users/apple/Documents/of_0071_osx_release/apps/myApps/stockCloud/data/quotes_long.csv");

    //Update the stockList with the stock information
    stocks = utils.createStocks(stockList);
    //ofBackgroundHex(0x64DCFF,128);
    ofFill();
    Stock test;
    for(int i =0 ; i<stocks.size();i++){
        cout<< "Loading stock particles...n";
        cout<< stocks[i].getCode()  << " \n";
    
        stockParticles.push_back(Particle(stocks[i].getLastTrade(), stocks[i].getAverageDailyVolume()));
    }
    


}

//--------------------------------------------------------------
void testApp::update(){

 
}

//--------------------------------------------------------------
void testApp::draw(){
/*
    ofBackground(0);
	ofSetColor(255);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateY(ofGetFrameNum());
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);

	if(ofGetKeyPressed()) {
		mesh.drawWireframe();
	} else {
		mesh.draw();
	}
    
//    cam.begin();
//    glPointSize(10);
//    glBegin(GL_POINTS);
//    glVertex3f(0,0,0);
//    glEnd();
//    cam.end();
*/
    if(blueValue>greenValue&&blueValue>redValue){
     ofBackground(255, 0, 0,160);
    }
    else if(greenValue>blueValue&&greenValue>redValue){
     ofBackground(0, 255, 0,160);
    }
    else if(redValue>blueValue&&redValue>greenValue){
     ofBackground(255, 0, 255,160);
    }

    redValue =0;
    blueValue = 0;
    greenValue=0;
    for(int i =0 ; i<stocks.size();i++){
     
        if(stocks[i].getLastTrade()<30){
            ofSetColor(255, 0, 0);
            if(redValue < 255)
            {
                redValue++;
            }
            else{
                redValue =0;
            }
        }
        else if(stocks[i].getLastTrade()>30&&stocks[i].getLastTrade()<70){
            ofSetColor(0, 0, 255);
            if(blueValue < 255)
            {
                blueValue++;
            }
            else{
                blueValue =0;
            }
        }
        else if(stocks[i].getLastTrade()>70){
            ofSetColor(0, 255, 0);
            if(greenValue < 255)
            {
                greenValue++;
            }
            else{
                greenValue =0;
            }
        }

        
       cout<< "r: " << redValue<< ", "<< "b: "<< blueValue<< ", "<< "g: "<< greenValue<<"\n";
        ofCircle(stocks[i].getAverageDailyVolume()/1e+13,stocks[i].getAverageDailyVolume()/1e+13, (int)stocks[i].getLastTrade());
      
    }

   // cout<<averageValue<<"\n";

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 'f') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	ofVec2f start(lastX, lastY);
	ofVec2f end(x, y);
	ofVec2f diff = end - start;
	ofVec3f perp = diff.rotate(90).normalize();
	perp *= 100;
	ofColor curColor = ofColor::fromHsb(ofRandom(255), 255, 255);
    
	//perp.rotate(ofGetElapsedTimef() * 90, diff);
	ofVec3f top = ofVec3f(end) - perp/2;
	ofVec3f bottom = ofVec3f(end) + perp/2;
    
	mesh.addColor(curColor);
	mesh.addVertex(top);
	mesh.addColor(curColor);
	mesh.addVertex(bottom);
	lastX = x;
	lastY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}