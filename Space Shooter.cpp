//PF Project
//Abdul Moiz Sarwar			21L-5203
//Saim ur Rehman			21L-5242
//Muhammad Qasim Dogar		21L-5246
//Abdul Ahad				21L-5454

//Made in Dev C++
//Graphics Lib was used
//TDM-GCC 4.9.2 32-bit Release

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

int restart = 0; // restart flag

int main(){
	fstream file; // opening highscore file
	file.open("score.txt",ios::in);
	int highscore = 0; // highscore
	file >> highscore; // fetching highscore
	file.close(); // closing the file
	if(highscore > 1000 || highscore < 0){ // innitializing file value
		highscore = 0;
	}
	char tsc[4]; // totalscore printing string
	char hsc[4]; // highscore printing string
	int score = 0; // score counter
	int level = 1; // level counter
	int lost = 0; // lost flag
	int win = 0; // win flag
	int life = 3; // total lifes
	int totalscore = 0; // total score
	int x = 400; // spaceship x coordinate
	int bul = 0; // bullet flag
	int bulx; // bullet x coordinate
	int buly = 700; // bullet y coordinate
	int b = 0; // enemy bullet timer
	int bulen; // enemy bullet flag
	int ranx; // random x selector
	int bulenx; // enemy bullet x coordinate
	int buleny; // enemy bullet y coordinate
	int enex[10]; // enemy x coordinates
	int eney[5] = {50, 100, 150, 200, 250}; // enemy y coordinates
	int rad[10][5]; // enemy radius
	int gain = 0; // enemy down speed
	int n = 0; //enemy downing timer
	for (int a = 0; a < 10; a++){ // enemy x coordinates
		enex[a] = (a+1)*72;
	}	
	for (int a = 0; a < 10; a++){ // enemy y coordinates
		for (int b = 0; b < 5; b++){
			rad[a][b] = 20;
		}
	}
	if(restart == 0){
		initwindow(800,800); // starting window
	}
	delay(1000); // flushing keyboard
	settextstyle(6,0,2); // printing instructions
	outtextxy(200,50,"I  N  S  T  R  U  C  T  I  O  N  S");
	outtextxy(125,200,"Use A/D to move the spaceship left and right");
	outtextxy(120,250,"Use SPACE to fire bullet towards the enemies");
	outtextxy(117,300,"Dodge the enemy bullet by using the A/D keys");
	outtextxy(127,350,"Destroy all the enemies to complete the game");
	outtextxy(180,400,"Press the M key at any time to quit");
	outtextxy(235,450,"Press the W key to play");
	outtextxy(200,550,"All time best High Score: ");
	sprintf(hsc,"%d",highscore);
	outtextxy(520,550,hsc);
	outtextxy(200,700, "B  E  S  T     O  F     L  U  C  K");
	setcolor(0);
	setbkcolor(7);
	while(!GetAsyncKeyState('W')){ delay(100); } // waiting for W key to be pressed
	for(;;){ // Start
	n++; // down timer
	b++; // enemy bullet timer
	if (GetAsyncKeyState('M')){ // exit
		delay(500); // flushing keyboard
		break;
	}
	if (GetAsyncKeyState('A')){ // move left
		x -= 5;
	}
	if (GetAsyncKeyState('D')){ // move right
		x += 5;
	}
	if (GetAsyncKeyState(' ') && bul == 0){ // start bullet
		bul = 1;
		bulx = x;
		

	}
	cleardevice();
	outtextxy(670,750,"Level: "); // printing level counter
	if (level == 1){
		outtextxy(750,750,"1");
	}
	if (level == 2){
		outtextxy(750,750,"2");
	}
	if (level == 3){
		outtextxy(750,750,"3");
	}
	if (level == 4){
		outtextxy(750,750,"4");
	}
	if (level == 5){
		outtextxy(750,750,"5");
	}
	sprintf(tsc,"%d",totalscore); // printing total score counter
	outtextxy(20,750,"Score: ");
	outtextxy(100,750,tsc);
	if (bul == 1){ // spaceship bullet
		circle(bulx,buly,10);
		setfillstyle(SOLID_FILL,0);
		floodfill(bulx,buly,0);
		buly -= 10;
	}	
	if (buly <= 0){ // end spaceship bullet
		bul = 0;
		buly = 700;
	}
	for(int a = 0; a <10; a++){ // levels
		if ( level >= 1){
			if (eney[4] >= 660 && rad[a][4] == 20){
				lost = 1;
				break;
			}
			eney[4] = (50 * level) + gain;
			circle (enex[a],eney[4],rad[a][4]);
			if (rad[a][4] == 20 ){
				setfillstyle(SOLID_FILL,8);
				floodfill(enex[a],eney[4],0);
			}
			if (buly >= eney[4] - 5 && buly <= eney[4] + 5 && bulx > enex[a] - 25 && bulx < enex[a] + 25 && rad[a][4] == 20){
				rad[a][4] = 0;
				bul = 0;
				buly = 700;
				score = score + 20;
				totalscore = totalscore + 20;
			}
		}
		if ( level >= 2){
			if (eney[3] >= 660 && rad[a][3] == 20){
				lost = 1;
				break;
			}
			eney[3] = 50 * (level - 1) + gain;
			circle (enex[a],eney[3],rad[a][3]);
			if (rad[a][3] == 20 ){
				setfillstyle(SOLID_FILL,8);
				floodfill(enex[a],eney[3],0);
			}
			if (buly >= eney[3] - 5 && buly <= eney[3] + 5 && bulx > enex[a] - 25 && bulx < enex[a] + 25 && rad[a][3] == 20){
				rad[a][3] = 0;
				bul = 0;
				buly = 700;
				score = score + 20;
				totalscore = totalscore + 20;
			}
		}
		if ( level >= 3){
			if (eney[2] >= 660 && rad[a][2] == 20){
				lost = 1;
				break;
			}
			eney[2] = 50 * (level - 2) + gain;
			circle (enex[a],eney[2],rad[a][2]);
			if (rad[a][2] == 20 ){
				setfillstyle(SOLID_FILL,8);
				floodfill(enex[a],eney[2],0);
			}
			if (buly >= eney[2] - 5 && buly < eney[2] + 5 && bulx > enex[a] - 25 && bulx < enex[a] + 25 && rad[a][2] == 20){
				rad[a][2] = 0;
				bul = 0;
				buly = 700;
				score = score + 20;
				totalscore = totalscore + 20;
			}
		}
		if ( level >= 4){
			if (eney[1] >= 660 && rad[a][1] == 20){
				lost = 1;
				break;
			}
			eney[1] = 50 * (level - 3) + gain;
			circle (enex[a],eney[1],rad[a][1]);
			if (rad[a][1] == 20 ){
				setfillstyle(SOLID_FILL,8);
				floodfill(enex[a],eney[1],0);
			}
			if (buly >= eney[1] - 5 && buly <= eney[1] + 5 && bulx > enex[a] - 25 && bulx < enex[a] + 25 && rad[a][1] == 20){
				rad[a][1] = 0;
				bul = 0;
				buly = 700;
				score = score + 20;
				totalscore = totalscore + 20;
			}
		}
		if ( level >= 5){
			if (eney[0] >= 660 && rad[a][0] == 20){
				lost = 1;
				break;
			}
			eney[0] = 50 * (level - 4) + gain;
			circle (enex[a],eney[0],rad[a][0]);
			if (rad[a][0] == 20 ){
				setfillstyle(SOLID_FILL,8);
				floodfill(enex[a],eney[0],0);
			}
			if (buly >= eney[0] - 5 && buly <= eney[0] + 5 && bulx > enex[a] - 25 && bulx < enex[a] + 25 && rad[a][0] == 20){
				rad[a][0] = 0;
				bul = 0;
				buly = 700;
				score = score + 20;
				totalscore = totalscore + 20;
			}
		}
	}
	circle (x,700,20); // spaceship
	setfillstyle(SOLID_FILL,2);
	floodfill(x,700,0);
	if (bulen == 1){ // enemy bullet
		circle(bulenx,buleny,5);
		setfillstyle(SOLID_FILL,4);
		floodfill(bulenx,buleny,0);
		buleny += 10;
		if (bulenx >= x - 15 && bulenx <= x + 15 && buleny >= 680){ // enemy bullet hit
			life--;
			bulen = 0;
	}
	}
	for(int a = 0; a < life; a++){ // lifes
		circle((a+7)*50,750,10);
		setfillstyle(SOLID_FILL,5);
		floodfill((a+7)*50,750,0);
	}
	if (score == 120){ // level gainer
		level++;
		score = 0;
	}
	if (level == 5){ // level cap
		score = 0;
	}
	if (n >= (200/level)){ // downing counter
		gain += level;
		n = 0;
	}
	if (b >= (200/level) && bulen == 0){ // enemy bullet start
		b = 0;
		bulen = 1;
		ranx = rand() % 10;
		bulenx = enex[ranx];
		for ( int b = 4; b > 0; b--){
			if (rad[ranx][b] == 20){
				buleny = eney[b];
				break;
			}
		}
	}	
	if (buleny >= 795){ // enemy bullet end
		bulen = 0;
	}
	if (life == 0){ // life end check
		lost = 1;
	}
	if (lost == 1){ // lose flag
		delay(500);
		break; // breaking infinite loop
	}
	if (totalscore == 1000){ // win check
		win = 1;
		delay(500);
		break;
	}
	delay(10); // framerate time
}
	cleardevice();
	if (totalscore > int(highscore)){ // saving highscore
		file.open("score.txt",ios::out); // opening highscore file
		file << totalscore; // saving highscore to file
		file.close(); // closing file
	}
	if (win == 1){ // winning output
		outtextxy(300,300,"Y O U   W O N");
	}
	if (lost == 1){ // losing output
		outtextxy(295,300,"Y O U   L O S T");
	}
	outtextxy(210,400,"Press R to restart or E to exit");
	for(;;){ // ending and restart
		if (GetAsyncKeyState('R')){
			restart = 1;
			main();
		}
		if (GetAsyncKeyState('E')){
			break;
		}
	}
	return 0; // end	
}
