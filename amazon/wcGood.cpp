#include<iostream>
#include<fstream>
using namespace std;
int main()
{
string filepath;
cin>>filepath;
//cout<<"filepath:"<<filepath;
    freopen(filepath.c_str(),"r",stdin);
    char buff[2<<20];
    string line;
    int words=0,chars=0,lines=0;
    while(gets(buff))
    {
        line=buff;
        int i=0;
        while(i<line.size())
        {
            switch(line[i])
            {
                case ' ':
                    if(i+1<line.size())
                        if(line[i+1]!=' ')
                        {
				if((int)line[i+1]!=9 && (int)line[i+1]!=13)//dont count as word if  next char to ' ' is a TAB char. or carriage return
				{ 
					//cout<<"\nword++ for:"<<(int)line[i+1]<<",";
					words++;
				}	
			}
                break;
            }
            i++;
            chars++;// this wasnt giving correct chars as i was not being initialized to 0 at each loop iteration.
        }
	if(line[0]!=' ' && line.size()>1)//this takes care of a single word in a line... or the first word in a multi word line.
	{
		//cout<<"\nword++ for222222:"<<(int)line[0];
		words++;
	}
        lines++;
        //chars+=line.size();
        //cout<<"line.size():"<<line.size()<<endl;
        //cout<<"words in this line:"<<words<<endl;
    }
//cout<<endl;
    chars+=lines;
    cout<<lines<<" "<<words<<" "<<chars<<endl;

}
