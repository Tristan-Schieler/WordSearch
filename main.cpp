#include "WordBoard/wordBoard.h"
#include "Utils/FileReader.h"

int main()
{
    FileReader boardFile;
    std::vector<std::string> words = boardFile.read("Utils/BoardFiles/PokemonGen1.txt");

    WordBoard game(10,10);
    game.createBoard(words);
    game.printBoard();

    return 0;
}