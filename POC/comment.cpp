#include<iostream>
using namespace std;
int main()
{
	char input[40];
	int flag=0;
	cout<<"Enter the line:";
	gets(input);
	if(input[0]=='/')
	{
		if(input[1]=='/')
		{
			cout<<"\nIt is single line comment";
		}
		else if(input[1]=='*')
		{
			for(int i=2;input[i]!='\0';i++)
			{
				if(input[i]=='*' && input[i+1]=='/' && input[i+2]=='\0')
				{
					cout<<"\nIt is a multiline comment";
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nIt is not multiline comment";
			}
		}
		else{
			cout<<"\nIt is not comment line";
		}
	}
	else{
		cout<<"\nIt is not comment";
	}
	return 0;
}
