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
#include "bossOne.h"

class envriormentReading{
public:

    /*
      NAME:
        OpenFilesForReading

      SYNOPSIS:
        OpenFilesForReading(std::vector<std::string> a_fileNames);

      DESCRIPTION:
        Loads all files corepsonding to levels into fileReader objects within memory.
        for later use.

      RETURNS:
        bool

      AUTHOR:
        Josh Long
    */
    bool OpenFilesForReading(std::vector<std::string> a_fileNames);

    /*
      NAME:
        ReadFileData

      SYNOPSIS:
        std::map<std::string,std::vector<std::vector<std::string>> ReadFileData();

      DESCRIPTION:
        Parses all level files and stores them within a map that
        has a key of a string, example "level1" and a value of the characters correpsonding to the level enviorment.

      RETURNS:
        std::map<std::string, std::vector<std::vector<std::string>>

      AUTHOR:
        Josh Long
    */
    std::map<std::string,std::vector<std::vector<std::string>>> ReadFileData();

    /*
      NAME:
        ParseFileData

      SYNOPSIS:
        void ParseFileData(std::map<std::string, std::vector<std::vector<std::string>>> &a_fileData);
                           std::map<std::string, std::vector<std::vector<std::string>>> &a_fileData ->
                           Reference to the map containing all level data.

      DESCRIPTION:
        Takes the intermediate map of level data and parses all useless formatting characters from it.

       RETURNS:
         None

       AUTHOR:
         Josh Long
    */
    void ParseFileData(std::map<std::string,std::vector<std::vector<std::string>>> &a_fileData);

private:
    std::vector<std::shared_ptr<std::ifstream>> m_files;
};

class enemyReading{
public:
    /*
      NAME:
        OpenFilesForReading

      SYNOPSIS:
        bool OpenFilesForReading(std::vector<std::string> a_fileNames)
                            std::vector<std::string> a_fileNames -> name of files contating data on enemies.

      DESCRIPTION:
        Opens all files relating to enemy data and parses them. data is formated as <LEVEL> <ROOM> <ENEMY> <XPOS> <YPOS> <VEL>

      RETURNS:
        bool -> on true, sucessful load. false, errors occured.

      AUTHOR:
        Josh Long
    */
    bool OpenFilesForReading(std::vector<std::string> fileNames);

    /*
      NAME:
        ReadFileData

      SYNOPSIS:
        std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> ReadFileData();

      DESCRIPTION:
        Returns a multimap containing the parsed data ready to be read and enterpreted by
        the room loading modules.

      RETURNS:
        std::multimap<std::string,std::tuple<std::string, std::string, int, int, int>>

      AUTHOR:
        Josh Long
    */
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> ReadFileData();

private:
    std::vector<std::shared_ptr<std::ifstream>> m_files;

};

class initilizeLevels{
public:

    /*
      NAME:
        CreateAndReturnLevels

      SYNOPSIS:
        std::map<std::string, std::vector<std::unique_ptr<loadLevel>>> CreateAndReturnLevels();

      DESCRIPTION:
        Returns a map that contains room objects that can be used normally throughout the application lifetime.
        data is in the format <LEVEL NAME> <loadLevel Obj>

      RETURNS:
        std::map<std::string, std::vector<std::unique_ptr<loadLevel>>>

      AUTHOR:
       Josh Long
    */
    std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> CreateAndReturnLevels();
private:

    /*
      NAME:
        ParseEnemyData

      SYNOPSIS:
        void ParseEnemyData(std::map<std::string,std::map<std::string,:std::vector<std:unique_ptr<baseEnemy>>>> &a_enemyData);
                            std::map<std::string, std::map<std::string, std::vector<std::unique_ptr<baseEnemy>>>> &a_enemyData ->
                            Reference to all enemies within the current level. formated as:
                            <LEVEL> <ROOM> <enemies for each room>

      RETURNS:
        void

      AUTHOR:
        Josh Long
    */
    void ParseEnemyData(std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> &enemyData);

    /*
      NAME:
        RawGameLevels

      SYNOPSIS:
        std::map<std::string, std::vector<std::vector<std::string>>> RawGameLevels();

      DESCRIPTION:
        Returns a map with the correpsonding structure:
        <LEVEL> <VECTOR OF VECTORS HOLDING STRINGS>

     RETURNS:
       std::map<std::string, std::vector<std::vector<std::string>>> -> map of level ids and strings with each level in string form.

    AUTHOR
      Josh Long
    */
    std::map<std::string,std::vector<std::vector<std::string>>> rawGameLevels;

    /*
      NAME:
        RawEnemies

      SYNOPSIS:
        std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> RawEnemies();

      DESCRIPTION:
        Returns a map that has all enemy data within it. 
    */
    std::multimap<std::string, std::tuple<std::string, std::string, int, int, int>> rawEnemies;

};

#endif
