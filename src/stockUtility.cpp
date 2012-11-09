//
//  stockUtility.cpp
//  stockCloud
//
//  Created by Surya on 06/10/12.
//
//

#include "stockUtility.h"

vector <Stock> stockUtility:: createStocks (vector <std::string> stringList){
    Stock stock;
    vector <Stock> stockList;
    stockUtility util;
     cout<<"HERE"<<endl;
    
    //TODO: Investigate why this first pop_back is
    stringList.pop_back();
    
    while(stringList.size()>6){

        stock.setAverageDailyVolume(util.filterStockList_MarketCap(stringList.back()));
        stringList.pop_back();
       
        stock.setMarketCap(util.filterStockList_MarketCap(stringList.back()));
        stringList.pop_back();
        
        stock.setLastTrade(ofToFloat(stringList.back()));
        stringList.pop_back();
        
        stock.setLastTradeDate(stringList.back());
        stringList.pop_back();

        stock.setName(stringList.back());
        stringList.pop_back();

        stock.setCode(stringList.back());
        stringList.pop_back();
       
        stockList.push_back(stock);
        
    }
    
    return stockList;
}

float stockUtility::filterStockList_MarketCap(std::string string){

    float marketcapvalue;
    
	if(string.compare("N/A")){
		marketcapvalue = ofToFloat("0");
	}
    
	if (string.find("B")) {
		ofStringReplace(string, "B", "0");
        //string.replace('B', '0');
		marketcapvalue = ofToFloat(string);
		return marketcapvalue*1000000000;
	}
    
	if (string.find("M")){
		ofStringReplace(string, "M", "0");
		marketcapvalue = ofToFloat(string);
		return marketcapvalue*1000000;
	}
    
    
	return ofToFloat(string);
}
