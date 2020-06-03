#pragma once
#ifndef SORT_H
#define SORT_H

#include<iostream>
using namespace std;
void Choose(int *a, const size_t& n);//ѡ������
void Insert(int *a, const size_t& n);//��������
void Bubble(int *a,const size_t &n);//ð������
void objBubble(int *a, const size_t &n);//��׼ð������
void betterBubble(int *a, size_t &n);//�Ż�ð������
void Shell(int *a, size_t &n);//ϣ������

int * Merge(int *arr, int left, int right);//�鲢����
//1��ʱ�临�Ӷȣ�O(nlogn)  2���ռ临�Ӷȣ�O(n)  3���ȶ�����  4����ԭ������
void merge(int *arr, int left, int mid, int right);

void Merge2(int *a, size_t n);//�ǵݹ�ʽ�鲢����

int* quickSort(int* arr, int left, int right);//��������
int partition(int* arr, int left, int right);
//���ʣ�1��ʱ�临�Ӷȣ�O(nlogn)  2���ռ临�Ӷȣ�O(logn)  3�����ȶ�����  4��ԭ������

void Count(int *a, size_t n);//��������
void betterCount(int *a, size_t n);//�Ż���������ͳ������Ĵ�С=max-min�Ĳ�ֵ+1
void stableCount(int *a, size_t n);//�ȶ���������

int qinkuai(int *arr, int left, int right);

#endif // !CHOOSE_H
