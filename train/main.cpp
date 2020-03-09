#include <iostream>

using namespace std;

int main()
{
    int in[10],out[10];
    int train=0,most=0;
    FILE *input;
    FILE *output;
    input=fopen("INPUT.TXT","r");
    output=fopen("OUTPUT.TXT","w");
    for(int i=0;i<10;i++)
    {
        fscanf(input,"%d %d",out+i,in+i);
        train-=(out[i]-in[i]);
        if(train>most)
        {
            most=train;
        }
    }
    fprintf(output,"%d",most);
    fclose(input);
    fclose(output);
}
