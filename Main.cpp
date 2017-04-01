h#include<iostream>
#include<fstream>
void sentencebreak(char sentence[], int &, int &, int &);
void solidwords(char sentence[], int &, int &, int &);
void stopwords(char word[], int &, int &,int &);
void lowercase(char word[]);
void dictionary(char word[], int & ,int &,int &);
using namespace std;
int main()
{
	float p_count=0,n_count=0;
	int t_count=0, t_positive=0, t_negative=0;
	char sentence[50]={'\0'};
	char word[50]={'\0'};
	cout<< " enter the sentence"<<endl;
	cin.getline( sentence,50);
	 sentencebreak(sentence,t_count,t_positive,t_negative);
	 cout<<"        Without Normalization"<<endl;
	 cout<<"Total :"<<t_count<<endl;
	 cout<<"positive :"<< t_positive<<endl;
	 cout<<"Negative :"<<t_negative<<endl;
	 if(t_positive>t_negative)
	 {
		 cout<<"Sentence is positive"<<endl;
	 }
	 else
	 {
		 cout<<"Sentence is negative"<<endl;
	 }
	 cout<<"        With Normalization"<<endl;
	 cout<<"Total :"<<t_count<<endl;
	 p_count=float(t_positive)/float(t_count);
	 n_count=float(t_negative)/float(t_count);
	 cout<<"Positive :"<<p_count<<endl;
	 cout<<"Negative :"<<n_count<<endl;
	 if(p_count>n_count)
	 {
		 cout<<"Sentence is positive"<<endl;
	 }
	 else
	 {
		 cout<<"Sentence is negative"<<endl;
	 }
	return 0;

}
	void sentencebreak(char sentence[],int &t_count, int &t_positive, int &t_negative)
	{
		
		char word[50]={'\0'};
		for(int i=0;sentence[i]!='\0';i++)
	     {    int j=0;
			for(;sentence[i]!=' ' && sentence[i]!='.' && sentence[i]!='\0';j++,i++)
			{
			  word[j]=sentence[i];
			}
		     word[j]='\0';
			//cout<< word <<endl;
			 lowercase(word);
			 solidwords(word,t_count,t_positive,t_negative);
	     }
		

	}
	void solidwords(char word[],int &t_count, int &t_positive, int &t_negative)
	{
				int flag=0;
		for(int i=0; word[i]!='\0' ;i++)
		{
			if(word[i]>='a' && word[i]<='z'|| word[i]>='A' && word[i]<='Z')
			{
				 flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1 )
		{
			stopwords(word,t_count,t_positive,t_negative);
		}
	}
	void lowercase(char word[])
	{
		for(int i=0;word[i]!='\0';i++)
		{
			if(word[i]>=65 && word[i]<=90)
			{
			word[i]=word[i]+32;
			}
		}
	//	cout<< word <<endl;
	}

void stopwords(char word[],int &t_count, int &t_positive, int &t_negative)
	{
		int flag=0;
		int loc=0;
		char stopwords[500]={'\0'};
			ifstream infile;
			infile.open("stopwords.txt",ios::in);
			while(true)
			{
			
							infile>> stopwords;				
							if(infile.eof())
							{break;}
							flag=0;
							for(int i=0; word[i]!= '\0' && stopwords[i]!='\0';i++)
							{
								if(stopwords[i]!=word[i])
								{
									flag=0;
									break;
								}
								else
								{
									flag=1;
								} 
							}
							if(flag==1)
							{
								
								break;
									
							}	
			}
			cout<< word <<endl;
			dictionary(word,t_count,t_positive,t_negative);
}

	void dictionary(char word[],int &t_count, int &t_positive, int &t_negative)
	{
		char dicword[500]={'\0'};
		int x=0;
		int y=0;
		int z=0;
		int flag=0;

		ifstream infile;
			infile.open("dictionary.txt",ios::in);
			while(!infile.eof())
			{
				infile>>dicword >>x >> y>>z;
				//cout<< dicword<<"   " << x<<"   "  << y <<"    "<< z <<endl;
				for(int i=0; word[i]!= '\0' && dicword[i]!='\0';i++)
							{
								if(dicword[i]!=word[i])
								{
									flag=0;
									break;
								}
								else
								{
									flag=1;
								} 
							}
							if(flag==1)
							{
								

								t_count=t_count+x;
								t_positive=t_positive+y;
								t_negative=t_negative+z;
								break;
							}	
								
				}
			cout<< word <<"   "<<t_count<<"    "<<  t_positive  <<"   "<< t_negative <<endl;
		
}
		
