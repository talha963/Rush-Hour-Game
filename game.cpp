//============================================================================
// Name        : .cpp
// Author      : Dr. Sibt Ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
class vehicle
{
  protected:
  int height,width;
  public:
  vehicle(int x=50,int y=700):height(x),width(y){}
};
class Board;
class Car:public vehicle
{
  private:
  int X,Y;        
  const int size=28;   //Size of Car
  bool flag=0;
  bool fuel=0;
  public:
  Car():X(height),Y(width){}
  void drawcar()
  {
    DrawSquare(X,Y,28,colors[YELLOW]);
    DrawCircle(X-4,Y,10,colors[RED]);
    DrawCircle(X-4,Y+25,10,colors[RED]);
    DrawCircle(X+29,Y+29,10,colors[RED]);
    DrawCircle(X+29,Y,10,colors[RED]);
  }
  
  void moveup(Board &b);
  void movedown(Board &b);
  void moveleft(Board &b);
  void moveright(Board &b);
    bool getFlag()
    {
      return flag;
    }
    int getX()
    {
      return X;
    }
    int getY()
    {
      return Y;
    }
    int getSize()
    {
      return size;
    }
    bool getFuel()
    {
      return fuel;
    }
    void setPosition(int a,int b)
    {
      X=a;
      Y=b;
    }
};
class tempo:public vehicle
{
  private:
  int h,w;        
  const int size=40;   //Size of tempo
  bool flag=0;
  bool fuel=0;
  public:
  tempo():h(height),w(width){}
  void drawtempo()
  {
    DrawSquare(h,w,40,colors[YELLOW]);
    DrawCircle(h+5,w-5,7,colors[RED]);
    DrawCircle(h+28,w-5,7,colors[RED]);
  }
  
  void Moveup(Board &b);
  void Movedown(Board &b);
  void Moveleft(Board &b);
  void Moveright(Board &b);
    bool getFlag()
    {
      return flag;
    }
    int getX()
    {
      return h;
    }
    int getY()
    {
      return w;
    }
    int getSize()
    {
      return size;
    }
    bool getFuel()
    {
      return fuel;
    }
    void setPosition(int a,int b)
    {
      h=a;
      w=b;
    }
};
class Board
{
  public:
  int tree_x[4];
  int tree_y[4];
  int fuel_x[4];
  int fuel_y[4];
  bool fuelInitializer=false;
  bool treeIntializer=false;
  bool Overlap=true;
  bool FuelStation=true;
  int score=0;
  void DisplayBoard(Car& c)
  {
    DrawLine(30,20,30,750,5,colors[WHITE]);
    DrawLine(28,750,980,750,5,colors[WHITE]);
    DrawLine(980,750,980,20,5,colors[WHITE]);
    DrawLine(980,20,28,20,5,colors[WHITE]);
    
    DrawLine(150,100,300,100,5,colors[WHITE]);
    DrawLine(150,100,150,280,5,colors[WHITE]);
    DrawLine(150,280,300,280,5,colors[WHITE]);
    DrawLine(300,280,300,100,5,colors[WHITE]);
    
    DrawLine(150,650,300,650,5,colors[WHITE]);
    DrawLine(150,650,150,470,5,colors[WHITE]);
    DrawLine(150,470,300,470,5,colors[WHITE]);
    DrawLine(300,470,300,650,5,colors[WHITE]);
    
    DrawLine(650,650,800,650,5,colors[WHITE]);
    DrawLine(650,650,650,470,5,colors[WHITE]);
    DrawLine(650,470,800,470,5,colors[WHITE]);
    DrawLine(800,470,800,650,5,colors[WHITE]);
    
    DrawLine(650,100,800,100,5,colors[WHITE]);
    DrawLine(650,100,650,280,5,colors[WHITE]);
    DrawLine(650,280,800,280,5,colors[WHITE]); 
    DrawLine(800,280,800,100,5,colors[WHITE]); 
    
    DrawSquare(40,40,60,colors[GREEN]);
    DrawTriangle(40,100,70,130,100,100,colors[RED]);
    if(!treeIntializer)
    {
          generateTree();
          treeIntializer=true;
     }
  if(!fuelInitializer)
  {
    generateFuel();
    fuelInitializer=true;
    
  }
    drawTree();
    drawStation();
  }
  void generateTree()
  {
    for(int i=0;i<4;i++)
    {
      while(Overlap)
      Overlap=false;
      
      tree_x[i]=500+rand()%250;
      tree_y[i]=150+rand()%350;
      
      if((tree_x[i]>=150 && tree_x[i]<=300 && tree_y[i]>=100 && tree_y[i]<=280)||
          (tree_x[i]>=150 && tree_x[i]<=300 && tree_y[i]>=470 && tree_y[i]<=650)||
          (tree_x[i]>=650 && tree_x[i]<=800 && tree_y[i]>=470 && tree_y[i]<=650)||
          (tree_x[i]>=650 && tree_x[i]<=800 && tree_y[i]>=100 && tree_y[i]<=280))
              Overlap=true;
        for(int j=0;j<i;j++)
        {
          if(abs(tree_x[i]-tree_x[j]<60) && abs(tree_y[i]-tree_y[j]<60))
            Overlap=true;
        }
    }
  }
  void drawTree()
  {
  for(int i=0;i<4;i++)
  {
    DrawCircle(tree_x[i],tree_y[i],20,colors[GREEN]);
    DrawLine(tree_x[i],tree_y[i]-20,tree_x[i],tree_y[i]-40,5,colors[BROWN]);
  }
  }
  void generateFuel()
  {
    for(int i=0;i<4;i++)
    {
      while(FuelStation)
      FuelStation=false;
      do
      {
        fuel_x[i]=200+rand()%350;
        fuel_y[i]=200+rand()%350;
      }
      while((fuel_x[i]>=150 && fuel_x[i]<=300 && fuel_y[i]>=100 && fuel_y[i]<=280)||
      (fuel_x[i]>=150 && fuel_x[i]<=300 && fuel_y[i]>=470 && fuel_y[i]<=650)||
      (fuel_x[i]>=650 && fuel_x[i]<=800 && fuel_y[i]>=470 && fuel_y[i]<=650)||
      (fuel_x[i]>=650 && fuel_x[i]<=800 && fuel_y[i]>=100 && fuel_y[i]<=280));
      
        for(int j=0;j<i;j++)
        {
          if(abs(fuel_x[i]-fuel_x[j]<50) && abs(fuel_y[i]-fuel_y[j]<50))
            FuelStation=true;
        }
    }
  }
  void drawStation()
  {
    for(int i=0;i<4;i++)
    {
      DrawRectangle(fuel_x[i],fuel_y[i],20,50,colors[BLUE]);
    }
  }
  bool isCollision(Car& c)          
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    if(x+s>=153 && x+s<=332 && y+s>=100 && y+s<=323)     //Building 1
      return true; 
    if(x+s>=153 && x+s<=332 && y+s>=465 && y+s<=693)  //Building 2
      return true;
    if(x+s>=645 && x+s<=840 && y+s>=465 && y+s<=693)   //Building 3
      return true;
    if(x+s>=645 && x+s<=840 && y+s>=100 && y+s<=323)    //Building  4
      return true;
    for(int i=0;i<4;i++)       //For Tree Circle
    {
      int left=tree_x[i]-18;
      int right=tree_x[i]+22;
      int bottom=tree_y[i]-18;
      int top=tree_y[i]+22;
      if(x+s>=left && x+s<=right && y+s>=bottom && y+s<=top)
        return true;
    }
    for(int i=0;i<4;i++)       //For tree Line
    {
      int trunkleft=tree_x[i]-5;
      int trunkright=tree_x[i]+5;
      int trunkbottom=tree_y[i]-40;
      int trunktop=tree_y[i]-20;
      if(x+s>=trunkleft && x+s<=trunkright && y+s>=trunkbottom && y+s<=trunktop)
        return true;
    }
     return false;  
  }
    bool isCollision_tempo(tempo& temp)          
  {
    int x=temp.getX();
    int y=temp.getY();
    int s=temp.getSize();
    if(x+s>=153 && x+s<=332 && y+s>=100 && y+s<=323)     //Building 1
      return true;
    if(x+s>=153 && x+s<=332 && y+s>=465 && y+s<=693)  //Building 2
      return true;
    if(x+s>=645 && x+s<=840 && y+s>=465 && y+s<=693)   //Building 3
      return true;
    if(x+s>=645 && x+s<=840 && y+s>=100 && y+s<=323)    //Building  4
      return true;
    for(int i=0;i<4;i++)       //For Tree Circle
    {
      int left=tree_x[i]-18;
      int right=tree_x[i]+22;
      int bottom=tree_y[i]-18;
      int top=tree_y[i]+22;
      if(x+s>=left && x+s<=right && y+s>=bottom && y+s<=top)
        return true;
    }
    for(int i=0;i<4;i++)       //For tree Line
    {
      int trunkleft=tree_x[i]-5;
      int trunkright=tree_x[i]+5;
      int trunkbottom=tree_y[i]-40;
      int trunktop=tree_y[i]-20;
      if(x+s>=trunkleft && x+s<=trunkright && y+s>=trunkbottom && y+s<=trunktop)
        return true;
    }
     return false;  
  }
  bool IsOnStation(Car& c)
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    for(int i=0;i<4;i++)
    {
      if(x+s>=fuel_x[i] && x+s<=fuel_x[i]+20 && y+s>=fuel_y[i] && y+s<=fuel_y[i]+50)
        return true;
    }
    return false;
  }
  bool IsOnStation_tempo(tempo& c)
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    for(int i=0;i<4;i++)
    {
      if(x+s>=fuel_x[i]-10 && x+s<=fuel_x[i]+30 && y+s>=fuel_y[i]-10 && y+s<=fuel_y[i]+60)
        return true;
    }
    return false;
  }
  bool isOnGarage(Car& c)
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    if(x>=40 && x+s<=100 && y>=40 && y+s<=130)
      return true;
    return false;  
  
  }
  bool isOnGarage_tempo(tempo& c)
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    if(x>=40 && x+s<=100 && y>=40 && y+s<=130)
      return true;
    return false;  
  
  }
  
  };
class RandomCar
{
  int x;
  int y;
  const int size=28;
  int direction;
  Board board;
  Car c;
  public:
  RandomCar(){
    x=100+rand()%500;
    y=100+rand()%600;
    direction=rand()%4;
    c.setPosition(x,y);
  }
  void draw()
  {
        DrawSquare(x,y,28,colors[YELLOW]);
        DrawCircle(x-4,y,10,colors[RED]);
        DrawCircle(x-4,y+25,10,colors[RED]);
        DrawCircle(x+29,y+29,10,colors[RED]);
        DrawCircle(x+29,y,10,colors[RED]);
  }
  void moveCar(){
  switch(direction)
  {
    case 0:
    {
      if(y+10+size<=750)    
        y+=10;
      break;
    }
    case 1:
    {
      if(y-10>=20)
        y-=10;
      break;  
    }
    case 2:
    {
      if(x-10>=30)
        x-=10;
      break;  
    }
    case 3:
    {
      if(x+10+size<=980)  
        x+=10;
      break;
    }
  }
  switch(direction)
  {
    case 0:
    {
      if(board.isCollision(c))
        y-=10;
       break; 
    }
    case 1:
    {
      if(board.isCollision(c))
        y+=10;
       break; 
    }
    case 2:
    {
      if(board.isCollision(c))
        x+=10;
       break; 
    }
    case 3:
    {
      if(board.isCollision(c))
        x-=10;
       break; 
    }
  }
  direction=rand()%4;
  glutPostRedisplay();
  }
};
class Destination
{
 public:
  virtual void generate(){};
  virtual void drawObject(){};
  virtual void DropObject(){};
  virtual void PickUp(Car& c){};
  virtual void dropPassenager(Car& c,int& score){};
  virtual void PickUp(tempo& p){};
  virtual void dropPassenager(tempo& p,int& score){};
  ~Destination(){}
};
class pessanger:public Destination
{
  int des_x[2];
  int des_y[2];
  int per1[2];
  int per2[2];
  bool pickup[2];
  bool drop[2];
  bool checker=false;
  bool overlap=true;
  public:
  pessanger()
  {
    if(!checker)
   {
      generate();
      for(int i=0;i<2;i++)
      {
        do
       { 
          des_x[i]=200+rand()%350;
          des_y[i]=200+rand()%350;
      }
      while((des_x[i]>=150 && des_x[i]<=300 && des_y[i]>=100 && des_y[i]<=280)||
      (des_x[i]>=150 && des_x[i]<=300 && des_y[i]>=470 && des_y[i]<=650)||
      (des_x[i]>=650 && des_x[i]<=800 && des_y[i]>=470 && des_y[i]<=650)||
      (des_x[i]>=650 && des_x[i]<=800 && des_y[i]>=100 && des_y[i]<=280));
      }
      checker=true;
      for(int i=0;i<2;i++)
      {
        pickup[i]=true;
        drop[i]=false;
      }
   }
  } 
  void generate () override
  {
    for(int i=0;i<2;i++)
    {
      while(overlap)
      overlap=false;
      
      per1[i]=350+rand()%250;
      per2[i]=350+rand()%250;
      
      if((per1[i]>=150 && per1[i]<=300 && per2[i]>=100 && per2[i]<=280)||
          (per1[i]>=150 && per1[i]<=300 && per2[i]>=470 && per2[i]<=650)||
          (per1[i]>=650 && per1[i]<=800 && per2[i]>=470 && per2[i]<=650)||
          (per1[i]>=650 && per1[i]<=800 && per2[i]>=100 && per2[i]<=280))
              overlap=true;
        for(int j=0;j<i;j++)
        {
          if(abs(per1[i]-per1[j]<60) && abs(per2[i]-per2[j]<60))
            overlap=true;
        }
  }
}
  void drawObject () override     //Draw Person
  {
    for(int i=0;i<2;i++)
    {
      if(pickup[i])
      {
        DrawCircle(per1[i],per2[i],10,colors[RED]);
        DrawLine(per1[i],per2[i]-10,per1[i],per2[i]-40,3,colors[WHITE]);
        DrawLine(per1[i],per2[i]-40,per1[i]-10,per2[i]-60,3,colors[WHITE]);
        DrawLine(per1[i],per2[i]-40,per1[i]+10,per2[i]-60,3,colors[WHITE]);
        DrawLine(per1[i], per2[i] - 25, per1[i] - 15, per2[i] - 35, 3, colors[WHITE]); 
        DrawLine(per1[i], per2[i] - 25, per1[i] + 15, per2[i] - 35, 3, colors[WHITE]);
      }
      
    }
      
  }
    
     
  void DropObject () override
  {
    for(int i=0;i<2;i++)
    {
      if(drop[i])
      {
        DrawSquare(des_x[i],des_y[i],30,colors[PURPLE]);
        
      }
    }
  
  
  
  }
  void PickUp (Car& c) override
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    for(int i=0;i<2;i++)
    {
      if(pickup[i])
    {
      int dx=per1[i];
      int dy=per2[i];
      if(x+s>=dx-10 && x+s<=dx+10 && y+s>=dy-60 && y+s<=dy)
      {
          pickup[i]=false;
          drop[i]=true;
      }
    }    
  }
  }
  void dropPassenager (Car& c,int& score) override
  {
    int x=c.getX();
    int y=c.getY();
    int s=c.getSize();
    for(int i=0;i<2;i++)
    {
      int dx=des_x[i];
      int dy=des_y[i];
      if(x+s>=dx && x+s<=dx+30 && y+s>=dy && y+s<=dy+30)
      {
        drop[i]=false;
        score+=20;
      }
    
    }
  
  }
};
class box:public Destination
{
  int dest_x[2];
  int dest_y[2];
  int box1[2];
  int box2[2];
  bool Pickup[2];
  bool Drop[2];
  bool Checker=false;
  bool over_lap=true;
  public:
  box()
  {
    if(!Checker)
   {
      generate();
      for(int i=0;i<2;i++)
      {
        do
       { 
          dest_x[i]=200+rand()%350;
          dest_y[i]=200+rand()%350;
      }
      while((dest_x[i]>=150 && dest_x[i]<=300 && dest_y[i]>=100 && dest_y[i]<=280)||
      (dest_x[i]>=150 && dest_x[i]<=300 && dest_y[i]>=470 && dest_y[i]<=650)||
      (dest_x[i]>=650 && dest_x[i]<=800 && dest_y[i]>=470 && dest_y[i]<=650)||
      (dest_x[i]>=650 && dest_x[i]<=800 && dest_y[i]>=100 && dest_y[i]<=280));
      }
      Checker=true;
      for(int i=0;i<2;i++)
      {
        Pickup[i]=true;
        Drop[i]=false;
      }
   }
  } 
  void generate () override
  {
    for(int i=0;i<2;i++)
    {
      while(over_lap)
      over_lap=false;
      
      box1[i]=350+rand()%250;
      box2[i]=350+rand()%250;
      
      if((box1[i]>=150 && box1[i]<=300 && box2[i]>=100 && box2[i]<=280)||
          (box1[i]>=150 && box1[i]<=300 && box2[i]>=470 && box2[i]<=650)||
          (box1[i]>=650 && box1[i]<=800 && box2[i]>=470 && box2[i]<=650)||
          (box1[i]>=650 && box1[i]<=800 && box2[i]>=100 && box2[i]<=280))
              over_lap=true;
        for(int j=0;j<i;j++)
        {
          if(abs(box1[i]-box1[j]<60) && abs(box2[i]-box2[j]<60))
            over_lap=true;
        }
  }
}
  void drawObject () override     //Draw boxes
  {
    for(int i=0;i<2;i++)
    {
      if(Pickup[i])
      {
        DrawSquare(box1[i],box2[i],35,colors[RED]);
      }
      
    }
      
  }
    
     
  void DropObject () override
  {
    for(int i=0;i<2;i++)
    {
      if(Drop[i])
      {
        DrawSquare(dest_x[i],dest_y[i],30,colors[PURPLE]);
        
      }
    }
  
  
  
  }
  void PickUp (tempo& p) override
  {
    int x=p.getX();
    int y=p.getY();
    int s=p.getSize();
    for(int i=0;i<2;i++)
    {
      if(Pickup[i])
    {
      int dx=box1[i];
      int dy=box2[i];
      if(x+s>=dx-10 && x+s<=dx+45 && y+s>=dy-10 && y+s<=dy+45)
      {
          Pickup[i]=false;
          Drop[i]=true;
      }
    }    
  }
  }
  void dropPassenager (tempo& p,int& score) override
  {
    int x=p.getX();
    int y=p.getY();
    int s=p.getSize();
    for(int i=0;i<2;i++)
    {
      int dx=dest_x[i];
      int dy=dest_y[i];
      if(x+s>=dx-10 && x+s<=dx+40 && y+s>=dy-10 && y+s<=dy+40)
      {
        Drop[i]=false;  
        score+=20;
      }
    
    }
  
  }
};
   //-------------------------------------------------- Movement of Car -------------------------------------------------------
    void Car::moveup(Board &b)
  {
    if(Y+10+size<=750)    
      Y+=10;
      if(b.isCollision(*this))
      {
        Y-=10;
      }
      flag=1;
      fuel=1;
  }
    void Car::movedown(Board &b){
  if(Y-10>=20)
    Y-=10;
    if(b.isCollision(*this))
      Y+=10;
    flag=1;
    fuel=1;
  }
  void Car::moveleft(Board &b){
    if(X-10>=30)
      X-=10;
      if(b.isCollision(*this))
        X+=10;
      flag=1;
      fuel=1;
    }
  void Car:: moveright(Board &b){
    if(X+10+size<=980)  
      X+=10;
      if(b.isCollision(*this))
        X-=10;
      flag=1;
      fuel=1;
    }
    //---------------------------------------------------Movement of Tempo---------------------------------------------------------
    void tempo::Moveup(Board &b)
  {
    if(w+10+size<=750)    
      w+=10;
      if(b.isCollision_tempo(*this))
      {
        w-=10;
      }
      flag=1;
      fuel=1;
  }
    void tempo::Movedown(Board &b){
  if(w-10>=20)
    w-=10;
    if(b.isCollision_tempo(*this))
      w+=10;
    flag=1;
    fuel=1;
  }
  void tempo::Moveleft(Board &b){
    if(h-10>=30)
      h-=10;
      if(b.isCollision_tempo(*this))
        h+=10;
      flag=1;
      fuel=1;
    }
  void tempo:: Moveright(Board &b){
    if(h+10+size<=980)  
      h+=10;
      if(b.isCollision_tempo(*this))
        h-=10;
      flag=1;
      fuel=1;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    class Game;
   class Menu
   { 
    bool isActive;
    string option[4]={"1:Taxi Mode","2:Delivery Mode","3:Instruction","4:Exit"};
    int option_num=4;
    public:
    Menu():isActive(true){}
    bool isMenuActive()
    {
      return isActive;
    }
    void activate()
    {
        isActive=true;
    }
    void deactivate()
    {
      isActive=false;
    }
    void draw()
    {
      DrawRectangle(350,250,300,300,colors[GRAY]);
      DrawString(400,450,"Rush Hour",colors[WHITE]);
      for(int i=0;i<option_num;i++)
      {
        DrawString(400,400-i*50,option[i],colors[WHITE]);
      }
    }
    int select(unsigned char key,Game& game);
   };
class Game:public Board
{
  private:
  Car car;
  Board board;
  pessanger p;
  tempo temp;
  Destination* current_destination;
  box b;
  Menu menu;
  RandomCar rc1;
  RandomCar rc2;
  int stopper=700;
  int fuel=100;
  int fuel_tempo=100;
  int fuel_counter=0;
  int fuel_counter1=0;
  int money=100;
  bool taxi=true;
  bool delivery=false;
  bool penelty=false;
  bool showInst=false;
  public:
  Game()
  {
  }  
  void setTaxi(bool val)
    {
      taxi=val;
    }
    void setDeli(bool val)
    {
      delivery=val;
    }   
  void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
        
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Display Score
	if(showInst)
	{
	    DrawString(50, 800, "Instructions", colors[WHITE]);
            DrawString(50, 750, "Arrow Keys: Move vehicle", colors[WHITE]);
            DrawString(50, 700, "P: Pick up passenger/box", colors[WHITE]);
            DrawString(50, 650, "D: Drop off passenger/box", colors[WHITE]);
            DrawString(50, 600, "M: Open menu", colors[WHITE]);
            DrawString(50, 550, "ESC: Exit", colors[WHITE]);
            DrawString(50, 500, "Press M to return to menu", colors[WHITE]);
	}
	else if(menu.isMenuActive())
	{
	  menu.draw();
	}
	else
	{
	  DrawString( 50, 800, "TALHA HABIB", colors[MISTY_ROSE]);
	  DrawString( 250, 800, "SCORE:"+to_string(score), colors[MISTY_ROSE]);
	  DrawString( 450, 800, "TIME:"+to_string(stopper), colors[MISTY_ROSE]);
	  DrawString( 750, 800, "FUEL:"+to_string((taxi)?fuel:fuel_tempo)+"%", colors[MISTY_ROSE]);
	  DrawString( 600, 800, "MONEY:"+to_string(money), colors[MISTY_ROSE]);
	
	board.DisplayBoard(car);
	rc1.draw();
	rc2.draw();
	
	if(taxi)
	{
	  car.drawcar();       //Draw Taxi
	  current_destination=&p;     
	}
	else if(delivery)
	{
	  temp.drawtempo();    //Draw Tempo
	  current_destination=&b;
	}
	if(current_destination)
	{
	  current_destination->drawObject();
	  current_destination->DropObject();
	}
	
	}

	glutSwapBuffers(); // do not modify this line..

}
void NonPrintableKeys(int key,int x,int y) {
        if(!menu.isMenuActive() && !showInst){
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if(taxi)
		  car.moveleft(board);
		else if(delivery)
		  temp.Moveleft(board);

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	        if(taxi)
		  car.moveright(board);
		else if(delivery)
		  temp.Moveright(board);
	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	        if(taxi)
		  car.moveup(board);
		else if(delivery)
		  temp.Moveup(board);
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(taxi)
		  car.movedown(board);
		else if(delivery)
		  temp.Movedown(board);
	}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}
void PrintableKeys(unsigned char key,int x,int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
        if(menu.isMenuActive())
        {
          int result=menu.select(key,*this);
          if(key=='3')showInst=true;
        }
        else if(showInst)
        {
          if(key=='m' || key=='M')
          {
            showInst=false;
            menu.activate();
          }
        }
        else
        {
        if (key == 'p' || key == 'P') //Key for pickup  the person
	{
	    if(taxi)
	      current_destination->PickUp(car);
	    else if(delivery)
	      current_destination->PickUp(temp);
            
	}
	if(key=='d' || key=='D')
	{
	  if(taxi)
	  {
	    current_destination->dropPassenager(car,score);
	    if(score==100)exit(1);
	  }
	  else if(delivery)
	  {
	    current_destination->dropPassenager(temp,score);
	    money+=10;
	    if(score==100)exit(1);
	  }
	  
	}
	if(board.isOnGarage(car))
	{
	  if(key=='b' || key=='B')
	  {
	    taxi=false;
	    delivery=true;
	  }  
	}
	if(board.isOnGarage_tempo(temp))
	{
	  if(key=='t' || key=='T')
	  {
	    taxi=true;
	    delivery=false;
	    current_destination=&p;
	  }
	
	}
      }	
	glutPostRedisplay();
}
void Timer(int m) {

	// implement your functionality here
	if(!menu.isMenuActive() && !showInst)
        {	
	rc1.moveCar();
	rc2.moveCar();
	
	                    //Timer Logic
	if(taxi){                    
	if(car.getFlag())
	{
	  stopper-=0.5;
	}
	if(stopper==0)
	{
	  exit(1);
	}
	}
	else if(delivery){
	if(temp.getFlag())
	{
	  stopper-=0.5;
	}
	if(stopper==0)
	{
	  exit(1);
	}
	}
	 
                     //Fuel Logic
    if(taxi)
    {
      if(car.getFuel())
      {
	fuel_counter+=1;                      
	if(fuel_counter>=10)
	{
	    fuel_counter=0;
            if(board.IsOnStation(car))
            {
              fuel+=5;
              if(fuel<100)
              {
              money-=5;
              }
              if(money==0)exit(1);
              if(fuel>=100)fuel=100;
            }
            else
            {
            if(car.getFuel())
            {
              fuel--;
            }
            if(fuel==0)
            {
              exit(1);
            }
            }
        }
       }
      }
      else if(delivery)
      { 
        if(temp.getFuel())
      {
	fuel_counter1+=1;                      
	if(fuel_counter1>=10)
	{
	    fuel_counter1=0;
            if(board.IsOnStation_tempo(temp))
            {
              fuel_tempo+=5;
              if(fuel_tempo<100)
              {
              money-=5;
              }
              if(money==0)exit(1);
              if(fuel_tempo>=100)fuel_tempo=100;
            }
            else
            {
            if(temp.getFuel())
            {
              fuel_tempo--;
            }
            if(fuel_tempo==0)
            {
              exit(1);
            }
            }
        }
       }
      
      }
     } 
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();
	glutTimerFunc(100, Timmer, 0);
}
static void DisplayToCall(){caller->GameDisplay();}
static void ArrowPresser(int key,int x,int y){caller-> NonPrintableKeys(key,x,y);}
static void MouseToCall(unsigned char key,int x,int y){caller->PrintableKeys(key,x,y);}
static void Timmer(int m){caller->Timer(m);}
static Game*caller;
};
int Menu::select(unsigned char key,Game& game)
    {
      switch(key)
      {
        case'1':
        {
          game.setTaxi(true);
          game.setDeli(false);
          isActive=false;
          return 1;
        }
        case '2':
        {
          game.setTaxi(false);
          game.setDeli(true);
          isActive=false;
          return 1;
        }
        case '3':
        {
          isActive=false;
          return 2;
        }
        case '4':
        {
          exit(0);
          return 0;
        }
        default:
        {
          return 0;
        }
      }
    }


Game*Game::caller=nullptr;

int main(int argc, char*argv[]) {
        
        srand(time(0));
	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	Game::caller=new Game();
	Game::caller->SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(Game::DisplayToCall); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(Game::ArrowPresser); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(Game::MouseToCall); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Game::Timmer, 0);

	//glutMouseFunc(MouseClicked);
	//glutPassiveMotionFunc(MouseMoved); // Mouse
	//glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
