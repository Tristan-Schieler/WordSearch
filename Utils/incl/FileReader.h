#include <string>
#include <vector>

class FileReader
{
    public:

        FileReader(){};

        std::vector<std::string> read(std::string pathToFile);

    private:

        virtual bool correctFormat(std::string& line);

};