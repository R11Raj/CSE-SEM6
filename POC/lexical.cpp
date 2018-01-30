#include<iostream>
#include<fstream>
#include<string.h>
//#include<ctype>
using namespace std;
int main()
{
	 fstream file;
	 file.open("C:\\Users\\DELL\\Desktop\\ex.txt",ios::in | ios::out);
	 char c;
	 int i=0,flag;
	 string word;
	 string key[]={"if","else","void","int","main","float","char","string","switch","for","do","while"};
	char op[]={'*','+','-','/','%','^','!','=','>','<'};
	char sp[]={',','{','}','[',']',';',':','.'};
	 while(!file.eof())
	 {
	 	flag=0;
	 	file.get(c);
	 	if(isdigit(c))
	 	{
	 		cout<<c<<" It is a number\n";
	 		flag=1;
		}
		for(i=0;i<10;i++)
		{
			if(c==op[i])
			{
				cout<<c<<" It is operator\n";
			flag=1;
			}
		}
		for(i=0;i<8;i++)
		{
			if(c==sp[i])
			{
				cout<<c<<" It is special character\n";
			flag=1;
			}
		}
		if(flag==0)
		{
			file.seekp(-1,ios::cur);
			file>>word;
			for(i=0;i<12;i++)
			{
				if(strcmp(word,key[i])==0)
				{
					cout<<word<<" it is a keyword";
				}
			}
		}
		
		
	}
	 
	 return 0;
}
