//
//  stock.cpp
//  StockCloud_oF
//
//  Created by Surya Mattu on 14/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "stock.h"

//Stock:: Stock(string code, string name, float lastTrade, float marketCap, float averageDailyVolume, string lastTradedate) 
Stock:: Stock()
{

    code ="NA";
    name= "NA";
    lastTrade= 0;
    marketCap = 0;
    averageDailyVolume= 0;
    lastTradedate= "NA";
    

    
}

std::string Stock:: getCode(){
    return code;
}

void Stock::setCode(std::string code){
    this->code = code;
}

std::string Stock:: getLastTradeDate(){
    return lastTradedate;
}

void Stock:: setLastTradeDate(std::string lastTradeDate){
    this->lastTradedate = lastTradeDate;
}

std::string Stock:: getName(){
    return name;
}

void Stock:: setName(std::string name){

    this->name = name;
}

float Stock:: getLastTrade(){
    return lastTrade;
}

void Stock:: setLastTrade(float lastTrade){
    
    this->lastTrade = lastTrade;
}

float Stock:: getMarketCap(){
    
    return marketCap;
}

void Stock:: setMarketCap(float marketCap){
    this->marketCap = marketCap;
}

float Stock:: getAverageDailyVolume(){
    return averageDailyVolume;
}

void Stock:: setAverageDailyVolume(float averageDailyVolume){
    this->averageDailyVolume = averageDailyVolume;
}

