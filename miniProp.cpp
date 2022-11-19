#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;


int trapX, trapY;

string board[3][4];

bool moveRight(){
    int a,b;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (board[i][j]== "|*|" or board[i][j] == "*|"){
                a = i;
                b= j;
            }
        }
    }
    int i = a;
    int j = b;
    if (b ==3){
        return false;
    }
    if (b == 0){
        board[a][b] = "|_|";
        board[a][b+1] = "*|";
        return true;
    }
    board[a][b] = "_|";
    board[a][b+1] = "*|";
    return true;
}

bool moveLeft(){
    int a,b;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (board[i][j]== "|*|" or board[i][j] == "*|"){
                a = i;
                b= j;
            }
        }
    }
    int i = a;
    int j = b;
    
    if (b ==0){
        return false;
    }
    if (b == 3){
        board[a][b] = "|_|";
        board[a][b-1] = "*|";
        return true;
    }
    board[a][b] = "_|";
    board[a][b-1] = "*|";
    return true;
}


bool moveDown(){
    int a,b;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (board[i][j]== "|*|" or board[i][j] == "*|"){
                a = i;
                b= j;
            }
        }
    }
    int i = a;
    int j = b;
    
    if (a ==2){
        return false;
    }
    if (a == 0){
        board[a][b] = "|_|";
        board[a+1][b] = "*|";
        return true;
    }
    board[a][b] = "_|";
    board[a+1][b] = "*|";
    return true;
}


bool moveUp(){
    int a,b;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (board[i][j]== "|*|" or board[i][j] == "*|"){
                a = i;
                b= j;
            }
        }
    }
    int i = a;
    int j = b;
    
    if (a ==0){
        return false;
    }
    if (a == 2){
        board[a][b] = "|_|";
        board[a-1][b] = "*|";
        return true;
    }
    board[a][b] = "_|";
    board[a-1][b] = "*|";
    return true;
}





void render(){
    for (int i=0; i<3;i++){
        for(int j=0; j<4; j++){
            cout<< board[i][j];
        }
        cout<<"\n";
    }
    
    int operation ;
    cin >> operation;
    if (operation == 1){
       
        if(moveRight()==false){
            cout<<"invalid move"<<endl;
        }
        
       
    }
    if(operation == 2){
        
        if(moveLeft()==false){
            cout<<"invalid move"<<endl;
        }
    }
    
    if(operation == 3){
        
        if(moveDown()==false){
            cout<<"invalid move"<<endl;
        }
    }
    
    if(operation == 4){
        
        if(moveUp()==false){
            cout<<"invalid move"<<endl;
        }
    }
    
    //finding coordinates of *
    
     int a,b;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (board[i][j]== "|*|" or board[i][j] == "*|"){
                a = i;
                b= j;
            }
        }    
    }
    if(trapX==a && trapY==b){
        cout<<"game over"<<endl;
        return;
    }
    
    
    if(a==2 && b==3){
        cout<<"game finish"<<endl;
        return;
    }
    
    render();
}


int main()
{
    
    srand((unsigned) time(NULL));
    int random1 = rand() % 4;
    
    cout<<random1<<endl;
    
    
    for (int i=0; i<3;i++){
       
        for(int j=0; j<4; j++){
        
            if((i==0)&&(j==0)){
               board[i][j]="|*|";
               continue;
            }
            if((i==2)&&(j==3)){
               board[i][j]="G|";
               continue;
            }
            if ((i==1)&&(j==random1)){
            board[i][j]=" T";
            continue;
            }
            
            if(j ==0){
              board[i][j]="|_|";
            }
            else{
              board[i][j]= "_|";
            }
            
            trapX=1;
            trapY=random1;
        }
    }
    
    
    render();
    return 0;
}


