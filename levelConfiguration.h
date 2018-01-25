#include<map>
#include<string>
#include <vector>
#include <tuple>
#include <memory>
#include <fstream>
#include <regex>

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
