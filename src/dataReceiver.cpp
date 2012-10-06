//
//  dataReceiver.cpp
//  StockCloud_oF
//
//  Created by Surya Mattu on 16/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
//  The Data Receiver class is used to read in the strings from the csv files and convert them into arrays for further manipulation

#include <iostream>
#include <list>
#include "dataReceiver.h"
//#define STRING_SIZE 20
#include<vector.h>

//fFile Test;

std::list<std::string> dataReceiver::parseData(std::string dataReceived){
    
    std::list<std::string> myStringList;
    //std::string t = "%" + "\n"; 
    
    dataReceived.find("/");
   
}

 vector <std::string>  dataReceiver::fileReader(string filePath){
    
    ofFile file;
    ofBuffer Buffer;
    std::string rows;
    string data;
    vector <std::string> stockList;
   // vector<std::string>::iterator x;
    
    if(file.open(filePath)){
     
        Buffer = file.readToBuffer();
    }
    
    data = Buffer.getText();
    ofStringReplace(data, "\",", "%");
    ofStringReplace(data, "B,", "B%");
    ofStringReplace(data, "M,", "M%");
    for (int i=0; i<10; i++) {
        ofStringReplace(data, ofToString(i) + ",", ofToString(i)+ "%");
    }
    ofStringReplace(data, "\"", "");
    stockList = ofSplitString(data, "%");
    for (vector<string>::iterator i = stockList.begin();
         i != stockList.end();
         ++i)
    {
        cout << *i << endl;
    }

    return stockList;
}

