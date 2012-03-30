#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    freopen("infile.in","r",stdin);
    int lines=0,words=0,chars=0,wordCandidate=0,firstCharAtLine=0,wordsInLine=0;
    string line;
    char buff[1<<20];
    while(gets(buff))
    {
        line=buff;
        lines++;
        int i=0;int lastSpace=1;
        while(i<line.size())
        {
            if(line[i]==' ' && wordCandidate==0)
            {
                //words++;
                if(firstCharAtLine)
                    wordCandidate=1;
                chars++;
                //lastSpace=1;
            }
            else
            {
                if(wordCandidate && (line[i]!='\n' || line[i]!=' ' ) )
                {
                    words++;
                    wordsInLine++;
                    wordCandidate=0;
                }
                chars++;
                if(line[i]!='\n' && line[i]!=' ')
                    firstCharAtLine++;
                //lastSpace=0;

            }
            i++;
        }
        //if(lastSpace)//if file starts with a space or empty line i.e only contains '\n'
        if(wordsInLine==0)
            words++;//increase word count at each line but only when word count for that line is zero upto \n
        wordsInLine=0;
    }
    chars+=lines;
    cout<<lines<<" "<<words<<" "<<chars;
}
