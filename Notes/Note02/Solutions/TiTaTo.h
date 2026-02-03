#ifndef TITATO_H
#define TITATO_H

#include <iostream> //ostream
#include <string> //string
#include <sstream> //stringstream
#include <cctype> //isdigit()
#include "Multi.h"

namespace dsn 
{
    class TicTacToe : public Multi 
    {
        private:
        std::string board;
        int player;
        static const std::string tokens;

        bool horizontal() const 
        {
            for(int i = 0;i <= 6;i += 3)
            {
                if(board[i] == board[i+1] && board[i] == board[i+2] && board[i] != '*')
                {
                    return true;
                }
            }
            return false;
        }

        bool vertical() const 
         {
            for(int i = 0;i <= 2;i += 1)
            {
                if(board[i] == board[i+3] && board[i] == board[i+6] && board[i] != '*')
                {
                    return true;
                }
            }
            return false;
        }

        bool diagonal() const 
        {
            bool dd = board[0] == board[4] && board[0] == board[8];
            bool id = board[2] == board[4] && board[2] == board[6];
            return (dd || id) && board[4] != '*';
        }

        bool available() const 
        {
            for(int i = 0;i < 9;i += 1)
            {
                if(board[i] == '*') {return true;}
            }
            return false;
        }

        public:
        //default constructor
        TicTacToe() 
        {
            board = std::string(9,'*');
            player = 0;
        }

        //copy constructor
        TicTacToe(const TicTacToe& obj)
        {
            board = obj.board;
            player = obj.player;
        }

        TicTacToe& operator=(const TicTacToe& rhs)
        {
            if(this != &rhs)
            {
                board = rhs.board;
                player = rhs.player;
            }
            return *this;
        }

        virtual ~TicTacToe() {}
        
		//Method: intro()
		//Description: provides name, 
		//descriptions, and instructions for 
		//the game   
		std::string intro() const override
        {
            return "TIC-TAC-TOE";
        } 

		//Method: move(str) 
		//Dscription: validates move input 
		//and performs move for the current 
		//player  
		bool move(std::string str) override
        {
            if(str.length() == 1 && isdigit(str[0]) && str[0] != '9')
            {
                int dg = str[0] - '0';

                if(board[dg] == '*') 
                {
                    board[dg] = tokens[player];
                    return true;
                }
            }
            return false;
        }

		//Method: playable()
		//Description: checks if the game is
		//playable
		bool playable() const override
        {
            return available() && !won();
        }

		//Method: won() 
		//Description: checks if the current 
		//player won the game
		bool won() const override
        {
            return horizontal() || vertical() || diagonal();
        }

		//Method: next()
		//Description: changes the current 
		//player 
		void next() override {player = (player + 1) % 2;}

		//Method: current()
		//Dscription: retrieve the identification 
		//of the current player 
		std::string current() const override 
        {
            return "Player " + std::to_string(player + 1);
            //return (player == 0)?("Player 1"):("Player 2");
            /*
            if(player == 0) {return "Player 1";}
            else {return "Player 2";}
            */
        }

        std::string toString() const override 
        {
            std::stringstream out;

            out << current() << ":\n\n";

            for(int i = 0;i < 9;i += 1)
            {
                out << " ";
                if(board[i] == '*') {out << " ";}
                else {out << board[i];}
                out << " ";

                if((i + 1) % 3 != 0) {out << "|";}
                else {out << "\n";}
            }
            return out.str();
        }
    };

    const std::string TicTacToe::tokens = "OX";
}

#endif