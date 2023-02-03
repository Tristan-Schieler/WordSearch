#include "wordBoard.h"
#include "FileReader.h"

int main(int argc, char *argv[])
{
    FileReader boardFile;
    std::vector<std::string> words = boardFile.read(argv[1]);

    WordBoard game(10,10);
    game.createBoard(words);
    game.printBoard();

    return 0;
}