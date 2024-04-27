#include<iostream>
#include"mini_header.h"

#include<windows.h>
using namespace std;

int main()
{	
	system("CLS");
	int npeo,team[20][20],skil[20][20],nskil,i,k,j,max,pos[20],
	m,count=0,size=0,l,pteam[20][20];  
	char bold=27;
	
	colour(4);

	string n="\n\n\t\t\t\t\t\t\t*****WELCOME TO TEAM PREDICTOR*****\n\n";
    delay(n);

	//Text Colour
	colour(3);
	
	//Check valid input for Players
	start1:

    colour(2);
	cout<<"\n\tENTER TOTAL NO. OF PLAYERS: ";
    colour(3);
	cin>>npeo;

	if(npeo<=1)
	{   
        colour(1);

		cout<<"\n\tNote : No. of Players should be Greater than 1 (PLAYER>1)"<<endl;
		
		goto start1;
	}
	cout<<endl;
	
	//Check valid input for Skill
	start2:

    colour(2);
	cout<<"\n\tENTER NO. OF SKILLS: ";
    colour(3);
	cin>>nskil;
	
	if(nskil<1)
	{   
        colour(1);

		cout<<"\n\tNote : No. of Skills should be Greater than 0 (SKILL>0)"<<endl;
		
		goto start2;
	}
	cout<<endl;

	//Input for Skills
    colour(2);
	cout<<"\tENTER PLAYER RATING PER SKILL\n"<<endl;
	colour(1);
	cout<<bold<<"[1m"<<"\t   ***RATE OUT OF 5***"<<bold<<"[0m"<<endl;
	cout<<"\t  [Demo: Player A: 2 3 1]\n"<<endl;
    colour(3);
	for(i=1;i<=npeo;i++)
	{	
		cout<<"\tPlayer "<<i<<": ";
		for(j=1;j<=nskil;j++)
		{
			cin>>skil[i][j];
		}
	}
		
	//All possible team
    colour(2);
	cout<<"\n\tALL POSSIBLE TEAMS ARE:\n"<<endl;
    colour(3);
	for(i=1,k=1;i<=npeo;i++)
     	{
		for(j=i+1;j<=npeo;j++)
		{
			cout<<"\tTEAM "<<k<<": "<<"Player "<<i<<" & "<<"Player "<<j<<endl;
			k++;
			count++;
		}
    	}
    	cout<<endl;
		
        colour(2);

		//Total no. of Teams
    	cout<<"\tTOTAL TEAMS: ";
		
		colour(3);

		cout<<count<<endl;
    	cout<<endl;
    	
		colour(3);
    	//Store position of Team
    	for(i=1,m=1;i<=npeo;i++)
     	{
		for(j=i+1;j<=npeo;j++)
		{
			pteam[m][1]=i;
			pteam[m][2]=j;
			m++;	
		}
    	}
	
	
	/*
	//Print Teams players with the array (For Checking)
	cout<<"TEAM AND PLAYERS:"<<endl;
	for(i=1;i<=count;i++)
	{
		cout<<"TEAM  "<<i<<":"<<" Player: "<<pteam[i][1]<<" Player: "<<pteam[i][2]<<endl;
	}
	cout<<endl;
	*/
    
    
    	//Create Team Score
    	l=1;
    	for(i=1;i<=npeo;i++)
    	{
		for(j=i+1;j<=npeo;j++)
		{	
			for(k=1;k<=nskil;k++)
			{
				team[l][k]=skil[i][k]+skil[j][k];
			}
			l++;
		}	
    	}

	//print team score per skill
    /*
	colour(2);
	cout<<"\tTEAM SCORE PER SKILLS:\n"<<endl;
    colour(3);
    	for(i=1;i<=count;i++)
    	{	
            
    		cout<<"\t| TEAM: "<<i;
    		for(j=1;j<=nskil;j++)
    		{
    			cout<<"| S"<<j<<": "<<team[i][j];
    		}
    		cout<<"|"<<endl;
    	}
    */		
    	
    	
  	//claculate Final Team Score
  	int finaltem[count];
	for(i=1;i<=count;i++)
	{	
		finaltem[i]=0;
		for(j=1;j<=nskil;j++)
		{
			finaltem[i]=team[i][j]+finaltem[i];
		}
		
	}
	
	/*
	//Print final team score (For Checking)
	cout<<"\nTOTAL SCORE OF TEAM:"<<endl;
	for(i=1;i<=count;i++)
	{	
		
		cout<<"| Team "<<i<<" | "<<finaltem[i]<<"   |"<<endl;
	}
	*/
	
	//find max score
	max=finaltem[1];
	for(i=2;i<=count;i++)
	{
		if(max<finaltem[i])
		{
			max=finaltem[i];
			
		}
	}
	
	//Find best Team with equal score
	for(i=1,j=1;i<=count;i++)
	{
		if(finaltem[i]==max)
		{
			pos[j]=i;
			j++;
			size++;
		}
	}
	

	//Print Final Teams
    colour(2);
	cout<<"\n\tMOST EFFICIENT TEAM: \n"<<endl;
    colour(5);
	for(i=1;i<=size;i++)
	{
		cout<<"\tTEAM "<<pos[i]<<": "<<"Player "<<pteam[pos[i]][1]<<" & "<<"Player "<<pteam[pos[i]][2]<<endl;
		
	}
	cout<<endl;
	colour(3);
	
}
	
