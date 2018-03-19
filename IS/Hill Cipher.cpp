#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	 int ch,val,inkey[2][2],key[2][2],v[2],i,j,t1,t2;
	 char Plain[100],Plaintext[100],Ciphertext[100];
	cout<<"\n1.Plaintext to Ciphertext";
	cout<<"\n2.Ciphertext to Plaintext";
	cout<<"\nEnter your choice[1/2]";
	cin>>ch;
	 if(ch==1)
	 {
	 
	 cout<<"\nEnter the key matrix 2x2 in row major order:";
	 for(i=0;i<2;i++)
	 {
	 	for(j=0;j<2;j++)
	 	{
	 		cin>>key[i][j];
		 }
	 }
	 val=(key[1][1]*key[0][0])-(key[1][0]*key[0][1]);
	 if(val==0)
	 {
	 	cout<<"\nEnter key is invalid";
	 }
	 fflush(stdin);
	 cout<<"\nEnter Plain text:";
	 gets(Plain);
	 for(i=0;i<strlen(Plain);i++)
	 {
	 	Plain[i]=toupper(Plain[i]);
	 }
	 cout<<Plain<<endl;
	 i=0;
	 j=0;
	 while(i<strlen(Plain))
	 {
	 	if(Plain[i]==' ')
	 	{
	 		i++;
	 		continue;
		 }
		 Plaintext[j++]=Plain[i++];
	 }
	 cout<<Plaintext<<endl;
	 if((strlen(Plaintext)%2)==1)
	 {
	 	Plaintext[j++]='X';
	 	Plaintext[j]='\0';
	 }
	 for(i=0;i<strlen(Plaintext);i=i+2)
	 {
	 	v[0]=Plaintext[i]-65;
	 	v[1]=Plaintext[i+1]-65;
	 	t1=(key[0][0]*v[0]+key[0][1]*v[1])%26;
	 	t2=(key[1][0]*v[0]+key[1][1]*v[1])%26;
	 	Ciphertext[i]=char(t1+65);
	 	Ciphertext[i+1]=char(t2+65);
	 }
	 cout<<Ciphertext;}
	 else{
	 
	 fflush(stdin);
	 cout<<"\nEnter Ciphertext:";
	 gets(Ciphertext);
	 cout<<"\nEnter the key matrix 2x2 in row major order:";
	 for(i=0;i<2;i++)
	 {
	 	for(j=0;j<2;j++)
	 	{
	 		cin>>key[i][j];
		 }
	 }
	 val=(key[1][1]*key[0][0])-(key[1][0]*key[0][1]);
	 if(val==0)
	 {
	 	cout<<"\nEnter key is invalid";
	 }
	 else if(val!=1)
	 {	if(val<0){
	 	while(!(val>0))
	 	{
	 		val=val+26;
		 }}
		 for(i=1;i<26;i++)
		 {
		 	if((val*i)%26==1)
		 	{
		 		break;
			 }
		 }
		 inkey[0][0]=(key[1][1]*i)%26;
		 inkey[1][1]=(key[0][0]*i)%26;
		 inkey[0][1]=((26-key[0][1])*i)%26;
	 	inkey[1][0]=((26-key[1][0])*i)%26;
	 	
	 for(i=0;i<strlen(Ciphertext);i=i+2)
	 {
	 	v[0]=Ciphertext[i]-65;
	 	v[1]=Ciphertext[i+1]-65;
	 	t1=(inkey[0][0]*v[0]+inkey[0][1]*v[1])%26;
	 	t2=(inkey[1][0]*v[0]+inkey[1][1]*v[1])%26;
	 	Plaintext[i]=char(t1+65);
	 	Plaintext[i+1]=char(t2+65);
	 }	
	 cout<<"\nPlaintext:"<<Plaintext;
	 }
}
	return 0;
}
