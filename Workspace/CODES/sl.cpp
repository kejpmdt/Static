#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define color(i) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i)
using namespace std;
int main()
{
   char zong, boon[99][99] = {" ", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################"}, boontemp[99][99];
   srand(time(0));
   string ccaa;
   string myid;
   bool te = 0;
   int te1 = 0;
   char mba = 'y';
   int qzi, num;
   char daoju[5][999] = {"神器3级头", "超级空投", "自动消除", "C4炸弹", "旗开得胜"};
   color(4);
   bool flag1 = 1;
   int deng[5] = {1, 1, 1, 1, 1};
   int choice, peaple, ming = 0, qi = 0, zi = 0;
   string id[99999];
   int number[99999], win[99999];
   cout << "请输入ID:" << endl;
   cin >> myid;
   if (myid == "神级玩家.数学大王.周义畯")
   {
      cout << "您好，尊敬的创世主！" << endl;
      for (int i = 0; i <= 4; i++)
      {
         deng[i] = 4;
      }
   }
   else if (myid == "黑客")
   {
      printf("你好，黑客!\n");
      for (int i = 0; i <= 4; i++)
      {
         deng[i] = 5;
      }
   }
   else if (myid == "爸爸")
   {
      cout << "创世主的爸爸，欢迎您" << endl;
      for (int i = 0; i <= 4; i++)
      {
         deng[i] = 2;
      }
      te = 1;
   }
   else if (myid == "11")
   {
      cout << "您好，创世主的弟弟" << endl;
      for (int i = 0; i <= 4; i++)
      {
         deng[i] = 3;
      }
      deng[3] = 5;
   }
   else if (myid == "温柔的回旋镖")
   {
      cout << "温柔征服一切" << endl;
      te1 = 3;
   }
   else
   {
      cout << "你好，游客" << endl;
   }
   cout << "\t扫雷游戏" << endl;
   color(6);
   cout << "用你的智慧排查出所有的地雷吧" << endl;
   color(8);
   cout << "按WASD控制光标移动" << endl;
   color(5);
   cout << "Q翻开，E插旗" << endl;
   color(15);
   int c4 = 0;
   system("pause");

   while (mba == 'y')
   {
      char boon[99][99] = {" ", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################", "############################################"};
      cout << "请选择你的道具：";
      for (int i = 0; i <= 4; i++)
      {
         cout << i + 1 << "." << daoju[i] << " " << deng[i] << "级" << endl;
      }
      cin >> choice;
      if (choice > 0 && choice < 6)
      {
         cout << "你选择了" << daoju[choice - 1] << endl;
      }
      if (choice == 1)
      {
         ming = deng[choice - 1];
      }
      else if (choice == 2)
      {
         qi = 10 - (8 - deng[choice - 1]);
         if (qi >= 1)
         {
         }
         else
         {
            qi = 1;
         }
         cout << "超级空投生效，地雷个数-" << qi << endl;
      }
      else if (choice == 3)
      {
         zi = 2 + deng[choice - 1];
         if (zi >= 10)
         {
            zi = 9;
         }
         cout << "自动消除生效，自动标记" << zi << "个雷" << endl;
      }
      else if (choice == 4)
      {
         c4 = pow((deng[choice - 1] + 1), 2);
         if (c4 >= 90)
         {
            c4 = 81;
         }
         cout << "C4炸弹生效，自动炸开" << c4 << "个方格" << endl;
      }
      else if (choice == 5)
      {
         qzi = deng[choice - 1] + 2;
      }
      else
      {
         cout << "你没有获得任何道具" << endl;
      }
      int nandu;
      cout << "请选择你所挑战的难度：1.简单 2.中等 3.困难 4.地狱" << endl;
      cin >> nandu;
      if (nandu > 4)
      {
         cout << "竟敢乱输，接受惩罚吧" << endl;
         nandu = 4;
      }
      int m, n;
      int BOON_number;
      int NUMBER_number;
      if (nandu == 1)
      {
         m = 10, n = 10;
         BOON_number = 10;
         BOON_number -= qi;
         NUMBER_number = 100 - BOON_number;
      }
      else if (nandu == 2)
      {
         m = 15, n = 15;
         BOON_number = 30;
         BOON_number -= qi;
         NUMBER_number = 225 - BOON_number;
      }
      else if (nandu == 3)
      {
         m = 20, n = 20;
         BOON_number = 50;
         BOON_number -= qi;
         NUMBER_number = 400 - BOON_number;
      }
      else if (nandu == 4)
      {
         m = 30, n = 30;
         BOON_number = 100;
         BOON_number -= qi;
         NUMBER_number = 900 - BOON_number;
      }
      int sum;
      bool flag;
      int tempx = 1, tempy = 1;
      char a[m + 2][n + 2] = {}, cca;
      for (int i = 1; i <= BOON_number; i++)
      {
         tempx = rand() % m + 1;
         tempy = rand() % n + 1;
         while (a[tempx][tempy] == '*')
         {
            tempx = rand() % m + 1;
            tempy = rand() % n + 1;
         }
         if (zi > 0)
         {
            boontemp[tempx][tempy] = '!';
            boon[tempx][tempy] = '!';
            zi--;
         }
         a[tempx][tempy] = '*';
      }
      for (int c = 1; c <= m; c++)
      {
         for (int d = 1; d <= n; d++)
         {
            sum = 48;
            if (a[c][d] != '*')
            {
               if (a[c + 1][d + 1] == '*')
               {
                  sum++;
               }
               if (a[c - 1][d - 1] == '*')
               {
                  sum++;
               }
               if (a[c + 1][d - 1] == '*')
               {
                  sum++;
               }
               if (a[c - 1][d + 1] == '*')
               {
                  sum++;
               }
               if (a[c][d - 1] == '*')
               {
                  sum++;
               }
               if (a[c][d + 1] == '*')
               {
                  sum++;
               }
               if (a[c + 1][d] == '*')
               {
                  sum++;
               }
               if (a[c - 1][d] == '*')
               {
                  sum++;
               }
               a[c][d] = (char)sum;
            }
         }
      }
      int xxxx = 0, yyyy = 0;
      while (c4 > 0)
      {
         xxxx = rand() % m + 1;
         yyyy = rand() % n + 1;
         while (a[xxxx][yyyy] == '*' && boontemp[xxxx][yyyy] != '#')
         {
            xxxx = rand() % m + 1;
            yyyy = rand() % n + 1;
         }
         boontemp[xxxx][yyyy] = a[xxxx][yyyy];
         boon[xxxx][yyyy] = a[xxxx][yyyy];
         c4--;
         NUMBER_number--;
      }
      for (int i = 1; i <= m + 1; i++)
      {
         for (int j = 1; j <= n + 1; j++)
         {
            cout << boon[i][j];
            boontemp[i][j] = boon[i][j];
         }
         cout << endl;
      }

      boon[5][5] = ' ';
      int xx = 5, yy = 5;
      while (true)
      {
         cca = getch();
         system("cls");
         if (cca == 'w')
         {
            if (xx - 1 >= 1)
            {
               boon[xx][yy] = boontemp[xx][yy];
               --xx;
               boon[xx][yy] = ' ';
            }
         }
         if (cca == 'a')
         {
            if (yy - 1 >= 1)
            {
               boon[xx][yy] = boontemp[xx][yy];
               --yy;
               boon[xx][yy] = ' ';
            }
         }
         if (cca == 's')
         {
            if (xx + 1 <= m + 1)
            {
               boon[xx][yy] = boontemp[xx][yy];
               ++xx;
               boon[xx][yy] = ' ';
            }
         }
         if (cca == 'd')
         {
            if (yy + 1 <= n + 1)
            {
               boon[xx][yy] = boontemp[xx][yy];
               ++yy;
               boon[xx][yy] = ' ';
            }
         }
         if (cca == 'q' && (boontemp[xx][yy] == '#' or boontemp[xx][yy] == '!'))
         {
            if (a[xx][yy] != '*')
            {
               if (te && (a[xx][yy] == '2' || a[xx][yy] == '3'))
               {
                  for (int i = -1; i <= 1; i++)
                  {
                     for (int j = -1; j <= 1; j++)
                     {
                        if (a[xx + i][yy + j] == '*' && te == 1)
                        {
                           boon[xx + i][yy + j] = '!';
                           boontemp[xx + i][yy + j] = '!';
                           te = 0;
                        }
                     }
                  }
                  te = 1;
                  boon[xx][yy] = a[xx][yy];
                  boontemp[xx][yy] = a[xx][yy];
                  NUMBER_number--;
               }
               else
               {
                  boon[xx][yy] = a[xx][yy];
                  boontemp[xx][yy] = a[xx][yy];
                  NUMBER_number--;
               }
            }
            else
            {
               if (ming >= 1)
               {
                  ming--;
                  cout << "神器三级头生效，保护了你" << endl;
                  boon[xx][yy] = a[xx][yy];
                  boontemp[xx][yy] = a[xx][yy];
               }
               else
               {
                  MessageBox(0, "GAME OVER!!!", "警告", MB_OK);
                  boon[xx][yy] = a[xx][yy];
                  for (int i = 1; i <= m; i++)
                  {
                     for (int j = 1; j <= n; j++)
                     {
                        cout << boon[i][j];
                     }
                     cout << endl;
                  }
                  system("pause");
                  system("cls");
                  color(4);
                  cout << "GAME OVER!!!" << endl;
                  cout << "你是否再来一盘（y/n）" << endl;
                  cin >> mba;
                  if (mba != 'y')
                  {
                     cout << "感谢你游玩此游戏" << endl;
                     return 0;
                  }
                  else
                  {
                     color(15);
                     break;
                  }
                  color(15);
               }
            }
         }
         if (cca == 'e' && boontemp[xx][yy] == '#')
         {
            if (qzi > 0 && a[xx][yy] != '*')
            {
               cout << "旗开得胜生效，翻开标记错误的地方，共3次机会" << endl;
               boon[xx][yy] = a[xx][yy];
               boontemp[xx][yy] = a[xx][yy];
               NUMBER_number--;
               qzi--;
            }
            else
            {
               boon[xx][yy] = '!';
               boontemp[xx][yy] = '!';
            }
         }
         else if (cca == 'o' && te1 >= 1)
         {
            cout << a[xx][yy] << endl;
            te1--;
         }
         if (NUMBER_number <= 0)
         {
            MessageBox(0, "You win!", "恭喜", MB_OK);
            boon[xx][yy] = a[xx][yy];
            for (int i = 1; i <= m; i++)
            {
               for (int j = 1; j <= n; j++)
               {
                  cout << boon[i][j];
               }
               cout << endl;
            }
            system("pause");
            system("cls");
            color(6);
            cout << "YOU WIN!" << daoju[choice - 1] << "升级！" << endl;
            deng[choice - 1]++;
            color(15);
            cout << "你是否再来一盘（y/n）" << endl;
            cin >> mba;
            if (mba != 'y')
            {
               cout << "感谢你游玩此游戏" << endl;
               return 0;
            }
            else
            {
               color(15);
               break;
            }
         }

         cout << NUMBER_number << endl;
         for (int i = 1; i <= m; i++)
         {
            for (int j = 1; j <= n; j++)
            {
               cout << boon[i][j];
            }

            cout << endl;
         }
      }
   }
   return 0;
}