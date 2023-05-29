#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

//controles/teclas
// z= disparar
// x= colocar barcos
// c= rotar barcos

using namespace std;

//esta funcion permite seleccionar una posicion en un plano cartesiano
void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

//matriz que permitirá la creacion de casillas y el mapeado grafico del mapa
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

//Estructura de datos con cordenadas en el eje y,x
struct coordenadas{
    int x, y;
};


//Estructura encargada de dar forma a los barcos, con posicicones originales y las extensiones
struct pieza{

    coordenadas ori;
    coordenadas peri[4];

    char D;
    char d = '*';

    coordenadas posicion(int n);
};

//Permite calcular las posiciones y extensiones
coordenadas pieza::posicion(int n){
    coordenadas ret = {ori.x, ori.y};
    if(n != 0){
        ret.x += peri[n-1].x;
        ret.y += peri[n-1].y;
    }
    return ret;
}
/*
Portaaviones 5 casillas
buque 4 casillas
submarino 3 casillas
lancha 1 casilla
*/

//creacion de los barcos y sus dimensiones
coordenadas peris[5][4] =
{{{2,0},{4,0},{6,0},{8,0 } },
{{2,0},{4,0},{6,0},{ } },
{{2,0},{4,0},{ },{ } },
{{ },{ },{ },{ } },
{{ },{ },{ },{ } }};

//caracteres que usarán los barcos
char barcos[4] = {'P','B','S','L'};

//una matriz espejo del mapa
char ju [27][31];

//char para disparar
char en[27][31];

char en2[27][31];

//creacion de una clase con las funciones necesarias
class player{
    private:
        int turno = 0;
        int turno1;
        int ganaplayer = 0;
        int ganaenemy = 0;

    public:


        void pasarmapa();
        void dibujarmapaju();
        void pintar(pieza &, int);
        void borrar(pieza &);
        void rotar(pieza &);
        coordenadas rotar(coordenadas &);
        void seleccionar(pieza &, int);
        void mover(pieza &, int &);
        bool colision(pieza &, int);
        int obtenerxy();
        void selecionamapa(pieza &, int, int);
        void disparo(pieza &, int);
        int verificar(pieza &);
        void cambioturno(pieza &, int &, int);
        void general(pieza &, int &, int);
};

void player::pasarmapa(){
    for(int i=0;i<27;i++){
        cout << endl;
        for(int j=0;j<31;j++){
            ju[i][j] = mapa[i][j];
            en[i][j] = mapa[i][j];
            en2[i][j] = mapa[i][j];
        }
    }
}

void player::dibujarmapaju(){
    for(int i=0;i<27;i++){
        cout << endl;
        for(int j=0;j<31;j++){
            cout << ju[i][j];
        }
    }
}

//funcion encargada de dibujar y crear los barcos en la posicion seleccionada
void player::pintar (pieza &P, int r){
        for(int i=0; i<5; i++){
            coordenadas c = P.posicion(i);
            if(r == 1)ju[c.y-1] [c.x-1] = P.d;
            else ju[c.y-1] [c.x-1] = P.D;
            }
    }           

//funcion encargada de borrar los barcos y limpiar la casilla una vez se mueven
void player::borrar (pieza &P){
    for(int i=0; i<5; i++){
        coordenadas c = P.posicion(i);
        ju[c.y-1] [c.x-1] = ' ';
    }
}

coordenadas player::rotar(coordenadas &c){
    coordenadas ret = {c.y, c.x};
    return ret;
}

//funcion encargada de la rotacion de los barcos
void player::rotar(pieza &P){
    for(int i=0;i<4;i++){
        P.peri[i] = player::rotar(P.peri[i]);
    }
}

//funcion que permite la seleccion de una casilla de la matriz en el mapa
void player::seleccionar(pieza &P, int r){
    P.ori.x = player::obtenerxy();
    P.ori.y = player::obtenerxy();
    P.D = barcos[r];
    for(int i=0 ; i<4;i++){
        P.peri[i] = peris[r][i];
    }
}
//funcion que detecta el tecleo y permite colocar, mover y rotar los barcos
void player::mover(pieza &P, int &r){
    if(kbhit()){
        pieza copia = P;
        char tecla = getch();
        if(tecla == 'w') P.ori.y -=2;
        if(tecla == 'a') P.ori.x -=2;
        if(tecla == 's') P.ori.y +=2;
        if(tecla == 'd') P.ori.x +=2;

        if(tecla == 'c'){
            player::rotar(P);
        }

        if(player::colision(P,1)){
            P = copia;
        }
        player::borrar(copia);
        player::pintar(P,1);

        if(tecla == 'x'){
            player::pintar(P,2);
            r++;
            player::selecionamapa(P,r,1);
        }
    }   
}

//funcion encargada de detectar las colisiones para que no borre barcos ni se salga del mapeado
bool player::colision(pieza &P, int q){
    for(int i=0; i<5; i++){
        coordenadas c = P.posicion(i);
        if(c.x < 2 || c.x > 30) return true;

        if(c.y < 2 || c.y >26) return true;

        if(q == 1){
            if(ju[c.y-1][c.x-1] == 'P' || ju[c.y-1][c.x-1] == 'B' || ju[c.y-1][c.x-1] == 'S' || ju[c.y-1][c.x-1] == 'L') return true;
        }
        if(q == 2){
            if(ju[c.y-1][c.x-1] == 'X' || ju[c.y-1][c.x-1] == 'O') return true;
        }

        
    }
    return false;
}

int player::obtenerxy(){
    while(true){
    int x = rand()%19+2;
    if(x%2 == 0) return x;
    }
}


void player::selecionamapa(pieza &P, int r, int q){
    while(true){
        player::seleccionar(P,r);
        if(!player::colision(P,q)) break;
    }
}

void player::disparo(pieza &P, int q){
    for(int i= 0; i<4; i++){
        coordenadas c = P.posicion(i);
        if(q == 1){
            if(en2[c.y-1][c.x-1] == 'P' || en2[c.y-1][c.x-1] == 'B' || en2[c.y-1][c.x-1] == 'S' || en2[c.y-1][c.x-1] == 'L'){
                en[c.y-1][c.x-1] = 'O';
                
            } 
            if(en2[c.y-1][c.x-1] == ' ') en[c.y-1][c.x-1] = 'X' ;
        }
        if(q == 2){
            if(ju[c.y-1][c.x-1] == 'P' || ju[c.y-1][c.x-1] == 'B' || ju[c.y-1][c.x-1] == 'S' || ju[c.y-1][c.x-1] == 'L') ju[c.y-1][c.x-1] = 'O';{
                if(ju[c.y-1][c.x-1] == 'P') P.D = 'P';
                if(ju[c.y-1][c.x-1] == 'B') P.D = 'B';
                if(ju[c.y-1][c.x-1] == 'S') P.D = 'S';
                ju[c.y-1][c.x-1] = 'O';
                turno1 = 1;
            }
            if(ju[c.y-1][c.x-1] == ' ') ju[c.y-1][c.x-1] = 'X' ;            
        }
    }
}

int player::verificar(pieza &P){
    for(int i=2;i<27;i++){
        for(int j=0;j<31;j++){
            if(ju[i][j] == P.D){
                P.ori.x = j;
                P.ori.y = i;
                return 1;
            }
        }
    }
    return 2;
}

void player::cambioturno(pieza &P, int &t, int r){
    player:: selecionamapa(P,r,2);
    //player::disparo(P,2);
    t = 1;
}

class enemy : public player{
    public:
        void dibujarmapaen();
        void pintar(pieza &, int);
        void borrar(pieza &);
        void mover(pieza &, int &, int &);
        bool colision(pieza &, int);
        void selecionamapa(pieza &, int);
        void iniciarbarcos(pieza &, int);
        int obtener();
};

void enemy::pintar(pieza &P,int r){
        for(int i=0; i<5; i++){
            coordenadas c = P.posicion(i);
            if(r == 1)en[c.y-1] [c.x-1] = P.d;
            else en2[c.y-1] [c.x-1] = P.D;
        }
}


void enemy::borrar(pieza &P){
    for(int i=0; i<5; i++){
        coordenadas c = P.posicion(i);
        en[c.y-1] [c.x-1] = ' ';
    }
}

void enemy::dibujarmapaen(){
    for(int i=0;i<27;i++){
        cout << endl;
        for(int j=0;j<31;j++){
            cout << en[i][j];
        }
    }
}

void enemy::mover(pieza &P, int &r, int &t){
    if(kbhit()){
        pieza copia = P;
        char tecla = getch();
        if(tecla == 'w') P.ori.y -=2;
        if(tecla == 'a') P.ori.x -=2;
        if(tecla == 's') P.ori.y +=2;
        if(tecla == 'd') P.ori.x +=2;

        if(enemy::colision(P,2)){
            P=copia;
        }

        enemy::borrar(copia);
        enemy::pintar(P,1);

        if(tecla == 'z'){
            enemy::disparo(P,1);
            enemy::selecionamapa(P,r);
            t = 2;
            copia = P;
        }

    }       
}

bool enemy::colision(pieza &P, int q){
    for(int i=0; i<4; i++){
        coordenadas c = P.posicion(i);
        if(c.x < 2 || c.x > 30) return true;

        if(c.y < 2 || c.y >26) return true;

        if(q == 1){
            if(en2[c.y-1][c.x-1] == 'P' || en2[c.y-1][c.x-1] == 'B' || en2[c.y-1][c.x-1] == 'S' || en2[c.y-1][c.x-1] == 'L') return true;
        }
        if(q == 2){
            if(en[c.y-1][c.x-1] == 'X' || en[c.y-1][c.x-1] == 'O' ) return true;
        }
        
    }
    return false;
}

void enemy::selecionamapa(pieza &P, int r){
    while(true){
        enemy::seleccionar(P,r);
        if(!enemy::colision(P,2)) break;
    }
}

int enemy::obtener(){
    int x = rand()%2;
    return x;
}

//
void enemy::iniciarbarcos(pieza &P, int q){
    for(int i = 0; i<5; i++){
        while(true){
            enemy::seleccionar(P,i);
            if(enemy::obtener()==0)enemy::rotar(P);
            if(!enemy::colision(P,1)){
                enemy::pintar(P,2);
                break;
            } 
        }
    }
}

void player::general(pieza &P, int &t, int r){
    if(turno1 == 0) turno = 0;
    if(turno1 == 1) turno = 1;

    if(turno = 0){
        player::cambioturno(P,t,r);
    }

    if(turno = 1){
        if(player::verificar(P) == 1){
            player::disparo(P,2);
            t = 1;
        }
        if(player::verificar(P) == 2){
            player::cambioturno(P,t,r);
            turno1 = 0;
        }
    }
}

int main(){

    /*HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 800, 600, TRUE);
    */

    //rand()
    srand(time(NULL)); //
    player a;  
    enemy b;              
    pieza S, S1;
    int r=0;

    a.pasarmapa();
    a.seleccionar(S,r);
    int t = 0;
    
    b.iniciarbarcos(S1,r);

    while(true){
        gotoxy(0,30); a.dibujarmapaju();
        gotoxy(0,0); b.dibujarmapaen();

        if(t==0){
            a.mover(S,r);
            if(r == 4) t=1;
        }
        if(t == 1){
            b.mover(S1,r,t);
        }
        if(t == 2){
            b.general(S,t,r);
        }

    }

    return 0;
}
