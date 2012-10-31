//
//  stockUtility.cpp
//  stockCloud
//
//  Created by Surya on 06/10/12.
//
//

#include "stockUtility.h"

vector <Stock>  createStocks (vector <std::string> stringList){
    Stock stock;
    vector <Stock> stockList;
    stockUtility util;
    while(stringList.size()>6){
    
        stock.setCode(stringList.back());
        stringList.pop_back();
        
        stock.setName(stringList.back());
        stringList.pop_back();
        
        stock.setLastTradeDate(stringList.back());
        stringList.pop_back();
        
        stock.setLastTrade(util.filterStockList_MarketCap(stringList.back()));
        stringList.pop_back();
        
       stock.setMarketCap(util.filterStockList_MarketCap(stringList.back()));
        stringList.pop_back();
        
        stock.setAverageDailyVolume(util.filterStockList_MarketCap(stringList.back()));
        stringList.pop_back();
        
        
        stockList.push_back(stock);
        
    }
    
    stockList.push_back(stock);
}

float filterStockList_MarketCap(std::string string){

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
