/*

Vertex Mover by Aren Taylan
used to mod The Legend of Zelda: Ocarina of Time


*/

// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <stdint.h>
using namespace std;

unsigned char str2hex(string input);
string hex2str(unsigned char num);

int main () {
    string inFileName;
    string outFileName;
    cout << "What is the filename that contains the original vertex data? (ex. vertex.txt) \n";
    cin >> inFileName;
    cout << "\n";
    cout << "And what do you want the output file to be? (ex. vertexOutput.txt) \n";
    cin >> outFileName;
    cout << "\n";

    cout << "Original Vertex Data: \n \n";

  string line;
  int NLcounter = 0;
  int linecounter = 0;
  ifstream infile;
  infile.open (inFileName);
  if(infile.is_open())
  {
      while(getline(infile, line, ' ')){
        cout << line << ' ';
        NLcounter++;
        if(NLcounter == 16)
        {
            cout<< "LINE NUMBER:" <<  linecounter;
            cout << '\n';
            NLcounter = 0;
            linecounter++;
        }
      }
      cout << "\n";
      cout << "AMOUNT OF TOTAL LINES: " << linecounter << "\n";
      cout << "\n";
      infile.close();
  }
int pNumLines = linecounter;


    unsigned char vertData[16][pNumLines];
   // unsigned char hData = 0;
   // hData-=3;
   // cout << static_cast<unsigned>(hData) << '\n';

    NLcounter = 0;
      linecounter = 0;

    infile.open (inFileName);
    if(infile.is_open())
        {
            while(getline(infile, line, ' '))
            {
                vertData[NLcounter][linecounter] = str2hex(line);
              //  cout << static_cast<unsigned>(vertData[NLcounter][linecounter]) << ' ';
                NLcounter++;
                if(NLcounter == 16)
                {
                   // cout << '\n';
                    NLcounter = 0;
                    linecounter++;
                }
            }
            infile.close();
        }
    else
        cout << "Can't open file";

        cout << "Converted data to number information. \n How do you want to modify the vertex?\n";
        int AXISchoice = 0;
        cout << "1: X axis\n";
        cout << "2: Y axis\n";
        cout << "3: Z axis\n";
        cin >> AXISchoice;

        cout << "Major change or minor change?\n";
        int MMchoice = 0;
        cout << "1: Major\n";
        cout << "2: Minor\n";
        cin >> MMchoice;

        cout << "Move positively or negatively?\n";
        int PNchoice = 0;
        cout << "1: Positively\n";
        cout << "2: Negatively\n";
        cin >> PNchoice;

        if(PNchoice == 2)
        {
            PNchoice = -1;
        }

        cout << "And finally, by how much? (input an integer between 0-255)\n";
        int movement = 0;
        cin >> movement;

        switch(AXISchoice)
        {
        case 1:
            {
                for(int i=0;i<pNumLines;i++)
                {
                    vertData[0+(MMchoice-1)][i] += movement*PNchoice;
                }
                break;
            }
        case 2:
            {
                for(int i=0;i<pNumLines;i++)
                {
                    vertData[2+(MMchoice-1)][i] += movement*PNchoice;
                }
                break;
            }
        case 3:
            {
                for(int i=0;i<pNumLines;i++)
                {
                    vertData[4+(MMchoice-1)][i] += movement*PNchoice;
                }
                break;
            }

        }

        cout << "Converted!\n Modified Vertex Data: \n";

        ofstream outfile;
        outfile.open(outFileName);

        for(int i = 0;i<pNumLines;i++)
        {
            for(int j=0;j<16;j++)
            {
                cout << hex2str(vertData[j][i]) << " ";
                outfile << hex2str(vertData[j][i]);
                outfile << " ";
            }
            outfile << "\n";
            cout << "\n";
        }


  return 0;
}

unsigned char str2hex(string input)
{
    char left;
    char right;
    unsigned char result = 0;
    left = input[0];
    right = input[1];
    switch(left)
    {
        case '0':
            result+=0;
            break;
        case '1':
            result+=16;
            break;
        case '2':
            result+=32;
            break;
        case '3':
            result+=48;
            break;
        case '4':
            result+=64;
            break;
        case '5':
            result+=80;
            break;
        case '6':
            result+=96;
            break;
        case '7':
            result+=112;
            break;
        case '8':
            result+=128;
            break;
        case '9':
            result+=144;
            break;
        case 'A':
            result+=160;
            break;
        case 'B':
            result+=176;
            break;
        case 'C':
            result+=192;
            break;
        case 'D':
            result+=208;
            break;
        case 'E':
            result+=224;
            break;
        case 'F':
            result+=240;
            break;
    }
    switch(right)
    {
        case '0':
            result+=0;
            break;
        case '1':
            result+=1;
            break;
        case '2':
            result+=2;
            break;
        case '3':
            result+=3;
            break;
        case '4':
            result+=4;
            break;
        case '5':
            result+=5;
            break;
        case '6':
            result+=6;
            break;
        case '7':
            result+=7;
            break;
        case '8':
            result+=8;
            break;
        case '9':
            result+=9;
            break;
        case 'A':
            result+=10;
            break;
        case 'B':
            result+=11;
            break;
        case 'C':
            result+=12;
            break;
        case 'D':
            result+=13;
            break;
        case 'E':
            result+=14;
            break;
        case 'F':
            result+=15;
            break;
    }
    return result;

}

string hex2str(unsigned char num)
{
    int rNum = num%16;
    int lNum = num/16;
    char cLeft;
    char cRight;
    switch(lNum)
    {
    case 0:
        {
            cLeft = '0';
            break;
        }

    case 1:
        {
            cLeft = '1';
            break;
        }
    case 2:
        {
            cLeft = '2';
            break;
        }
    case 3:
        {
            cLeft = '3';
            break;
        }
    case 4:
        {
            cLeft = '4';
            break;
        }
    case 5:
        {
            cLeft = '5';
            break;
        }
    case 6:
        {
            cLeft = '6';
            break;
        }
    case 7:
        {
            cLeft = '7';
            break;
        }
    case 8:
        {
            cLeft = '8';
            break;
        }
    case 9:
        {
            cLeft = '9';
            break;
        }
    case 10:
        {
            cLeft = 'A';
            break;
        }
    case 11:
        {
            cLeft = 'B';
            break;
        }
    case 12:
        {
            cLeft = 'C';
            break;
        }
    case 13:
        {
            cLeft = 'D';
            break;
        }
    case 14:
        {
            cLeft = 'E';
            break;
        }
    case 15:
        {
            cLeft = 'F';
            break;
        }
    }

    switch(rNum)
    {
    case 0:
        {
            cRight = '0';
            break;
        }

    case 1:
        {
            cRight = '1';
            break;
        }
    case 2:
        {
            cRight = '2';
            break;
        }
    case 3:
        {
            cRight = '3';
            break;
        }
    case 4:
        {
            cRight = '4';
            break;
        }
    case 5:
        {
            cRight = '5';
            break;
        }
    case 6:
        {
            cRight = '6';
            break;
        }
    case 7:
        {
            cRight = '7';
            break;
        }
    case 8:
        {
            cRight = '8';
            break;
        }
    case 9:
        {
            cRight = '9';
            break;
        }
    case 10:
        {
            cRight = 'A';
            break;
        }
    case 11:
        {
            cRight = 'B';
            break;
        }
    case 12:
        {
            cRight = 'C';
            break;
        }
    case 13:
        {
            cRight = 'D';
            break;
        }
    case 14:
        {
            cRight = 'E';
            break;
        }
    case 15:
        {
            cRight = 'F';
            break;
        }
    }

    string result = "";
    result += cLeft;
    result += cRight;
    return result;
}


