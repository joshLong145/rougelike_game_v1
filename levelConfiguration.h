#include<map>
#include<string>
#include <vector>
#include <memory>
#include <fstream>
#include <regex>

class fileReading{
public:
    bool openFilesForReading(std::vector<std::string> fileNames);
    std::map<std::string,std::vector<std::vector<std::string>>> readFileData();
    void parseFileData(std::map<std::string,std::vector<std::vector<std::string>>> &fileData);

private:
    std::vector<std::shared_ptr<std::ifstream>> files;
};
