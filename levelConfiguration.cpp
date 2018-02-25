#include "levelConfiguration.h"
#include <algorithm>    // std::random_shuffle
#include <stdlib.h> // rand()

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


void  initilizeLevels::parseEnemyData(std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> &enemyData){

    std::vector<std::string> EnemyTextFiles = {"enemiesLevel1.txt"};

    //open and load files into memory.
    enemyReading enemies;
    enemies.openFilesForReading(EnemyTextFiles);
    rawEnemies = enemies.readFileData();

    //cycle through all rawEnemy data and parse into game objects
    for(auto enemy : rawEnemies){
        std::string enemyType = std::get<1>(enemy.second);
        std::string room = std::get<0>(enemy.second);
        int xValue = std::get<2>(enemy.second);
        int yValue = std::get<3>(enemy.second);
        int velocity = std::get<4>(enemy.second);

        //depending on the enemy create a ptr obj of it and put it into its corresponding room.
        if(enemyType == "fly"){
            enemyData[enemy.first][room].push_back(std::make_unique<fly>(xValue, yValue, velocity));
        }
        if(enemyType == "ghost"){
            enemyData[enemy.first][room].push_back(std::make_unique<Ghost>(xValue, yValue, velocity));
        }

        if(enemyType == "turret"){
            enemyData[enemy.first][room].push_back(std::make_unique<Turret>(xValue, yValue, velocity));
        }
    }
}

std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> initilizeLevels::createAndReturnLevels(){
    std::map<std::string,std::vector<std::unique_ptr<loadLevel>>>  levelData;
    std::vector<std::string> enviormentLevels = {"level1.txt", "level2.txt"};

    //obj for parsing enviorment data.
    envriormentReading enviorment;
    enviorment.openFilesForReading(enviormentLevels);
    rawGameLevels = enviorment.readFileData();
    enviorment.parseFileData(rawGameLevels);

    //create enmies from raw enemy data
    std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> enemyData;
    parseEnemyData(enemyData);

    for(auto level : rawGameLevels){
        int roomNumber = 1;
        for(unsigned int i = 0; i < level.second.size(); i++){
           levelData[level.first].push_back(std::make_unique<loadLevel>(rawGameLevels[level.first][i],
                                                                         enemyData[level.first]["room"+std::to_string(roomNumber)]));
            roomNumber++;
        }
        //
        std::random_shuffle(levelData[level.first].begin() + 1, levelData[level.first].end() -1); // need to keep the first and last room the correct place
    }

    return levelData;

}


