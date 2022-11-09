#include "wordBoard.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

WordBoard::WordBoard(int height, int width) :
    wordBoard_(width, std::vector<char>(height,'#'))
{}

WordBoard::Word::Word(std::pair<uint32_t, uint32_t> position, Direction dir) :
    position(position),
    dir(dir)
{}

void WordBoard::createBoard(std::vector<std::string> words)
{   
    //generate seed for random numbers
    std::srand((unsigned int)std::time(nullptr));

    while(!words.empty())
    {
        //radom word in list
        uint32_t wordIndex = std::rand() % (words.size());
        std::string word = words.at(wordIndex);
        
        //variables for placment of word
        uint32_t xBoardPos, yBoardPos;
        std::pair<uint32_t, uint32_t> postion;
        Direction dir;
        
        //used to cancel out of finding placement for too many tries
        uint32_t numIterations = 0;
        const uint32_t maxNumberOfIterations = 1000;

        do{
            //random spot in board
            xBoardPos = std::rand() % (wordBoard_.size());
            yBoardPos = std::rand() % (wordBoard_[xBoardPos].size());
            postion = std::make_pair(xBoardPos,yBoardPos);

            //random direction
           dir = static_cast<Direction>(std::rand() % static_cast<int>(Direction::MAXSIZE));
           numIterations++;

            if(numIterations >= maxNumberOfIterations)
                break;

        } while (!validPlacement(word, postion, dir));
    
        //if loop above reached max iterations it cant be placed on board
        if(numIterations < maxNumberOfIterations)
        {
            placeWordOnBoard(word, postion, dir);
            wordsInBoard_.insert({word, Word(postion, dir)});
            wordList_.insert(word);
        }
        
        //dont put word on board twice
        words.erase(words.begin() + wordIndex);
    }

    fillRestOfBoard();
}

bool WordBoard::checkWord(const std::string word, const std::pair<uint32_t,uint32_t> position, const Direction dir)
{
    if(wordsInBoard_.count(word))
    {
        Word boardWord = wordsInBoard_.at(word);
        if(position == boardWord.position && dir == boardWord.dir)
        {
            wordList_.erase(word);
        }
    }

    return false;
}

void WordBoard::printBoard()
{
    for(int i = 0 ; i < wordBoard_[0].size() ; ++i)
    {
        for(int j = 0 ; j < wordBoard_.size() ; ++j)
        {
            std::cout << wordBoard_[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(auto& word : wordList_)
    {
        std::cout << word << " ";
    }  
    std::cout << std::endl;
}

bool WordBoard::validPlacement(const std::string& word, std::pair<uint32_t,uint32_t> position, const Direction& dir)
{
    //check if there is are letters in the path of new word
    bool wrongLetters = false;
    for(uint32_t w = 0 ; w < word.size() ; incrementBoardPos(position, dir), ++w)
    {
        //check bounds
        if(position.first < 0 || position.first >= wordBoard_.size() 
        || position.second < 0 || position.second >= wordBoard_[position.first].size())
            return false;

        //check for letter in way
        if(wordBoard_[position.first][position.second] != '#'
        && wordBoard_[position.first][position.second] != word.at(w))
        {
            wrongLetters = true;
            break;
        }
    }

    //not a valid placement if there are wrong letters
    return !wrongLetters;
}

void WordBoard::placeWordOnBoard(const std::string& word, std::pair<uint32_t,uint32_t> position, const Direction& dir)
{
    for(auto& ch : word)
    {
        wordBoard_[position.first][position.second] = ch;
        incrementBoardPos(position, dir);
    }
}

void WordBoard::incrementBoardPos(std::pair<uint32_t,uint32_t>& position,  const Direction& dir)
{
    switch(dir)
    {
        case Direction::UP:
            position.second += 1;
            break;
        case Direction::DOWN:
            position.second -= 1;
            break;
        case Direction::LEFT:
            position.first -= 1;
            break;
        case Direction::RIGHT:
            position.first += 1;
            break;
        case Direction::UPRIGHT:
            position.second += 1;
            position.first += 1;
            break;
        case Direction::DOWNRIGHT:
            position.second += 1;
            position.first -= 1;
            break;
        case Direction::DOWNLEFT:
            position.second -= 1;
            position.first += 1;
            break;
        case Direction::UPLEFT:
            position.second -= 1;
            position.first -= 1;
            break;
    }
}

void WordBoard::fillRestOfBoard()
{
    //generate seed for random letters
    std::srand((unsigned int)std::time(nullptr));

    for(auto& vec : wordBoard_)
    {
        for(auto& ch : vec)
        {
            if(ch == '#')
            {
                ch = 'a' + std::rand() % 26;
            } 
        }
    }
}