//
//  dataReceiver.h
//  StockCloud_oF
//
//  Created by Surya Mattu on 16/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StockCloud_oF_dataReceiver_h
#define StockCloud_oF_dataReceiver_h
#include "ofFileUtils.h"
#include "ofUtils.h"
#include "stock.h"

class dataReceiver{
    
public:
    std::list<std::string> parseData(std::string dataReceived);
     vector <std::string>  fileReader(string filePath);
    
};


#endif
