#include<stdio.h>
#include<string.h>
void main()
{
	FILE*input,*optab,*outputfile,*symtabfile;
	input=fopen("input.txt","r");
	optab=fopen("optab.txt","r");
	outputfile=fopen("output.txt","w");
	symtabfile=fopen("symtab.txt","w");
	int lc,sa;
	char label[20],instruction[20],operand[20];
	fscanf(input,"%s %s %s",label,instruction,operand);
	if(strcmp(instruction,"START")==0)
	{
		sa=strtol(operand,NULL,16);
		fprintf(outputfile,"%X\t%s\t%s\t%s\n",sa,label,instruction,operand);
	}
	else
	{
		sa=0;}
		lc=sa;
		fscanf(input,"%s %s %s",label,instruction,operand);
		while(strcmp(instruction,"END")!=0)
		{
			fprintf(outputfile,"%X\t%s\t%s\t%s\n",lc,label,instruction,operand);
			if(strcmp(label,"-")!=0){
			fprintf(symtabfile,"%s\t%X\n",label,lc);}
		
		if(strcmp(instruction,"WORD")==0)
		{
			lc+=3;
		}
		else if(strcmp(instruction,"RESW")==0)
		{
			lc=lc+(3*(strtol(operand,NULL,10)));
		}
		else if(strcmp(instruction,"RESB")==0)
		{
			lc=lc+strtol(operand,NULL,10);
		}
		else if(strcmp(instruction,"BYTE")==0)
		{
			if(operand[0]=='X')
				lc=lc+strlen(operand)-3;
		}
		else
		
			lc+=3;
		
	fscanf(input,"%s %s %s",label,instruction,operand);
	}
	fprintf(outputfile,"%X\t%s\t%s\t%s\n",lc,label,instruction,operand);
	fclose(input);
	fclose(optab);
	fclose(outputfile);
	fclose(symtabfile);
}
