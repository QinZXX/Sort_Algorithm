#pragma once
#ifndef _SORT_H
#define _SORT_H

#include<iostream>
using namespace std;
void SelectionSort(int *a, const size_t& n);//ѡ������
void InsertionSort(int *a, const size_t& n);//��������
void BubbleSort(int *a,const size_t &n);//ð������
void stdBubbleSort(int *a, const size_t &n);//ð������2
void ShellSort(int *a, size_t &n);//ϣ������

void merge(int*a, int left, int min, int right);
void MergeSort(int *a, size_t n);//(�ǵݹ�ʽ)�鲢����

int partition(int* a, int left, int right);//�������� :�ź�����Ԫ��λ��   ��������Ԫ��λ��
void quickSort(int *a, int left, int right);//�ݹ�(if left=right,return)
void qSort(int *a, size_t n);//��װ
//���ʣ�1��ʱ�临�Ӷȣ�O(nlogn)  2���ռ临�Ӷȣ�O(logn)  3�����ȶ�����  4��ԭ������
int partition2(int* a, int left, int right);//��ʽ2��˫��ɨ��

void CountingSort(int *a, size_t n);//��������
void betterCountingSort(int *a, size_t n);//�Ż���������ͳ������Ĵ�С=max-min�Ĳ�ֵ+1
void stableCountingSort(int *a, size_t n);//�ȶ���������

#endif 
