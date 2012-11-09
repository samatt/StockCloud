//
//  stockUtility.h
//  stockCloud
//
//  Created by Surya on 06/10/12.
//
//

#ifndef __stockCloud__stockUtility__
#define __stockCloud__stockUtility__

#include <iostream>
#include "stock.h"
#include <vector>
#include "ofFileUtils.h"
#include "ofUtils.h"
class stockUtility{

public:
    
    vector <Stock> createStocks(vector <std::string> stringList);
    
    float filterStockList_MarketCap(std::string string);
};
#endif /* defined(__stockCloud__stockUtility__) */
