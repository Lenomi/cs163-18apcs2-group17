#pragma once
#ifndef _UI_H_
#define _UI_H_

#include <chrono> 
using namespace std::chrono;
#include<iostream>
#include"graphics.h"
#include"winbgim.h"
#include"header.h"
#include<string.h>

using namespace std;

vector<string> fileNames;

File hi;
void searchScreen();
void drawBox(int pos)
{
	int min = 100;
	setcolor(COLOR(0,0,0));
	line(20,100+(pos-1)*min,660,100+(pos-1)*min);
	line(20, 130 + (pos - 1) * min, 660, 130 + (pos - 1) * min);	
	line(20, 100 + (pos - 1) * min, 20, 130 + (pos - 1) * min);
	line(660, 100 + (pos - 1) * min, 660, 130 + (pos - 1) * min);
}
void erasBox(int pos)
{
	if (pos > 0)
	{
		int min = 100;
		setcolor(COLOR(110, 223, 233));
		line(20, 100 + (pos - 1)*min, 660, 100 + (pos - 1)*min);
		line(20, 130 + (pos - 1) * min, 660, 130 + (pos - 1) * min);
		line(20, 100 + (pos - 1) * min, 20, 130 + (pos - 1) * min);
		line(660, 100 + (pos - 1) * min, 660, 130 + (pos - 1) * min);
	}
}
void initSetup(int clor)
{
	int gdriver = IBM8514, gmode = IBM8514HI, errorcode;

	/* initialize graphics and local variables */

	initgraph(&gdriver, &gmode, "");
	/* clear the screen */

	/* select a new background color */

//cleardevice();
	setfillstyle(LTBKSLASH_FILL, 3);
	setbkcolor(clor);

	cleardevice();
	setbkcolor(clor);

	//initgraph(&gdriver, &gmode, "");
	//setcolor(BLUE);
	//floodfill(1, 1, 0);
	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk) { /* an error occurred */printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1); /* terminate with an error code */
	}
}

vector<string> DivineToLine(std::string &text, int size) {
	vector<string> list;
	string s = text;
	int i = 0, pre = 0;
	while (i < s.length()) {
		if (i > size) {
			if (s[i] != ' ' && pre == 0) {
				pre = i;
			}
			string line = s.substr(0, pre);
			s.erase(0, pre);
			list.push_back(line);
			i = 0; pre = 0;
			continue;
		}
		else {
			if (s[i] == ' ') pre = i;
		}
		i++;
	}
	return list;
}

void Draw(vector<string> &text, int page, int total_page) {

	setviewport(700, 20, 1360, 720, 0);
	int start = (page - 1) * 27, stop = min(text.size(), start + 27);
	int offset = 1;
	for (int i = start; i < stop; ++i) {
		outtextxy(10, 25*offset++, text[i].c_str());
	}
}

void File::Highlight(string &inputbuf, vector<int>& ID)
{
	string l = inputbuf;
	string z;
	vector<string> query1;
	string word4 = "";
	for (auto x : l)
	{
		if (x == ' ')
		{
			query1.push_back(convert_word(word4));
			word4 = "";
		}
		else
		{
			word4 = word4 + x;
		}
	}
	query1.push_back(convert_word(word4));
	while (!query1.empty() && query1.back() == "") query1.pop_back();
	int query1_size = query1.size();
	for(int i=0 ; i<query1_size; i++)
	{
		if (query1[i][0] == '~')
		{
			int pos1 = l.find("~");
			l.erase(pos1, 1);
			query1[i].erase(0,1);
			search_synonyms(query1[i], z);
		}
	}
	for (int i = 0; i < query1_size; i++)
	{
		string Worderase;
		if (query1[i][0] == '-')
		{
			Worderase = query1[i].substr(1);
			while (l.find(Worderase) != string::npos)
			{
				int pos1 = l.find(Worderase);
				l.erase(pos1, Worderase.length());
			}
		}
	}
	l += " " + z;
	string y;
	for (int i=0; i < l.size(); i++)
	{
		if (l[i] >= 97 && l[i] <= 122 || l[i] >= 65 && l[i] <= 90 || l[i] <= 57 && l[i] >= 48 || l[i] == 35 || l[i] == 36 || l[i]==32)
		{
			y += l[i];
		}
	}
	l = y;
	while (l.find(" AND") != string::npos)
	{
		int pos1 = l.find(" AND");
		string Worderase = " AND";
		l.erase(pos1, Worderase.length());
	}
	while (l.find(" OR") != string::npos)
	{
		int pos1 = l.find(" OR");
		string Worderase = " OR";
		l.erase(pos1, Worderase.length());
	}
	vector<string> query;
	string word = "";
	for (auto x : l)
	{
		if (x == ' ')
		{
			query.push_back(convert_word(word));
			while (!query.empty() && query.back() == "") query.pop_back();
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	query.push_back(convert_word(word));
	while (!query.empty() && query.back() == "") query.pop_back();
	int query_size = query.size();
	vector <string> a;
	vector <string> b;
	for (int i = 0; i < 5 && i < ID.size(); i++)
	{
		a.push_back(search(root, ID[i])->data);
		b.push_back(convert_word(a.back()));
	}
	for (int i = 0; i < 5 && i < ID.size(); i++)
	{
		vector<int> pos;
		vector<int> name;
		for (int j = 0; j < query_size; j++)
		{
			if (b[i].find(query[j]) != string::npos)
			{
				pos.push_back(b[i].find(query[j]));
				name.push_back(query[j].size());
			}
		}
		string sub;
		string subline1;
		string subline2;
		string subline3;
		subline1 = "...";
		int k;
		if (inputbuf.find("intitle:") != string::npos || inputbuf.find("filetype:") != string::npos || inputbuf.find(".."))
		{
			pos.push_back(rand() % 90 + 1);
			name.push_back(0);
		}
		for (int c = 0; pos[0] + c < a[i].size() && c < 30; c++)
		{
			string sub2 = a[i].substr(pos[0] + c, 1);
			sub += sub2;
			k = c;
		}
		subline1 += sub;
		for (int c = k+1; pos[0] + c < a[i].size() && c < 60; c++)
		{
			string sub2 = a[i].substr(pos[0] + c, 1);
			subline2 += sub2;
			k = c;
		}
		for (int c = k + 1; pos[0] + c < a[i].size() && c < 90; c++)
		{
			string sub2 = a[i].substr(pos[0] + c, 1);
			subline3 += sub2;
		}
		subline3 += "...";
		string NAME = a[i].substr(pos[0], name[0]);
		
		setcolor(WHITE);
		outtextxy(30, 145 + i * 100, subline1.c_str());
		outtextxy(30, 170 + i * 100, subline2.c_str());
		outtextxy(30, 195 + i * 100, subline3.c_str());
		setcolor(RED);
		outtextxy(60, 145 + i * 100, NAME.c_str());

	}
}
void showText(int id) 

{
	
	string data = hi.GetFile(id);
	vector<string> text = DivineToLine(data, 38);
	int page = 1, total_page = text.size() / 27 + 1;
	Draw(text, page, total_page);
		cout << page << " " << total_page << "\n";
		int is_off = 0;
	while (is_off!=1) {
		int c = getch();
		switch(c)
		{
		
		case 77:
			clearviewport();
			page++;
			page = min(page, total_page);
			break;
		case 75:
			clearviewport();
			page--;
			page = max(page, 1);
			break;
		case 27:
			clearviewport();
			is_off = 1;
			break;
		default:
			break;
		}
		
		Draw(text, page, total_page);
	}
	clearviewport();
	
}



void  File::ResultScreen(string &inputbuf)	
{
	while (1)
	{
#pragma region searching bar
		closegraph();
		initSetup(COLOR(110, 223, 233));
		
		int midx = getmaxx() / 2;
		int midy = getmaxy() / 2;


		// the main bar
		line(20, 10, 650, 10);
		line(20, 40, 650, 40);
		arc(20, 25, 90, -90, 15);
		arc(650, 25, -90, 90, 15);
		//search bar
		line(20, 50, 100, 50);
		line(20, 80, 100, 80);
		arc(20, 65, 90, -90, 15);
		arc(100, 65, -90, 90, 15);
		//text bar
		setfillstyle(10, COLOR(255, 255, 255));
		bar(666, 0, 680, 740);

		//logo
		settextstyle(3, HORIZ_DIR, 3);
		setfillpattern("SLASH_FILL", 15);
		outtextxy(30, 55, "NEM0");
		setfillstyle(SLASH_FILL, COLOR(255, 102, 0));
		floodfill(20, 60, 15);
#pragma endregion

#pragma region show keyword

		if (inputbuf.length() > 0 && inputbuf.length() <= 33)
		{
			settextjustify(LEFT_TEXT, CENTER_TEXT);
			settextstyle(1, HORIZ_DIR, 3);
			outtextxy(20, 30, inputbuf.c_str());
		}
		else if (inputbuf.length() > 33)
		{
			settextjustify(RIGHT_TEXT, CENTER_TEXT);
			settextstyle(1, HORIZ_DIR, 3);
			outtextxy(650, 30, inputbuf.c_str());
			//settextstyle(2, HORIZ_DIR, 3);
			setfillstyle(0, BLUE);
			bar(0, 15, 20, 35);
			arc(20, 25, 90, -90, 15);
		}

#pragma endregion

#pragma region show result
		vector<int> ID;
		settextjustify(LEFT_TEXT, CENTER_TEXT);
		settextstyle(1, HORIZ_DIR, 3);


		//auto start = high_resolution_clock::now();
		hi.ranking(fileNames, inputbuf.c_str(), ID);
		//auto stop = high_resolution_clock::now();

		// Get duration. Substart timepoints to  
		// get durarion. To cast it to proper unit 
		// use duration cast method 
		//auto duration = duration_cast<microseconds>(stop - start);

		//cout << "Time taken by function: "
		//	<< duration.count() << " microseconds" << endl;



		if (ID.size() == 0)
		{
			setcolor(COLOR(229,99,39));
			settextstyle(3, HORIZ_DIR, 3);
			outtextxy(20, 120, "Can not SEA the NEMO you're Finding");
			outtextxy(20, 150, "'(> ~ <)' ");
		}
		else
		{
			for (int i = 0; i < 5 && i < ID.size(); i++)
			{
				settextstyle(1, HORIZ_DIR, 3);
				setcolor(COLOR(229, 99, 39));
				outtextxy(30, 120 + i * 100, fileNames[ID[i] - 1].c_str());

			}

			Highlight(inputbuf, ID);
			//cout << inputbuf;
			//cout << endl;
			//for (int i = 0; i < 5 && i < ID.size(); i++)
			//{
			//	Cout_name_file(fileNames,ID[i]);
			//	cout << ", ";
			//}
			//cout << endl;
		}

#pragma endregion

#pragma region action with keyboard
		string tmp = inputbuf.c_str();
		int the_end = 0;
		int Position = 0;
		while (the_end != 1)
		{
			int c = getch();

			switch (c)
			{
			case 8: /* backspace */

			{
				if (inputbuf.length() <= 0)
				{
					setcolor(WHITE);
					outtextxy(20, 30, "");
				}
				else if (inputbuf.length() > 0 && inputbuf.length() <= 33)
				{
					inputbuf.pop_back();
					setfillstyle(0, BLUE);
					//setcolor(BLUE);
					bar(20, 15, 650, 35);
					setcolor(WHITE);
					settextstyle(1, HORIZ_DIR, 3);

					settextjustify(LEFT_TEXT, CENTER_TEXT);
					outtextxy(20, 30, inputbuf.c_str());
				}
				else if (inputbuf.length() > 33)
				{
					inputbuf.pop_back();
					setcolor(WHITE);
					settextjustify(RIGHT_TEXT, CENTER_TEXT);
					settextstyle(1, HORIZ_DIR, 3);

					outtextxy(650, 30, inputbuf.c_str());
					bar(0, 15, 20, 35);
					arc(20, 25, 90, -90, 15);
				}
			}
			break;
			case 13: /* return */
			{
				
				
					//cleardevice();
					the_end = 1;
					break;
				
				

				
			}
			case 27: /* Escape = Abort */
				inputbuf[0] = 0;
				searchScreen();
				break;
			case 72://UP
			{
				if (ID.size() > 0)
				{
					erasBox(Position);
					Position--;
					if (Position <= 0)
					{
						if (ID.size() < 5)
						{
							Position = ID.size();
							drawBox(Position);
						}
						else if (ID.size() >= 5)
						{
							Position = 5;
							drawBox(Position);
						}
					}

					else
					{
						drawBox(Position);
					}
				}
			}

			break;
			case 80: //Down
			{
				if (ID.size() > 0)
				{
					erasBox(Position);
					Position++;
					if (ID.size() < 5)
					{
						if (Position > ID.size())
						{
							Position = 1;
							drawBox(Position);
						}
						else

							drawBox(Position);

					}
					else
					{
						if (Position > 5)
						{
							Position = 1;
							drawBox(Position);
						}
						else

							drawBox(Position);

					}




				}
			}
			break;
			

			default:
				if (c >= ' ' && c <= '~')
				{
					Position = 0;
					setcolor(WHITE);
					inputbuf += c;
					setfillstyle(0, BLUE);
					bar(20, 15, 650, 35);
					settextstyle(1, HORIZ_DIR, 3);

					if (inputbuf.length() >= 0 && inputbuf.length() <= 33)
					{
						settextjustify(LEFT_TEXT, CENTER_TEXT);
						settextstyle(1, HORIZ_DIR, 3);
						outtextxy(20, 30, inputbuf.c_str());
					}
					else if (inputbuf.length() > 33)
					{
						settextjustify(RIGHT_TEXT, CENTER_TEXT);
						settextstyle(1, HORIZ_DIR, 3);

						outtextxy(650, 30, inputbuf.c_str());
						//settextstyle(2, HORIZ_DIR, 3);
						setfillstyle(0, BLUE);
						bar(0, 15, 20, 35);
						arc(20, 25, 90, -90, 15);

					}

				}








			}
		}

		if (Position == 1)
		{

			showText(ID[Position - 1]);
		}
		if (Position == 2)
		{
			showText(ID[Position - 1]);
		}
		if (Position == 3)
		{
			showText(ID[Position - 1]);
		}
		if (Position == 4)
		{
			showText(ID[Position - 1]);
		}
		if (Position == 5)
		{
			showText(ID[Position - 1]);
		}
#pragma endregion



			
	
	}
}
void InsertScreen() 
{
	
	
	hi.loadFileNames(fileNames);
	hi.insert_synonyms();
	hi.openFiles(fileNames);
	closegraph();
	//string l;
	//hi.Cout_file(5);
	//cout << endl;
	//hi.Cout_name_file(fileNames, 5);
	
}

void searchScreen()
{
	initSetup(COLOR(112,226,236));

	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;

	setcolor(15);
#pragma region search bar
	// the main bar
	line(2 * midx / 5, midy, 8 * midx / 5, midy);
	line(2 * midx / 5, midy + 50, 8 * midx / 5, midy + 50);
	arc(2 * midx / 5, midy + 25, 90, -90, 25);
	arc(8 * midx / 5, midy + 25, -90, 90, 25);
	//the search button 
	setcolor(15);



	line(7 * midx / 5, midy + 25 / 4, 8 * midx / 5, midy + 25 / 4);
	line(7 * midx / 5, midy + 175 / 4, 8 * midx / 5, midy + 175 / 4);
	arc(7 * midx / 5, midy + 25, 90, -90, 3 * 25 / 4);
	arc(8 * midx / 5, midy + 25, -90, 90, 3 * 25 / 4);

	


#pragma endregion


#pragma region LOGO
	//setfillpattern
	setfillstyle(LTBKSLASH_FILL, 15);
	setcolor(COLOR(115,229,239));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 10);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	//setusercharsize(1, 4, 4, 1);
	outtextxy(midx, midy - 35, "NEW        RCH");
	setcolor(COLOR(229, 99, 39));
	outtextxy(midx + 10, midy - 35, "S   A");

	{setcolor(15);
	outtextxy(midx - 7, midy - 35, "E");
	}
	//for (int i = 0; i < 12; i++)
	{
		settextstyle(9, HORIZ_DIR, 4);
		setfillpattern("SLASH_FILL", 15);
		//setbkcolor(15);

		outtextxy(1020, midy + 35, "NEMO");
		setfillstyle(SLASH_FILL, COLOR(255, 102, 0));
		floodfill(980, 395, 15);
		//getch();
	}

#pragma endregion

#pragma region input string

	settextjustify(LEFT_TEXT, CENTER_TEXT);
	settextstyle(9, HORIZ_DIR, 4);
	string inputbuf = "";
	int input_pos = 0;
	int the_end = 0;
	while (the_end != 1)
	{
		int c = getch();
		switch (c)
		{
		case 8: /* backspace */

		{
			if (inputbuf.length() <= 0) {
				setcolor(WHITE);
				outtextxy(2 * midx / 5, midy + 30, "");
			}
			else if (inputbuf.length() > 0 && inputbuf.length() <= 28)

			{
				inputbuf.pop_back();
				setfillstyle(0, BLUE);
				//setcolor(BLUE);
				bar(2 * midx / 5 - 10, midy + 5, 930, midy + 40);
				setcolor(COLOR(229, 99, 39));
				settextjustify(LEFT_TEXT, CENTER_TEXT);
				outtextxy(2 * midx / 5, midy + 30, inputbuf.c_str());
			}
			else if (inputbuf.length() > 28)
			{
				inputbuf.pop_back();
				setcolor(COLOR(229, 99, 39));
				settextjustify(RIGHT_TEXT, CENTER_TEXT);
				outtextxy(920, midy + 30, inputbuf.c_str());
				bar(0, midy + 5, 2 * midx / 5 - 10, midy + 40);
				arc(2 * midx / 5, midy + 25, 90, -90, 25);
			}
		}
		break;
		case 13: /* return */
		{
			if (inputbuf.length() >0)
			{

				the_end = 1;
			
				


			}
		}
		break;
		case 27: /* Escape = Abort */
			inputbuf[0] = 0;
			the_end = 1;
			break;
		default:
			if (c >= ' ' && c <= '~')
			{
				setcolor(COLOR(229, 99, 39));
				inputbuf += c;
				setfillstyle(0, BLUE);
				bar(2 * midx / 5 - 10, midy + 5, 930, midy + 40);

				if (inputbuf.length() >= 0 && inputbuf.length() <= 28)
					outtextxy(2 * midx / 5, midy + 30, inputbuf.c_str());
				else if (inputbuf.length() > 28)
				{
					settextjustify(RIGHT_TEXT, CENTER_TEXT);

					outtextxy(920, midy + 30, inputbuf.c_str());
					setfillstyle(0, BLUE);
					bar(0, midy + 5, 2 * midx / 5 - 10, midy + 40);
					arc(2 * midx / 5, midy + 25, 90, -90, 25);

				}
			}
		}



	}
	closegraph();
	hi.ResultScreen(inputbuf);
}




#endif // !_UI_H_
