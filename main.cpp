#include "wordBoard.h"
#include "FileReader.h"

int main()
{
    FileReader boardFile;
    std::vector<std::string> words = boardFile.read("BoardFiles/PokemonGen1.txt");

    WordBoard game(10,10);
    game.createBoard(words);
    game.printBoard();

    return 0;
}