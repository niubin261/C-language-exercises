#include <stdio.h>//clear函数delete函数都是直接奔溃，想了许久，关键是*str1指向的是常量字符串常量，不能改动任何值改动的办法是使用数组，有时间以后再改
#include <cstdlib>//
int StrCmp(char*, char*);
char* StrCpy(char*);
int StrLenght(char*);
bool StrEmpty(char*);
void ClearStr(char*);
char* ConnectStr(char*,char*);
int SubStr(char*,char* );
char* StrInsert(char*, int, char*);
void StrDelete(char*, int);
void DestroyStr(char*);
int main()
{
	char*str1="boy";
	
	char*str2="bad";
	printf("%d", StrLenght(str1));
	char*str3;
	str3=StrCpy(str1);
	printf("%s", str3);
	free(str3);
	printf("%d", StrCmp(str1, str2));
	//StrDelete(str1, 1);
	ConnectStr(str1, str2);
	char*str4=StrInsert(str1, 1, str2);
	printf("%s", str4);
	char*str5 = ConnectStr(str1, str2);
	free(str4);

	free(str5);
	ClearStr(str1);
	printf("%s", str1);
}
int StrLenght(char*str)
{
	if (str == NULL)
	{
		
		return 0;

	}
	int i = 0;
	while (str[i]!='\0')
	{
		i++;
	}
	return i;
}//比如“boy”输出的长度就是3，呵呵，不傻
int StrCmp(char*str1, char*str2)
{
	int i = 0;
	while (str1[i] != '\0'&&str1[i] == str2[i])
	{
		i++;
	}
	return str1[i] - str2[i];
}
char* StrCpy(char*str)
{
	if (str == NULL)
	{
		return NULL;
	}
	int i = 0;
	int size;
	size = StrLenght(str);
	char*tmp = (char*)malloc(sizeof(char)*(size + 1));
	while (str[i]!='\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return tmp;
}
bool StrEmpty(char*str)
{
	if (str == NULL)
	{
		return false;
	}
	if (str[0] == '\0')
	{
		return true;
	}else
	{
		return false;
	}
}
void ClearStr(char*str)
{
	int i = 0;
	while (str[i]!='\0')
	{
		str[i] = '\0';
		i++;
	}
}
char* ConnectStr(char*str1, char*str2)//不在考虑那字符串为NULL，不然太麻烦了，主要是自己太菜了，哈哈哈............
{
	int len1 = StrLenght(str1);
	char*str = StrInsert(str1, len1, str2);
	return  str;
}
/*下面都不考虑字符串为null的情况了，呵呵呵呵*/
//int SubStr(char*str1, char*str2)
//{
//	int i = 0;
//	int j = 0;
//	
//}
char*StrInsert(char*str1, int local, char*str2)//最简单的方法就是新开一个空间之后将数据搬移进去，简单快速，不装逼
{
	int len1 = StrLenght(str1);
	int len2 = StrLenght(str2);
	char*str = (char*)malloc(sizeof(char)*(len1 + len2 + 1));
	int i;
	int j;
	
	for (i = 0; i < local; i++)
	{
		str[i] = str1[i];
	}
	for (j = 0; j < len2; j++)
	{
		str[i + j] = str2[j];
	}
	for (; i < len1; i++)
	{
		str[local + len2+i-1] = str1[i];
	}
	str[len1 + len2] = '\0';
	return str;
}
void DestroyStr(char*str)
{
	free(str);
}
void StrDelete(char*str, int local)
{
	int len = StrLenght(str);
	if (local>len || local<0)
	{
		return;
	}
	int i = local;
	while (str[i] != '\0')
	{
		str[i-1] = str[i];
		i++;



	}
	str[i - 1] = str[i];
}















#include <stdio.h>
#include <cstdlib>
int StrCmp(char*, char*);
char* StrCpy(char*);
int StrLenght(char*);
bool StrEmpty(char*);
void ClearStr(char*);
char* ConnectStr(char*,char*);
int SubStr(char*,char* );
char* StrInsert(char*, int, char*);
void StrDelete(char*, int);
void DestroyStr(char*);
int main()
{
	char*str1="boy";
	char*str2="bad";
	printf("%d", StrLenght(str1));
	char*str3;
	str3=StrCpy(str1);
	printf("%s", str3);
	free(str3);
	printf("%d", StrCmp(str1, str2));
	//StrDelete(str1, 1);
	ConnectStr(str1, str2);
	char*str4=StrInsert(str1, 1, str2);
	printf("%s", str4);
	char*str5 = ConnectStr(str1, str2);
	free(str4);

	free(str5);
	ClearStr(str1);
	printf("%s", str1);
}
int StrLenght(char*str)
{
	if (str == NULL)
	{
		
		return 0;

	}
	int i = 0;
	while (str[i]!='\0')
	{
		i++;
	}
	return i;
}//比如“boy”输出的长度就是3，呵呵，不傻
int StrCmp(char*str1, char*str2)
{
	int i = 0;
	while (str1[i] != '\0'&&str1[i] == str2[i])
	{
		i++;
	}
	return str1[i] - str2[i];
}
char* StrCpy(char*str)
{
	if (str == NULL)
	{
		return NULL;
	}
	int i = 0;
	int size;
	size = StrLenght(str);
	char*tmp = (char*)malloc(sizeof(char)*(size + 1));
	while (str[i]!='\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return tmp;
}
bool StrEmpty(char*str)
{
	if (str == NULL)
	{
		return false;
	}
	if (str[0] == '\0')
	{
		return true;
	}else
	{
		return false;
	}
}
void ClearStr(char*str)
{
	int i = 0;
	while (str[i]!='\0')
	{
		str[i] = '\0';
		i++;
	}
}
char* ConnectStr(char*str1, char*str2)//不在考虑那字符串为NULL，不然太麻烦了，主要是自己太菜了，哈哈哈............
{
	int len1 = StrLenght(str1);
	char*str = StrInsert(str1, len1, str2);
	return  str;
}
/*下面都不考虑字符串为null的情况了，呵呵呵呵*/
//int SubStr(char*str1, char*str2)
//{
//	int i = 0;
//	int j = 0;
//	
//}
int SubStr(char*str1,char*str2){//如果匹配失败会返回-1
    int i=0;
    int j=0;
    int pos;
    while(str1[i]!='\0'&&str2[j]!='\0'){
        if(str1[i]==str2[j]){
            i++;
            j++;
        } else{
            i++;
            pos=i;
        }
    }
    if(str2[j]=='\0'){
        return i-j;
    }else{
        return -1;
    }
}
char*StrInsert(char*str1, int local, char*str2)//最简单的方法就是新开一个空间之后将数据搬移进去，简单快速，不装逼
{
	int len1 = StrLenght(str1);
	int len2 = StrLenght(str2);
	char*str = (char*)malloc(sizeof(char)*(len1 + len2 + 1));
	int i;
	int j;
	
	for (i = 0; i < local; i++)
	{
		str[i] = str1[i];
	}
	for (j = 0; j < len2; j++)
	{
		str[i + j] = str2[j];
	}
	for (; i < len1; i++)
	{
		str[local + len2+i-1] = str1[i];
	}
	str[len1 + len2] = '\0';
	return str;
}
void DestroyStr(char*str)
{
	free(str);
}
void StrDelete(char*str, int local)
{
	int len = StrLenght(str);
	if (local>len || local<0)
	{
		return;
	}
	int i = local;
	while (str[i] != '\0')
	{
		str[i-1] = str[i];
		i++;



	}
	str[i - 1] = str[i];
}
