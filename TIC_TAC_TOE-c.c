//checking algorithm and printing algorithm
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
    void clrscr()
    {
        system("@cls||clear");
    }
    void delay(unsigned int mseconds)
    {
        clock_t goal = mseconds + clock();
        while (goal > clock());
    }


void main()
{
    char ttt[3][3] = {'_','_','_','_','_','_',' ',' ',' '};//left spaces for the last three boxes in the grid
    char p1 = 'x',p2 = 'o';
    int tch[3][3] = {0,0,0,0,0,0,0,0,0};
    int x,y,x1,y1,i,j,cp1 = 9,turn;
    
    clrscr();
    printf("Welcome to the game of Tic Tac Toe. Created by Adwait.\n");
    delay(1800);
    clrscr();
    printf("Please decide who will be the first player.\n");
    delay(1800);
    clrscr();
    printf("Decided?.. Lets proceed then.\n");
    delay(1799);
    clrscr();

    for(turn = 1;turn <= 9;turn++)//running the loops for 9 times because it is the maximum moves the game will have
    {   
        if(turn%2 != 0)
        {   
            re1: //checkpoint for wrong input
            
            printf("\nEnter the coords for your move player 1:\nx: ");//taking input for the coords for the desired box
            scanf("%d",&x);
            printf("y: ");  
            scanf("%d",&y);
            if (x>3||y>3||x<0||y<0)
            {
                clrscr();
                printf("Enter the coordinates properly.");
                delay(200);
                goto re1;
            }
            if(ttt[x-1][y-1] == '_' || ttt[x-1][y-1] == ' ')//checking if the places are valid
            {
                ttt[x-1][y-1] = p1;
                tch[x-1][y-1] = 1;
                
            }
            else if(ttt[x-1][y-1] == 'o' || ttt[x-1][y-1] == 'x')//checking if the places are occupied
            {
                printf("\nThis move has already made earlier\n");
                goto re1; //going to checkpoint re1 to redo the step
            }
            

               
            //-------------------------------------
            for(i=0;i<3;i++)//printing for the table with inputs
            {
                for(j=0;j<3;j++)
                {   
                    if(i>=0&&i<2) // for printing the given below pattern for 0,1 times
                    {
                        if(j>0&&j<3)//prints |___ for 1,2 times
                            printf("|_%c_",ttt[i][j]);
                        else if(j==0)//printing the pattern ___ for every start of line
                            printf("_%c_",ttt[i][j]);
                    }               
                }
                if(i>=0&&i<2)//special case for the last line
                    printf("\n");
                else if(i==2)//special case for the last line
                {
                    printf(" %c | %c | %c ",ttt[i][0],ttt[i][1],ttt[i][2]); // the last ine of the pattern to be printed
                    break;
                }
            }
            //--------------------------------------      
            if (tch[0][0] == 1 && tch[0][1] == 1 && tch[0][2] == 1 || tch[1][0] == 1 && tch[1][1] == 1 && tch[1][2] == 1 || tch[2][0] == 1 && tch[2][1] == 1 && tch[2][2] == 1 || tch[0][0] == 1 && tch[1][1] == 1 && tch[2][2] == 1 || tch[0][2] == 1 && tch[1][1] == 1 && tch[2][0] == 1 || tch[0][0] == 1 && tch[1][0] == 1 && tch[2][0] == 1 || tch[0][1] == 1 && tch[1][1] == 1 && tch[2][1] == 1 || tch[0][2] == 1 && tch[1][2] == 1 && tch[2][2] == 1)
            { //Checking for if the horizontal rows or the diagonals or the vertical columns respectively
                printf("\nGame won by player 1...\n");
                break;//Killing the loop because the winnrs decided
            }
            else if(turn>6)
            {
            cp1 = 1;
           
            }
            
        }
        
        
        
        else
        {   
            re:
            
            printf("\nEnter the coords for your move player 2:\nx: ");
            scanf("%d",&x1);
            printf("y: ");  
            scanf("%d",&y1);

            if ( x1 > 3 || y1 > 3 || x1 < 0 || y1 < 0)
            {
                clrscr();
                printf("Enter the coordinates properly.");
                delay(200);
                goto re;
            }
            
            if(ttt[x1-1][y1-1] == '_' || ttt[x1-1][y1-1] == ' ')
            {
                ttt[x1-1][y1-1] = p2;
                tch[x1-1][y1-1] = 2;
                
            }
            else if(ttt[x1-1][y1-1] == 'o' || ttt[x1-1][y1-1] == 'x')
            {
                printf("\nThis move has already been made.\n");
                goto re;
            }
        //-------------------------------------
            for(i=0;i<3;i++)//printing for x
            {
                for(j=0;j<3;j++)
                {   
                    if(i>=0&&i<2) // for printing the given below pattern for 0,1 times
                    {
                        if(j>0&&j<3)//prints |___ for 1,2 times
                            printf("|_%c_",ttt[i][j]);
                        else if(j==0)//printing the pattern ___ for every start of line
                            printf("_%c_",ttt[i][j]);
                    }               
                }
                if(i>=0&&i<2)
                    printf("\n");
                else if(i==2)
                {
                    printf(" %c | %c | %c ",ttt[i][0],ttt[i][1],ttt[i][2]); // the last ine of the pattern to be printed
                    break;
                }
            }
        //--------------------------------------
        if (tch[0][0] == 2 && tch[0][1] == 2 && tch[0][2] == 2 || tch[1][0] == 2 && tch[1][1] == 2 && tch[1][2] == 2 || tch[2][0] == 2 && tch[2][1] == 2 && tch[2][2] == 2 || tch[0][0] == 2 && tch[1][1] == 2 && tch[2][2] == 2 || tch[0][2] == 2 && tch[1][1] == 2 && tch[2][0] == 2 || tch[0][0] == 2 && tch[1][0] == 2 && tch[2][0] == 2 || tch[0][1] == 2 && tch[1][1] == 2 && tch[2][1] == 2 || tch[0][2] == 2 && tch[1][2] == 2 && tch[2][2] == 2)
        { 
           printf("\nGame won by player 2...\n");
           break;
        }
        else if(turn>6)
        {
            cp1 = 1;
        }
    }
        
   }
   
   if(cp1 == 1){
        delay(2300);
        printf("\n\nIts a draw\n");
   }
   delay(1200);
   printf("Press enter to quit now...");
   getch();
}