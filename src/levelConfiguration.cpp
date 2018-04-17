#include "levelConfiguration.h"
#include <algorithm>    // std::random_shuffle
#include <stdlib.h> // rand()

bool envriormentReading::OpenFilesForReading(std::vector<std::string> fileNames){
    for(auto names : fileNames){
      try{
        m_files.push_back(std::make_unique<std::ifstream>(names));

      }catch(std::ifstream::failure & err){
        return false;

      }
    }
    return true;
}

std::map<std::string,std::vector<std::vector<std::string>>> envriormentReading::ReadFileData(){
    std::map<std::string, std::vector<std::vector<std::string>>> levels;
    for(unsigned int i = 0; i < m_files.size(); i ++){
        std::vector<std::vector<std::string>> level;
        std::vector<std::string> rooms;
        for(std::string line; std::getline((*m_files[i]),line); ){
            if(!(*m_files[i]).eof()){
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

void envriormentReading::ParseFileData(std::map<std::string,std::vector<std::vector<std::string>>> &a_fileData){
  
    std::regex expression("[,]");
    for(auto level = a_fileData.begin(); level != a_fileData.end(); ++level){
        for(auto room = (*level).second.begin(); room != (*level).second.end(); ++room){
            for(auto line = (*room).begin(); line != (*room).end(); ++line){
                (*line) = std::regex_replace((*line),expression, "");
            }
        }
    }
}

bool enemyReading::OpenFilesForReading(std::vector<std::string> a_fileNames){
    for(auto names : a_fileNames){
      /*
        Attempts to open all file buffers into memory.
        If ifstream runs into an error the return false; and the rest of the the data will not be parsed.
      */
      try{
        m_files.push_back(std::make_unique<std::ifstream>(names));

      }catch(std::ifstream::failure &error){
        return false;
      }
    }
    return true;
}

std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> enemyReading::ReadFileData(){
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> enemiesInLevels;

    for(unsigned int i = 0; i < m_files.size(); i++){
        std::string level;

        for(std::string line; std::getline((*m_files[i]),line); ){
            std::istringstream ss(line);
            int xValue, yValue, velocity;
            std::string room, enemy;

            /*
              Each line of file data is expected in the form of <LEVEL> <ROOM> <ENEMY> <XPOS> <YPOS> <VEL>
              if the data is not returned in that way then continue on the the next line.
              or next enemy.
            */
            if(!(ss >> level >> room >> enemy >> xValue >> yValue >> velocity)){ continue; };

            enemiesInLevels.insert(std::pair<std::string, std::tuple<std::string, std::string, int, int, int>>
                           (level, std::make_tuple(room, enemy, xValue, yValue, velocity)));

        }
    }

    return enemiesInLevels;
}


void  initilizeLevels::ParseEnemyData(std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> &enemyData){

    std::vector<std::string> EnemyTextFiles = {"./enemiesLevel1.txt"};

    //open and load files into memory.
    enemyReading enemies;
    enemies.OpenFilesForReading(EnemyTextFiles);
    rawEnemies = enemies.ReadFileData();

    //cycle through all rawEnemy data and parse into game objects
    for(auto enemy : rawEnemies){
        /*!
          Parses the enemy attributes, formated as <LEVEL> <ROOM> <ENEMY> <XPOS> <YPOS> <VEL>
          already parsed this data successfully in another function. so we can garentee that it will be correctly formatted.
        !*/
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

        if(enemyType == "boss_1"){
          enemyData[enemy.first][room].push_back(std::make_unique<bossOne>(xValue,yValue,velocity));
        }
    }
}

std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> initilizeLevels::CreateAndReturnLevels(){
    std::map<std::string,std::vector<std::unique_ptr<loadLevel>>>  levelData;
    // load the files dealing with the level configuation into memory, there will be more of them in the future. 
    std::vector<std::string> enviormentLevels = {"./level1.txt", "./level2.txt"};

    /*!
      creates an envriormentReading object and opens and reads all enemy files into memory.
      once all files are in memory, parse them from all formatting characters and compartmentalizes them into
      loadLevel objs.
    !*/
    envriormentReading enviorment;
    enviorment.OpenFilesForReading(enviormentLevels);
    rawGameLevels = enviorment.ReadFileData();
    enviorment.ParseFileData(rawGameLevels);

    //! create enmies from raw enemy data
    std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> enemyData;
    ParseEnemyData(enemyData);

    for(auto level : rawGameLevels){
        int roomNumber = 1;
        for(unsigned int i = 0; i < level.second.size(); i++){
           levelData[level.first].push_back(std::make_unique<loadLevel>(rawGameLevels[level.first][i],
                                                                         enemyData[level.first]["room"+std::to_string(roomNumber)]));
            roomNumber++;
        }
        //! Randomly shuffles all rooms within the current level. Except for the first and last rooms. they need to stay in place.
        std::random_shuffle(levelData[level.first].begin() + 1, levelData[level.first].end() -1);
       // Need to keep the first and last room the correct place
    }

    return levelData;

}
