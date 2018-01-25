#include "levelConfiguration.h"
#include <iostream>


bool envriormentReading::openFilesForReading(std::vector<std::string> fileNames){
    for(auto names : fileNames){
        files.push_back(std::make_unique<std::ifstream>(names));
    }
    return true;
}

std::map<std::string,std::vector<std::vector<std::string>>> envriormentReading::readFileData(){
    std::map<std::string, std::vector<std::vector<std::string>>> levels;
    for(unsigned int i = 0; i < files.size(); i ++){
        std::vector<std::vector<std::string>> level;
        std::vector<std::string> rooms;
        for(std::string line; std::getline((*files[i]),line); ){
            if(!(*files[i]).eof()){
                if(line.size()){
                    rooms.push_back(line);
                }else{
                    level.push_back(rooms);
                    rooms.clear();
                }
            }
        }
        level.push_back(rooms);
        levels["level" + std::to_string(i+ 1)] = level;
    }

    return levels;
}

void envriormentReading::parseFileData(std::map<std::string,std::vector<std::vector<std::string>>> &fileData){
    std::regex expression("[,]");
    for(auto level = fileData.begin(); level != fileData.end(); ++level){
        for(auto room = (*level).second.begin(); room != (*level).second.end(); ++room){
            for(auto line = (*room).begin(); line != (*room).end(); ++line){
                (*line) = std::regex_replace((*line),expression, "");
            }
        }
    }
}

bool enemyReading::openFilesForReading(std::vector<std::string> fileNames){
    for(auto names : fileNames){
        files.push_back(std::make_unique<std::ifstream>(names));
    }
    return true;
}

std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> enemyReading::readFileData(){
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> enemiesInLevels;

    for(unsigned int i = 0; i < files.size(); i++){
        std::string level;

        for(std::string line; std::getline((*files[i]),line); ){
            std::istringstream ss(line);
            int xValue, yValue, velocity;
            std::string room, enemy;

            if(!(ss >> level >> room >> enemy >> xValue >> yValue >> velocity)){ break; };

            enemiesInLevels.insert(std::pair<std::string, std::tuple<std::string, std::string, int, int, int>>
                           (level, std::make_tuple(room, enemy, xValue, yValue, velocity)));

        }
    }

    return enemiesInLevels;
}
