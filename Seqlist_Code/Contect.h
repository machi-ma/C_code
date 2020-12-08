#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//#define MAX 1000//最大通讯录存储数目
#define MAX_NAME 20//名字最大长度
#define MAX_AGE  5//年龄最大长度
#define MAX_SEX  5//性别最大长度
#define MAX_TELE 12//最长电话号码长度
#define MAX_ADDR 30//最大地址长度
#define CAPACITY_SZ 5//初始通讯录大小
enum Input//通讯录功能选择
{
	EXITCONTACT,//0
	ADDCONTACT,//1
	DELCONTACT,
	SEARCHCONTACT,
	MODIFYCONTACT,
	PRINTCONTACT,
	SORTCONTACT,
	SAVECONTACT
};//枚举0~6代表退出增删查改打印排序
 typedef struct PerInfo//个人信息的结构体
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PerInfo;
struct Contact//通讯录结构体
{
	int size;//已经存了多少个
	int capacity;//通讯录总大小
	PerInfo* date;//定义柔性数组
};

//函数声明

//菜单函数
void menu();

//初始化通讯录函数
void InitContact(struct Contact* ps);

//增加通讯录人的函数
void AddContact(struct Contact *ps);

//删除通讯录人的函数
void DelContact( struct Contact* ps);

//查找个人信息函数
void SearchContact(const struct Contact* ps);

//修改个人信息函数
void ModifyContact(struct Contact* ps);

//打印通讯录函数
void PrintContact(const struct Contact* ps);

//释放动态内存函数
void FreeContact(struct Contact *ps);

//保存通讯录到文件中函数
void SaveContact(struct Contact* ps);

//判断通讯录容量是否够用
void CheckCapacity(struct Contact* ps);