





    //Test the results in check function
    /*
    cb.chess_map["G4"]=new King(Black);
    
    cb.chess_map["D3"]=new Pawn(White);
  
    //cb.submitMove("A7","A5");//Expect : CANNOT CAUSEcheck
    //  cout<<endl;
    cb.chess_map["F3"]=new Pawn(White);
    cb.changeTurn();
     cb.submitMove("G4","H3");//Expect : CANNOT CAUSEcheck    
    cout<<endl;
    //cb.submitMove("G2", "H5");
   
  cb.submitMove("G4","H5");//Expect : CAN   
  cout<<endl;
    //
    //cb.printBoard();*/
    
    //TEST BISHOP CHECKMOVE
    /*
    cb.chess_map["E4"]=new Bishop(White);

    cb.chess_map["G6"]= new Pawn(White);
    cb.chess_map["F5"] = new Knight(Black);
    cb.chess_map["D3"] = new Queen(Black);
    cb.erasePiece("D2");
    cb.printBoard();
    cb.submitMove("E4","D3");//Expect : CAN
    cout<<endl;
    cb.submitMove("E4","C2");//Expect : CANNOT CAUSE SAME PIECE COLOR
    cout<<endl;
    cb.submitMove("E4", "D2"); //Expect CANNOT in checkmove
    cout<<endl;
    cb.submitMove("E4", "F3");//CAN
    cout<<endl;
    cb.submitMove("E4", "C6");//CAN
    cout<<endl;
    cb.submitMove("E4", "F5"); //CAN
    cout<<endl;
    */

    //TEST CASTLE CHECKMOVE
    /*
    cb.chess_map["E4"]= new Castle(White);
    cb.chess_map["E5"]= new Pawn(Black);
    cb.chess_map["A4"]= new Pawn(Black);   
    cb.chess_map["H4"]= new Pawn(Black);
    cb.chess_map["G4"]= new Pawn(Black);
    
    cb.submitMove("E4","E7");//Cannot checkmove
    cout<<endl;
    cb.submitMove("E4","E5");//Can
    cout<<endl;
    cb.submitMove("E4","A4");//Can
    cout<<endl; 
    cb.submitMove("E4","C6");//Cannot checkMove
    cout<<endl;
    cb.submitMove("E4","H4");//Cannot CheckMove;
    cout<<endl;
    cb.submitMove("E4","G4");//Can
    cout<<endl;
    cb.submitMove("E4","E2");//Cannot same color
    cout<<endl;
    cb.submitMove("E4","E3");//Can
    cout<<endl;*/


    //TEST QUEEEN CHECKMOVE
    /* cb.changeTurn();
    cb.chess_map["E4"]=new Queen(Black);

    cb.chess_map["E5"]= new Pawn(White);
    cb.chess_map["A4"]= new Pawn(White);   
    cb.chess_map["H4"]= new Pawn(White);
    cb.chess_map["G4"]= new Pawn(White);
    
    cb.chess_map["G6"]= new Pawn(Black);
    cb.chess_map["F5"] = new Knight(White);
    cb.chess_map["D3"] = new Queen(White);
    cb.erasePiece("D2");
    cb.printBoard();
    cb.submitMove("E4","D3");//Expect : CAN
    cout<<endl;
    cb.submitMove("E4", "D2"); //Expect CANNOT in checkmove
    cout<<endl;
    cb.submitMove("E4", "F3");//CAN
    cout<<endl;
    cb.submitMove("E4", "C6");//CAN
    cout<<endl;
    cb.submitMove("E4", "F5"); //CAN
    cout<<endl;

 
    cb.submitMove("E4","E6");//Cannot checkmove
    cout<<endl;
    cb.submitMove("E4","E5");//Can
    cout<<endl;
    cb.submitMove("E4","A4");//Can
    cout<<endl; 
    cb.submitMove("E4","H4");//Cannot CheckMove;
    cout<<endl;
    cb.submitMove("E4","G4");//Can
    cout<<endl;
    cb.submitMove("E4","E3");//Can
    cout<<endl;*/

    //TEST KING
    /* cb.changeTurn();
    cb.chess_map["E4"]=new King(Black);
    cb.submitMove("E4","E6");//Cannnot checkmove
    cout<<endl;
    cb.submitMove("E4","E6");//Cannot checkmove
    cout<<endl;
    cb.submitMove("E4","D5");//Can
    cout<<endl;
    cb.submitMove("E4","E5");//Can
    cout<<endl;
    cb.submitMove("E4","F5");//Can
    cout<<endl;
    cb.submitMove("E4","F4");//Can
    cout<<endl;
    cb.submitMove("E4","F3");//Can
    cout<<endl;
    cb.submitMove("E4","E3");//Can
    cout<<endl;
    cb.submitMove("E4","D3");//Can
    cout<<endl;
    cb.submitMove("E4","D4");//Can
    cout<<endl;*/

    //TEST KNIGHT
    /*cb.chess_map["D5"]=new Knight(White);
    cb.submitMove("D5","D6");//Cannnot checkmove
    cout<<endl;
    cb.submitMove("D5","D3");//Cannnot checkmove
    cout<<endl;
    cb.submitMove("D5","E6");//Cannnot checkmove
    cout<<endl;
    cb.submitMove("D5","C7");//Can
    cout<<endl;
    cb.submitMove("D5","E7");//Can
    cout<<endl;
    cb.submitMove("D5","B6");//Can
    cout<<endl;
    cb.submitMove("D5","F6");//Can
    cout<<endl;
    cb.submitMove("D5","F4");//Can
    cout<<endl;
    cb.submitMove("D5","E3");//Can
    cout<<endl;
    cb.submitMove("D5","C3");//Can
    cout<<endl;
    cb.submitMove("D5","B4");//Can
    cout<<endl;*/

    /*//TEST  White Pawn
    cb.chess_map["D4"]=new Pawn(White);
    cb.erasePiece("D2");
    //NO other piece arround
    cb.submitMove("D4","D6");//Can
    cout<<endl;
    cb.submitMove("D4","D5");//Can
    cout<<endl;
    cb.submitMove("D4","D6");//CanNNOOT
    cout<<endl;
    cb.submitMove("D4","D5");//Can
    cout<<endl;
    cb.submitMove("D4","E6");//Cannot
    cout<<endl;
    cb.submitMove("D4","E5");//Cannot
    cout<<endl;
    cb.submitMove("D4","C5");//Cannot
    cout<<endl;
    cb.submitMove("D4","D3");//Cannot
    cout<<endl;
    cb.submitMove("D4","C3");//Cannot
    cout<<endl;
    cb.submitMove("D4","C4");//Cannot
    cout<<endl;
    cb.submitMove("D4","F4");//Cannot
    cout<<endl;
    
    cout<<"put new pieces"<<endl;
  
    cb.chess_map["D5"]= new Pawn(Black);    
    cb.submitMove("D4","D6");//CanNOT
    cout<<endl;

    cb.chess_map["D6"]= new Pawn(Black);
    cb.erasePiece("D5");
    cb.submitMove("D4","D6");//CanNOT
    cout<<endl;
    cb.chess_map["D5"]= new Pawn(Black);    
    cb.chess_map["C5"]= new Pawn(Black);    
    cb.chess_map["E5"]= new Pawn(Black);    
    cb.submitMove("D4","C5");//Can
    cout<<endl;
    cb.submitMove("D4","E5");//Can
    cout<<endl;
    cb.chess_map["E3"]= new Pawn(Black); 
    cb.submitMove("D4","E3");//CanNOT
    cout<<endl;


    cout<<endl<<"TEST Black  Pawn"<<endl;
    cb.changeTurn();
    
    cb.submitMove("E5","D4");//Can
    cout<<endl;
    cb.submitMove("E5","E4");//Can
    cout<<endl;
    cb.submitMove("E5","F4");//CanNOT
    cout<<endl;
    cb.submitMove("E5","E6");//CanNOT
    cout<<endl;
    cb.chess_map["F6"]= new Pawn(White);    
    cb.submitMove("E5","F6");//CanNOT
    cout<<endl;
    cb.submitMove("C5","C3");//Can
    cout<<endl;*/
   



    /*
    cb.changeTurn();
    
    cb.submitMove("A7","A5");//Can
    cout<<endl;
 
    cb.submitMove("A7","A6");//Can
    cout<<endl;*/


/*
    cb.submitMove("A7", "A5");
    cout<<endl;
    //cb.erasePiece("A2");
    cb.submitMove("A1","A4");
    cout<<endl;

    //cb.erasePiece("E2");
    cb.submitMove("F1","C4");
    cout<<endl;
    //  cb.printBoard();



    */




















#include <iostream>

using namespace std;

#include "ChessBoard.h"

int main() {
 
    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;
  
    cout<<endl<<"E2";
    cb.chess_map["E2"]->printFirstMove();
    cout<<endl<<"E7";
    cb.chess_map["E7"]->printFirstMove();
    cout<<endl<<"A2";
    cb.chess_map["A2"]->printFirstMove();

    
    cb.submitMove("E2", "E4");

    cout<<endl<<"A2";
    cb.chess_map["A2"]->printFirstMove();
    cout<<endl<<"E7";
    cb.chess_map["E7"]->printFirstMove();
    cout<<endl<<"E4";
    cb.chess_map["E4"]->printFirstMove();
   
  
    cb.submitMove("E7", "E6");
    cout << endl;

    cout<<endl<<"A2";
    cb.chess_map["A2"]->printFirstMove();
    cout<<endl<<"E6";
    cb.chess_map["E6"]->printFirstMove();
    cout<<endl<<"E4";
    cb.chess_map["E4"]->printFirstMove();
    cout<<endl<<"D2";
    cb.chess_map["D2"]->printFirstMove();
   

    cb.submitMove("D2", "D4");

        cout<<endl<<"A2";
    cb.chess_map["A2"]->printFirstMove();
    cout<<endl<<"E6";
    cb.chess_map["E6"]->printFirstMove();
    cout<<endl<<"E4";
    cb.chess_map["E4"]->printFirstMove();
    cout<<endl<<"D4";
    cb.chess_map["D4"]->printFirstMove();
    /* cb.submitMove("D7", "D5");
       cout << endl;

       cb.submitMove("B1", "C3");
   cb.submitMove("F8", "B4");
   cout << endl;
   
    

    
    cb.submitMove("F1", "D3");

    cb.printBoard();


    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;
    */
  return 0;  
}

















