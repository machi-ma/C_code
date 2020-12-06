#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//#define MAX 1000//���ͨѶ¼�洢��Ŀ
#define MAX_NAME 20//������󳤶�
#define MAX_AGE  5//������󳤶�
#define MAX_SEX  5//�Ա���󳤶�
#define MAX_TELE 12//��绰���볤��
#define MAX_ADDR 30//����ַ����
#define CAPACITY_SZ 5//��ʼͨѶ¼��С
enum Input//ͨѶ¼����ѡ��
{
	EXITCONTACT,//0
	ADDCONTACT,//1
	DELCONTACT,
	SEARCHCONTACT,
	MODIFYCONTACT,
	PRINTCONTACT,
	SORTCONTACT,
	SAVECONTACT
};//ö��0~6�����˳���ɾ��Ĵ�ӡ����
 typedef struct PerInfo//������Ϣ�Ľṹ��
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PerInfo;
struct Contact//ͨѶ¼�ṹ��
{
	int size;//�Ѿ����˶��ٸ�
	int capacity;//ͨѶ¼�ܴ�С
	PerInfo* date;//������������
};

//��������

//�˵�����
void menu();

//��ʼ��ͨѶ¼����
void InitContact(struct Contact* ps);

//����ͨѶ¼�˵ĺ���
void AddContact(struct Contact *ps);

//ɾ��ͨѶ¼�˵ĺ���
void DelContact( struct Contact* ps);

//���Ҹ�����Ϣ����
void SearchContact(const struct Contact* ps);

//�޸ĸ�����Ϣ����
void ModifyContact(struct Contact* ps);

//��ӡͨѶ¼����
void PrintContact(const struct Contact* ps);

//�ͷŶ�̬�ڴ溯��
void FreeContact(struct Contact *ps);

//����ͨѶ¼���ļ��к���
void SaveContact(struct Contact* ps);

//�ж�ͨѶ¼�����Ƿ���
void CheckCapacity(struct Contact* ps);