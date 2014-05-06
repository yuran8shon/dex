// dex.cpp : Defines the entry point for the console application.
//

/**
@mainpage ����������, ����������� �������� ��������".
* 
*�������� ��������� �������� � ����� ���������� ���� ����� ����� ���������.
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
int vol;

//�������� ��������

/** 
* \fn void DEX()
* \brief �������, ����������� �������� ��������. 
* 
* ������� ��������� �������� ��������. ��� �� � ��� �� ���������� ��������� ������ � ���������� ���������� ����� ���������.
*
*/
void DEX()
{
	int st;
	cout << " ���-��: "; cin >> vol;

    int **bl = new int*[vol]; 
    for (int count = 0; count < vol; count++)
		bl[count] = new int[vol];
	
	for (int i = 0; i < vol; i++)
		for (int j=0; j < vol; j++){
			if (i != j){
				system("cls");
				cout << i+1 << "-->" << j+1 << ": ";
				cin >> bl[i][j];
			}
		}

	system("cls");
	for (int i = 0; i < vol; i++){
		for (int j=0; j < vol; j++){			
			if (i == j) cout << 0 << " ";
			else 
			cout << bl[i][j] << " ";			
		}
	cout << endl;
	}
cout<<"��������� ������� >> "; cin>>st;
st--;


int *distance = new int[vol];
int count, index, i, u, m=st+1;
bool *volisited = new bool[vol];
for (i=0; i<vol; i++)
{
distance[i]=INT_MAX; volisited[i]=false;
}
distance[st]=0;
for (count=0; count<vol-1; count++)
{
int min=INT_MAX;
for (i=0; i<vol; i++)
if (!volisited[i] && distance[i]<=min)
{
min=distance[i]; index=i;
}
u=index;
volisited[u]=true;
for (i=0; i<vol; i++)
if (!volisited[i] && bl[u][i] && distance[u]!=INT_MAX &&
distance[u]+bl[u][i]<distance[i])
distance[i]=distance[u]+bl[u][i];
}
cout<<"���� �� ��������� ������� �� ���������:\t\n";
for (i=0; i<vol; i++) if (distance[i]!=INT_MAX)
cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;
else cout<<m<<" > "<<i+1<<" = "<<"���� ����������"<<endl;
}
//������� �������
int main()
{
setlocale(LC_ALL, "Rus");

DEX();
}

