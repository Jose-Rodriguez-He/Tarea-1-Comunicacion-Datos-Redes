#include <iostream>
#include <windows.h>
#include  <conio.h>

using namespace std;

//esta funcion permite seleccionar una posicion en un plano cartesiano
void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

char mapa[27][31] = {
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
};


class enemigo{
    private:

        public:
            void pintar(int, int);
            void mover(int &, int &);
            void borrar(int, int);
            void pintarmapa();
};

void enemigo::pintarmapa(){
    for(int i=0;i<27;i++){
        cout << endl;
        for(int j=0;j<31;j++){
            cout << mapa[i][j];
        }
    }
}



void enemigo::pintar(int x, int y){
    gotoxy(x,y); cout<<"O";
}

void enemigo::borrar(int x, int y){
    gotoxy(x,y); cout << " ";
}

void enemigo::mover(int &x, int &y){
    if(kbhit()){
        enemigo::borrar(x,y);
        char tecla = getch();
        if(tecla == 'w' && y>2) y=y-2;
        if(tecla == 'a' && x>2) x=x-2;
        if(tecla =='s' && y<26) y=y+2;
        if(tecla =='d' && x<29) x=x+2;
        enemigo::pintar(x,y);
    }
}

int main(){

    enemigo a;
    int q1=1;
    int w1=2;

    a.pintarmapa();

    while(true){
    a.mover(q1,w1);
    }
}
