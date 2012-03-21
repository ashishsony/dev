#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    freopen("infile.in","r",stdin);
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
                            //cout<<"\nword++ for:"<<(int)line[i+1];
                            if((int)line[i+1]!=9)//dont count as word if  next char to ' ' is a TAB char. 
                            words++;
                        }
                break;
            }
            i++;
            chars++;// this wasnt giving correct chars as i was not being initialized to 0 at each loop iteration.
        }
        if(line[0]!=' ' && line.size()>1)//this takes care of a single word in a line... or the first word in a multi word line.
            words++;
        lines++;
        //chars+=line.size();
        //cout<<"line.size():"<<line.size()<<endl;
        //cout<<"words in this line:"<<words<<endl;
    }
    chars+=lines;
    cout<<lines<<" "<<words<<" "<<chars<<endl;

}
