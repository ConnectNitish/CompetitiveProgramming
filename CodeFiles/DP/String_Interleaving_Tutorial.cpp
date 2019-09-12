#include<stdio.h>
#include<cstring>
#define MAX 1000
using namespace std;



char s1[MAX];
char s2[MAX];
char s3[MAX];

bool getInterleaving(char * s1,char * s2,char * s3,int s1_ptr,int s2_ptr,int s3_ptr)
{
	// all the three strings are consumed 
	if(s1[s1_ptr]=='\0' && s2[s2_ptr]=='\0' && s3[s3_ptr]=='\0')
		return true;

	// ensures s1 and s2 are consumed but s3 is not yet consumed 
	// because it shows that s3 is not interleaving of s1 and s2 
	if(s1[s1_ptr]=='\0' && s2[s2_ptr]=='\0')
		return false;

	// ensures s1 and s2 is not consumed but s3 is consumed 
	// it shows becase some component of s1 and s2 are already present 
	// shows s3 is not interleaving of s1 and s2
	if(s3[s3_ptr]=='\0')
		return false;

	char s1_char = s1[s1_ptr];
	char s2_char = s2[s2_ptr];
	char s3_char = s3[s3_ptr];

	bool first = false;
	bool second = false;

	// if the s1 char is matches with s3 char 
	if(s1_char == s3_char)
		// matching from the next charcter of s1 with that of s3  
		// exisiting s2 as same 
		first = getInterleaving(s1,s2,s3,s1_ptr+1,s2_ptr,s3_ptr+1);

	// this condition will be executable 
	// irrespective of above fails or passes 
	// shows if the current character of s3 matches with current character
	// of s1 then also we will verify wrt s2 for the same character
	// because at a time we are considering only one charcter 
	// match of s3 with either s1 or s2   
	if(s2_char == s3_char)
		// matching from the next character of s2 with that of s3 
		// exsiting s1 as same  
		second = getInterleaving(s1,s2,s3,s1_ptr,s2_ptr+1,s3_ptr+1);

	// if either matches 
	// then result is true
	return (first || second);
}

void invoke_recusrive_solution()
{
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);

	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	int len_s3 = strlen(s3);

	if(len_s1+len_s2==len_s3)
		printf("%d",getInterleaving(s1,s2,s3,0,0,0));
	else 
		printf("0");
}


int dp_memoisation[MAX][MAX];
bool getInterleavingTopDown(char * s1,char * s2,char * s3,int s1_ptr,int s2_ptr,int s3_ptr)
{
	char s1_char = s1[s1_ptr];
	char s2_char = s2[s2_ptr];
	char s3_char = s3[s3_ptr];

	if(s1_char=='\0' && s2_char=='\0' && s3_char=='\0')
		return true;
	
	if(s1_char=='\0' && s2_char=='\0')
		return false;

	if(s3_char=='\0')
		return false;
	
	if(dp_memoisation[s1_ptr][s2_ptr]!=-1) 
		return dp_memoisation[s1_ptr][s2_ptr];

	bool match_from_s1 = false;
	bool match_from_s2 = false;

	if(s1_char==s3_char)
		match_from_s1 = getInterleavingTopDown(s1,s2,s3,s1_ptr+1,s2_ptr,s3_ptr+1);

	if(s2_char==s3_char)
		match_from_s2 = getInterleavingTopDown(s1,s2,s3,s1_ptr,s2_ptr+1,s3_ptr+1);

	return (dp_memoisation[s1_ptr][s2_ptr] = (match_from_s1 || match_from_s2));

}

void invoke_top_down_solution()
{
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);

	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	int len_s3 = strlen(s3);

	for(int i=0;i<=len_s1;i++)
		for(int j=0;j<=len_s2;j++)
			dp_memoisation[i][j] = -1;

	if(len_s1+len_s2==len_s3)
		printf("%d",getInterleavingTopDown(s1,s2,s3,0,0,0));
	else 
		printf("0");
}


bool dp_bottom_up[MAX][MAX];
bool get_interleaving_bootom_up(char * s1,char * s2,char * s3,int len_s1,int len_s2,int len_s3)
{
	// Initialisation in Bottom Up Manner 
	for(int i=0;i<=len_s1;i++)
		for(int j=0;j<=len_s2;j++)
			dp_bottom_up[i][j] = false;

	for(int i=0;i<=len_s1;i++)
	{
		for(int j=0;j<=len_s2;j++)
		{
			if(i==0 && j==0)
				dp_bottom_up[i][j] = true;
			else if(i==0 || j==0)
			{
				if(j==0)
				{
					if(s1[i-1] == s3[(i+j)-1])
						// store the result which is previous got 
						// by not keeping s1[i-1] in s1 i.e. s1[0...i-2] and s2[0...j]
						dp_bottom_up[i][j] = dp_bottom_up[i-1][j];
				}
				else if(i==0)
				{
					if(s2[j-1] == s3[(i+j)-1])
						// store the result which is previous got 
						// by not keeping s2[j-1] in s2 i.e. s1[0...i] and s2[0...j-2]
						dp_bottom_up[i][j] = dp_bottom_up[i][j-1];
				}
			}
			else
			{
				if(s1[i-1]==s3[(i+j)-1])
				{
					dp_bottom_up[i][j] = dp_bottom_up[i-1][j];
				}

				if(s2[j-1]==s3[(i+j)-1])
				{
					dp_bottom_up[i][j] = (dp_bottom_up[i][j] || dp_bottom_up[i][j-1]);
				}
			}
		}
	}

	return dp_bottom_up[len_s1][len_s2];
}

void invoke_bottom_up_solution()
{
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);

	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	int len_s3 = strlen(s3);

	if(len_s1+len_s2==len_s3)
		printf("%d",get_interleaving_bootom_up(s1,s2,s3,len_s1,len_s2,len_s3));
	else 
		printf("0");
}



int main()
{
	// invoke_top_down_solution();
	// invoke_recusrive_solution();
	invoke_bottom_up_solution();
	return 0;
}