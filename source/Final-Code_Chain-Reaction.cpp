//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   CHAIN REACTION   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  RUTVIJ SHANKARWAR    140040025    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   KRISHNA CHAITANYA    140070055   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   DHANANJAY UPPALWAD    140070016   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//

#include<simplecpp>
/*VARIABLE USED :
  ^^^^^^^^^^^^^
        playerState[][]     ..... Represents the the orbs belonging to the player
        orbCount [][]       ..... Represents the no. of the orbs inthe cell
        m                   ..... represents the position of mouse click
        mx                  ..... represents the x position of mouse click
        my                  ..... represents the y position of mouse click
        player              ..... represents the turn of player
        criticalMass[][]    ..... represents critical mass of cell
        count               ..... stores the the total no. of orbs
        playerCount[]       ..... stores the no. orbs corresponding toplayer
*/

int criticalMass[8][6]={{1,2,2,2,2,1},{2,3,3,3,3,2},
{2,3,3,3,3,2},{2,3,3,3,3,2},{2,3,3,3,3,2},
{2,3,3,3,3,2},{2,3,3,3,3,2},{1,2,2,2,2,1}};
void explode(int playerState[8][6],int orbCount[8][6],int x, int y,int player);  // THIS FUNCTION IS FOR EXPOLSION AFTER  REACHING THE CRICTICAL MASS OF THE RESPECTIVE CELL
void expand(int playerState[8][6],int orbCount[8][6],int x, int y,int player);    // THIS FUNCTION IS TO INCREASE THE NO. OF ORBS IF THE CELL DOES NOT REACHES THE CRITICALMASS

void draw_grid(int i,int j,int k)                       //This draws the grid and changes the color the grid according to the player
{   beginFrame();
    Line h1(0,0,600,0),h2(0,100,600,100),               // "h" is the horizontal lines and "v" is the vertical lines
    h3(0,200,600,200),h4(0,300,600,300),
    h5(0,400,600,400),h6(0,500,600,500),
    h7(0,600,600,600),h8(0,700,600,700),
    h9(0,800,600,800);
    Line v1(0,0,0,800),v2(100,0,100,800),
    v3(200,0,200,800),v4(300,0,300,800),
    v5(400,0,400,800),v6(500,0,500,800),
    v7(600,0,600,800);
    h1.setColor(COLOR(255*i,255*j,255*k)),h2.setColor(COLOR(255*i,255*j,255*k)),
    h3.setColor(COLOR(255*i,255*j,255*k)),h4.setColor(COLOR(255*i,255*j,255*k)),
    h5.setColor(COLOR(255*i,255*j,255*k)),h6.setColor(COLOR(255*i,255*j,255*k)),
    h7.setColor(COLOR(255*i,255*j,255*k)),h8.setColor(COLOR(255*i,255*j,255*k)),
    h9.setColor(COLOR(255*i,255*j,255*k));
    v1.setColor(COLOR(255*i,255*j,255*k)),v2.setColor(COLOR(255*i,255*j,255*k)),
    v3.setColor(COLOR(255*i,255*j,255*k)),v4.setColor(COLOR(255*i,255*j,255*k)),
    v5.setColor(COLOR(255*i,255*j,255*k)),v6.setColor(COLOR(255*i,255*j,255*k)),
    v7.setColor(COLOR(255*i,255*j,255*k));
    h1.imprint(),h2.imprint(),
    h3.imprint(),h4.imprint(),
    h5.imprint(),h6.imprint(),
    h7.imprint(),h8.imprint(),h9.imprint();
    v1.imprint(),v2.imprint(),
    v3.imprint(),v4.imprint(),
    v5.imprint(),v6.imprint(),v7.imprint();
    endFrame();
}


void explode(int playerState[8][6],int orbCount[8][6],int x,int y,int player)
{
    beginFrame();
    if(orbCount[x][y]>criticalMass[x][y])                                   // orbCount[x][y] refers to the no. of orbs in the cell of "x"th row and "y"th column
    {                                                                       //if orbCount[x][y] exceeds the critical mass the the cell becomes empty and the orbs goes to
        orbCount[x][y]=0;playerState[x][y]=0;                               //   vertical and horizontal directions and encapulate the other orbs chages to the current players
        Rectangle h(y*100+50,x*100+50,90,90);                               //    color.
        h.setColor(COLOR(255,255,255));
        h.setFill();
        h.imprint();
        if(x-1>=0) {orbCount[x-1][y]++;playerState[x-1][y]=player;}         // the orbs will explode to possible vertical and horizontol directions
        if(x+1<=7) {orbCount[x+1][y]++;playerState[x+1][y]=player;}
        if(y-1>=0) {orbCount[x][y-1]++;playerState[x][y-1]=player;}
        if(y+1<=5) {orbCount[x][y+1]++;playerState[x][y+1]=player;}
        if((x-1)>=0&&orbCount[x-1][y]>criticalMass[x-1][y])                 // after explosion the adjacent cells will explode or expand according to the respective crutical mass
            explode(playerState,orbCount,x-1,y,player);
        else if((x-1)>=0&&orbCount[x-1][y]<=criticalMass[x-1][y])
            expand(playerState,orbCount,x-1,y,player);
         if((x+1)<=7&&orbCount[x+1][y]>criticalMass[x+1][y])
            explode(playerState,orbCount,x+1,y,player);
        else if((x+1)>=0&&orbCount[x+1][y]<=criticalMass[x+1][y])
            expand(playerState,orbCount,x+1,y,player);
         if((y-1)>=0&&orbCount[x][y-1]>criticalMass[x][y-1])
            explode(playerState,orbCount,x,y-1,player);
        else if((y-1)>=0&&orbCount[x][y-1]<=criticalMass[x][y-1])
            expand(playerState,orbCount,x,y-1,player);
        if((y+1)<=5&&orbCount[x][y+1]>criticalMass[x][y+1])
            explode(playerState,orbCount,x,y+1,player);
        else if((y+1)<=5&&orbCount[x][y+1]<=criticalMass[x][y+1])
            expand(playerState,orbCount,x,y+1,player);
    }
    endFrame();
}


void expand(int playerState[8][6],int orbCount[8][6],int x, int y,int player)
{
    beginFrame();

    if(orbCount[x][y]==1)
    {
            playerState[x][y]=player;                   // After the explosion if the adjacent cell is empty then the orb will occupy it.
            Circle g(y*100+50,x*100+50,15);
             g.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
             g.setFill();
             g.imprint();
    }

   if(orbCount[x][y]==2||orbCount[x][y]==3)
   {                                                // for expantion this will remove the single orb and replaces with double or triple orbs
    playerState[x][y]=0;
    Rectangle w(y*100+50,x*100+50,90,90);
    w.setColor(COLOR(255,255,255));
    w.setFill();
    w.imprint();
   }

   if(((x>=1&&x<=6)||(y>=1&&y<=4))&&orbCount[x][y]==2)
    {
        Circle c1(y*100+40,x*100+50,15);
        Circle c2(y*100+60,x*100+50,15);
        playerState[x][y]=player;
        c2.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
        c1.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
        c1.setFill();
        c2.setFill();
        c1.imprint();
        c2.imprint();
    }

   else if(((x>=1&&x<=6)&&(y>=1&&y<=4))&&orbCount[x][y]==3)
    {
       Circle a1(y*100+50,x*100+40,15);
       Circle a2(y*100+40,x*100+60,15);
       Circle a3(y*100+60,x*100+60,15);
        playerState[x][y]=player;
        a3.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
        a2.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
        a1.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
        a1.setFill();
        a2.setFill();
        a3.setFill();
        a1.imprint();
        a2.imprint();
        a3.imprint();
    }

    if(orbCount[x][y]>criticalMass[x][y])                       // afer placing the orbs if the cell reache the critical mass if the extra orb is placed by the corresponding
        explode(playerState,orbCount,x,y,player);               //   player then it will call the explode funtion.

}

void playgame(int p)
{
    int playerState[8][6];     //represents cell belonging to player
    int orbCount[8][6];    //represents no of rbs inthe cell

    for(int nrow=0;nrow<8;nrow++)
    {
        for(int ncol=0;ncol<6;ncol++)
        {
            playerState[nrow][ncol]=0;  //initilizing the cell state to be zero which means that cell donot belong any of the player
            orbCount[nrow][ncol]=0;     //initilizing no of orbs in th cell to be zero
        }
    }

    int player=1;

    while(true)
    {
    wrongCell:

        draw_grid(player%2,(player/2)%2,((player/2)/2)%2);
        int iclick=getClick();                                  // iclick will take the position of the mouse click
        int xpos=iclick/65536;                                  // xpos and the y pos will give the x and y position respectively of the mouse click
        int ypos=iclick%65536;
        int r_click=ypos/100;                                    // r_click and c_click will take value of row and the column in which it was clicked
        int c_click=xpos/100;

        if(playerState[r_click][c_click]==0)
        {                                                       // if the cell is empty it places an orb
            playerState[r_click][c_click]=player;
            orbCount[r_click][c_click]++;
            Circle c(c_click*100+50,r_click*100+50,15);
            c.setColor(COLOR(255*(player%2),255*((player/2)%2),255*(((player/2)/2)%2)));
            c.setFill();
            c.imprint();

        }

        else if(playerState[r_click][c_click]==player)
        {                                                   // if cell is not empty and if the player clicks in the cell corresponding cell and it is not reached the
        orbCount[r_click][c_click]++;                       //    critical mass then it will take to expnasion function
        expand(playerState,orbCount,r_click,c_click,player);
        }

        else if(playerState[r_click][c_click]!=player)          //  if the player clicks on the cell corresponding other player then it goes to the label : wrongCell
            goto wrongCell;

    int count=0;int playerCount[4]={0,0,0,0};

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<6;j++)
        {
            count=count+orbCount[i][j];
        }
    }

    if(p==2)
    {
        for(int k=1;k<=2;k++)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<6;j++)
                {                                                                       // every time it counts the no. of orbs corresponding players
                    if(orbCount[i][j]!=0&&playerState[i][j]==k)
                        playerCount[k-1]=playerCount[k-1]+orbCount[i][j];
                }
            }
        }
        if(count<=2)
        {
            if(player==1)
                player=2;
            else if(player==2)
                player=1;
        }
        else if(count>2)
        {
            if(player==1&&playerCount[1]!=0)
                player=2;                           //if the orbs corresponding to the player is 0 the that player will be eliminated otherwise player will swap to next player
            else if(player==1&&playerCount[1]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();

                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==2&&playerCount[0]!=0)
                player=1;
            else if(player==2&&playerCount[0]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<endl<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }

        }
    }
                                                        // if the the no.of players are 3 then this will excuete
    else if(p==3)
    {
        for(int k=1;k<=3;k++)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<6;j++)
                {
                    if(orbCount[i][j]!=0&&playerState[i][j]==k)
                    playerCount[k-1]=playerCount[k-1]+orbCount[i][j];
                }
            }
        }
        if(count<=3)
        {
            if(player==1)
                player=2;
            else if(player==2)
                player=3;
            else if(player==3)
                player=1;
        }
        else if(count>=3)
        {
            if(player==1&&playerCount[1]!=0)
                player=2;
            else if(player==1&&playerCount[1]==0&&playerCount[2]!=0)
            {
                player=3;
            }
            else if(player==1&&playerCount[1]==0&&playerCount[2]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==2&&playerCount[2]!=0)
            {
                player=3;
            }
            else if(player==2&&playerCount[2]==0&&playerCount[0]!=0)
            {
                player=1;
            }
            else if(player==2&&playerCount[2]==0&&playerCount[0]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==3&&playerCount[0]!=0)
                player=1;
            else if(player==3&&playerCount[0]==0&&playerCount[1]!=0)
            {
                player=2;
            }
            else if(player==3&&playerCount[0]==0&&playerCount[1]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS";
                cout<<"GAME OVER"<<endl;
                break;
            }
        }
    }
    else if(p==4)
    {                                               // if the no.of players are 4  then this will excute.
        for(int k=1;k<=4;k++)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<6;j++)
                {
                    if(orbCount[i][j]!=0&&playerState[i][j]==k)
                        playerCount[k-1]=playerCount[k-1]+orbCount[i][j];
                }
            }
        }
        if(count<=4)
        {
            if(player==1)
                player=2;
            else if(player==2)
                player=3;
            else if(player==3)
                player=4;
            else if(player==4)
                player=1;
        }
        else if(count>4)
        {
            if(player==1&&playerCount[1]!=0)
                player=2;
            else if(player==1&&playerCount[1]==0&&playerCount[2]!=0)
                player=3;
            else if(player==1&&playerCount[1]==0&&playerCount[2]==0&&playerCount[3]!=0)
                player=4;
            else if(player==1&&playerCount[1]==0&&playerCount[2]==0&&playerCount[3]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==2&&playerCount[2]!=0)
                player=3;
            else if(player==2&&playerCount[2]==0&&playerCount[3]!=0)
                player=4;
            else if(player==2&&playerCount[2]==0&&playerCount[3]==0&&playerCount[0]!=0)
                player=1;
            else if(player==2&&playerCount[2]==0&&playerCount[3]==0&&playerCount[0]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==3&&playerCount[3]!=0)
                player=4;
            else if(player==3&&playerCount[3]==0&&playerCount[0]!=0)
                player=1;
            else if(player==3&&playerCount[3]==0&&playerCount[0]==0&&playerCount[1]!=0)
                player=2;
            else if(player==3&&playerCount[3]==0&&playerCount[0]==0&&playerCount[1]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<endl<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
            else if(player==4&&playerCount[0]!=0)
                player=1;
            else if(player==4&&playerCount[0]==0&&playerCount[1]!=0)
                player=2;
            else if(player==4&&playerCount[0]==0&&playerCount[1]==0&&playerCount[2]!=0)
                player=3;
            else if(player==4&&playerCount[0]==0&&playerCount[1]==0&&playerCount[2]==0)
            {
                wait(0.5);
                Rectangle r1(300,400,600,800); r1.setFill(1); r1.setColor(COLOR("white")); r1.imprint();
                Text t1(350,50,"WINS"); t1.imprint();
                Text t2(250,50,"PLAYER"); t2.imprint();
                Text t3(300,50,player); t3.imprint();
                cout<<"PLAYER "<<player<<" WINS"<<endl;
                cout<<"GAME OVER"<<endl;
                break;
            }
        }
    }

    }
}




main_program{
initCanvas("Chain Reaction",600,800);
Text welcome(300,50,"WELCOME TO CHAIN REACTION");
welcome.setColor(COLOR(126,126,126));
Text under_line(300,75,"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~");
under_line.setColor(COLOR(0,0,255));
Rectangle start(300,150,120,24);
Text start_game(300,150,"START GAME");
start_game.setColor(COLOR(0,255,0));
Rectangle instru(300,250,125,24);
Text instruction(300,250,"INSRUCTIONS");
instruction.setColor(COLOR(0,0,255));
Rectangle qui(300,350,125,24);
Text exit(300,350,"EXIT");
exit.setColor(COLOR(255,0,0));
do
{
    int m, mx, my;
    m=getClick();
    mx=m/65536;
    my=m%65536;
    if(mx>=237.5 && my<=362.5 && my>=338 && my<=362 )
    {
        wait(0);                            //Closing the game
        return -1;
    }

    if(mx>=237.5 && my<=362.5 && my>=238 && my<=262 )
    {
        under_line.hide();                  //Shows the instructions
        welcome.hide();
        start.hide();
        start_game.hide();
        instru.hide();
        instruction.hide();
        qui.hide();
        exit.hide();
        Text t1(300,97,"A 2 to 4 player game Player1 is red, Player2 is green, Player3 is yellow, Player4 is blue");
        Text t2(300,194,"Each player is allowed to place the orb in a empty cell or cell belonging to player");
        Text t3(300,291,"A cell explodes once the orbs have reached more than critical mass");
        Text t4(300,388,"As soon as a player loses all his orbs he will be out of the game");

        t1.setColor(CYAN);
        t2.setColor(CYAN);
        t3.setColor(CYAN);
        t4.setColor(CYAN);

        Rectangle bac(300,500,100,24);
        Text Back(300,500,"BACK");
        Back.setColor(COLOR(100,100,100));
        int m=getClick();
        int mx=m/65536;
        int my=m%65536;
        if(mx>=200&&mx<=400&&my>=488&&my<=512)
        {
            t1.hide();
            t2.hide();
            t3.hide();
            t4.hide();
            bac.hide();
            Back.hide();
            under_line.show();
            welcome.show();
            start.show();
            start_game.show();
            instru.show();
            instruction.show();
            qui.show();
            exit.show();

        }

    }

    if(mx>=237.5 && my<=362.5 && my>=138 && my<=162 )
    {
        welcome.hide();
        start.hide();           //Starts game
        start_game.hide();
        instru.hide();
        instruction.hide();
        qui.hide();
        exit.hide();
        under_line.hide();
        Rectangle r2(300,150,100,24);
        Text p_2(300,150,"2 PLAYER");
        p_2.setColor(COLOR(0,0,255));
        Rectangle r3(300,250,100,24);
        Text p_3(300,250,"3 PLAYER");
        p_3.setColor(COLOR(0,0,255));
        Rectangle r4(300,350,100,24);
        Text p_4(300,350,"4 PLAYER");
        p_4.setColor(COLOR(0,0,255));
        while (true)
        {
            int m=getClick();
            int mx=m/65536;
            int my=m%65536;

            if(mx>=250&&mx<=350&&my>=138&&my<=162)
            {
                r2.hide();p_2.hide();
                r3.hide();p_3.hide();
                r4.hide();p_4.hide();
                playgame(2);
                break;
            }

            else if(mx>=250&&mx<=350&&my>=238&&my<=262)
            {
                r2.hide();p_2.hide();
                r3.hide();p_3.hide();
                r4.hide();p_4.hide();
                playgame(3);
                break;
            }

            else if(mx>=250&&mx<=350&&my>=338&&my<=362)
            {
                r2.hide();p_2.hide();
                r3.hide();p_3.hide();
                r4.hide();p_4.hide();
                playgame(4);
                break;
            }
        }

        break;
    }

}
while(true);
wait(2);
return -1;
}
