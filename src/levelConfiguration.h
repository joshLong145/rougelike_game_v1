#ifndef levelConfiguration_h
#define levelConfiguration_h

#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <memory>
#include <fstream>
#include <regex>
#include "loadLevel.h"
#include "fly.h"
#include "Ghost.h"
#include "turret.h"

class envriormentReading{
public:
    bool openFilesForReading(std::vector<std::string> fileNames);
    std::map<std::string,std::vector<std::vector<std::string>>> readFileData();
    void parseFileData(std::map<std::string,std::vector<std::vector<std::string>>> &fileData);

private:
    std::vector<std::shared_ptr<std::ifstream>> files;
};

class enemyReading{
public:
    bool openFilesForReading(std::vector<std::string> fileNames);
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> readFileData();
private:
    std::vector<std::shared_ptr<std::ifstream>> files;

};

class initilizeLevels{
public:
    std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> createAndReturnLevels();
private:
    void parseEnemyData(std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> &enemyData);
    std::map<std::string,std::vector<std::vector<std::string>>> rawGameLevels;
    //stores senemy data patsed from txt files
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> rawEnemies;

};

#endif
