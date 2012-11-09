//
//  stock.h
//  StockCloud_oF
//
//  Created by Surya Mattu on 14/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
//This is the stock class that contains all the properties related to a stock object

#ifndef StockCloud_oF_stock_h
#define StockCloud_oF_stock_h
#include <iostream>
#include <string>
#include "ofUtils.h"


class Stock{
    public:
       // Stock(string code, string name, float lastTrade, float marketCap, float averageDailyVolume, string lastTradedate);
    Stock();

    std::string getCode();
    void setCode(std::string code);
    
    std::string getName();
    void setName(std::string name);
    
    std::string getLastTradeDate();
    void setLastTradeDate (std::string lasTradeDate);
    
    float getLastTrade();
    void setLastTrade(float lastTrade);
    
    float getMarketCap();
    void setMarketCap(float marketCap);
    
    float getAverageDailyVolume();
    void setAverageDailyVolume(float averageDailyVolume);    
    
    
    private:
    std::string code;
    std::string name;
    std::string lastTradedate;
    float lastTrade;
    float marketCap;
    float averageDailyVolume;
    
};

#endif
